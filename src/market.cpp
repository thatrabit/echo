#include "market.hpp"

Market::Market(QObject* parent) : QObject(parent) {
}

Market::Market(const QString& mic, QObject* parent) : QObject(parent), m_mic(mic) {
}

QString Market::mic() const {
    return m_mic;
}

void Market::updateMic(const QString& mic) {
    if (mic == m_mic)
        return;
    m_mic = mic;
    emit micUpdated();
}

void Market::addInstrument(Instrument* instrument) {
    if (m_instrumentData.contains(instrument->symbol())) {
        emit instrumentAdded(instrument->symbol(), false);
        return;
    }
    m_instrumentData[instrument->symbol()] = instrument;
    emit instrumentAdded(instrument->symbol(), true);
}
