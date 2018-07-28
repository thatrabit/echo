#include "echo.hpp"

Echo::Echo(QObject* parent) : QObject(parent), m_echoId("trader0") {
    m_agent = new Agent(m_echoId, this);
    connect(m_agent, SIGNAL(orderReceived(QString, qint64)), this, SLOT(onOrderReceived(QString, qint64)));
}

Echo::~Echo() {
}

QString Echo::echoId() const {
    return m_echoId;
}

QString Echo::lastInstrumentSymbol() const {
    return m_lastInstrumentSymbol;
}

void Echo::setEchoId(QString echoId) {
    if (echoId == m_echoId)
        return;
    m_echoId = echoId;
    emit echoIdChanged(m_echoId);
}

void Echo::addInstrument(QString symbol) {
    m_instrumentHash[symbol] = new Instrument(symbol, this);
    m_lastInstrumentSymbol = symbol;
    emit lastInstrumentSymbolChanged();
}

void Echo::onOrderReceived(QString symbol, qint64 quantity) {
}
