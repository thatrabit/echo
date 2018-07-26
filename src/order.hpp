#ifndef ECHO_ORDER_HPP
#define ECHO_ORDER_HPP

#include <QtCore/QtCore>
#include "amount.hpp"
#include "instrument.hpp"

class Order : public QObject {
    Q_OBJECT
    Q_PROPERTY(qint64 quantity READ quantity WRITE updateQuantity NOTIFY quantityUpdated)
public:
    explicit Order(QObject* parent = nullptr);
    qint64 quantity() const;
public slots:
    void updateQuantity(const qint64& quantity);
signals:
    void quantityUpdated(qint64);
private:
    Amount m_quantity;
private slots:
};

#endif
