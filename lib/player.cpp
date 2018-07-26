#include "player.hpp"

Player::Player(QObject* parent) : QObject(parent) {
    m_pnl.updateValue(0);
}

Player::Player(const QString& name, QObject* parent) : QObject(parent), m_name(name) {
    m_pnl.updateValue(0);
}

QString Player::name() const {
    return m_name;
}

qint64 Player::pnl() const {
    return m_pnl.value();
}

void Player::updateName(const QString& name) {
    if (name == m_name)
        return;
    m_name = name;
    emit nameUpdated();
}

void Player::updatePnl(const qint64& pnl) {
    if (pnl == m_pnl.value())
        return;
    m_pnl.updateValue(pnl);
    emit pnlUpdated(m_pnl.value());
}
