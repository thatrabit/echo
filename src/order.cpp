#include "order.hpp"

Order::Order(QObject* parent) : QObject(parent) {
    m_quantity.updateValue(0);
}

qint64 Order::quantity() const {
    return m_quantity.value();
}

void Order::updateQuantity(const qint64& quantity) {
    if (quantity == m_quantity.value())
        return;
    m_quantity.updateValue(quantity);
    emit quantityUpdated(m_quantity.value());
}
