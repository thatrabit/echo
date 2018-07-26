#include "amount.hpp"

Amount::Amount(QObject* parent)
    : QObject(parent)
    , m_value(0) {
}

Amount::Amount(const qint64& value, QObject* parent)
    : QObject(parent)
    , m_value(value) {
}

qint64 Amount::value() const {
    return m_value;
}

void Amount::updateValue(const qint64& value) {
    m_value = value;
    emit valueUpdated(m_value);
}
