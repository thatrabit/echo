#ifndef ECHO_INSTRUMENT_HPP
#define ECHO_INSTRUMENT_HPP

#include <QtCore/QtCore>

class Instrument : public QObject {
    Q_OBJECT
public:
    explicit Instrument(QObject* parent = nullptr);
    Instrument(const QString& symbol, QObject* parent = nullptr);
    ~Instrument();
    QString symbol() const;
public slots:
signals:
private:
    const QString m_symbol;
private slots:
};

#endif
