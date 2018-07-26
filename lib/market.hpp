#ifndef ECHO_MARKET_HPP
#define ECHO_MARKET_HPP

#include "global.hpp"
#include "instrument.hpp"

class ECHO_SHARED_EXPORT Market : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString mic READ mic WRITE updateMic NOTIFY micUpdated)
public:
    explicit Market(QObject* parent = nullptr);
    Market(const QString& mic, QObject* parent = nullptr);
    QString mic() const;
public slots:
    void updateMic(const QString& mic);
    void addInstrument(Instrument* instrument);
signals:
    void micUpdated();
    void instrumentAdded(QString, bool);
private:
    QString m_mic;
    QHash<QString, Instrument*> m_instrumentData;
private slots:
};

#endif
