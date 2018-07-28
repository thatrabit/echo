#ifndef ECHO_ECHO_HPP
#define ECHO_ECHO_HPP

#include <QtCore/QtCore>
#include "instrument.hpp"
#include "agent.hpp"

class Echo : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString echoId READ echoId WRITE setEchoId NOTIFY echoIdChanged);
    Q_PROPERTY(QString lastInstrumentSymbol READ lastInstrumentSymbol NOTIFY lastInstrumentSymbolChanged);
public:
    explicit Echo(QObject* parent = nullptr);
    ~Echo();
    QString echoId() const;
    QString lastInstrumentSymbol() const;
    void setEchoId(QString echoId);
    Q_INVOKABLE void addInstrument(QString symbol);
public slots:
    void onOrderReceived(QString symbol, qint64 quantity);
signals:
    void echoIdChanged(QString);
    void lastInstrumentSymbolChanged();
private:
    QString m_echoId;
    QString m_lastInstrumentSymbol;
    Agent* m_agent;
    QHash<QString, Instrument*> m_instrumentHash;
private slots:
};

#endif
