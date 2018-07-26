#ifndef ECHO_AMOUNT_HPP
#define ECHO_AMOUNT_HPP

#include "global.hpp"

class ECHO_SHARED_EXPORT Amount : public QObject {
    Q_OBJECT
    Q_PROPERTY(qint64 value READ value WRITE updateValue NOTIFY valueUpdated)
public:
    explicit Amount(QObject* parent = nullptr);
    Amount(const qint64& value, QObject* parent = nullptr);
    qint64 value() const;
public slots:
    void updateValue(const qint64& value);
signals:
    void valueUpdated(qint64);
private:
    qint64 m_value;
private slots:
};

#endif
