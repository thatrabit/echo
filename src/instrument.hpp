#ifndef ECHO_INSTRUMENT_HPP
#define ECHO_INSTRUMENT_HPP

#include <QtCore/QtCore>
#include "amount.hpp"

class Instrument : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString symbol READ symbol WRITE updateSymbol NOTIFY symbolUpdated);
public:
    explicit Instrument(QObject* parent = nullptr);
    Instrument(const QString& symbol, QObject* parent = nullptr);
    QString symbol() const;
public slots:
    void updateSymbol(const QString& symbol);
signals:
    void symbolUpdated();
private:
    QString m_symbol;
private slots:
};

#endif
