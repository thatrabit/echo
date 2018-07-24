#include "player.h"

Player::Player(QObject* parent)
    : QObject(parent) {
}

Player::Player(const QString& name, QObject* parent)
    : QObject(parent)
    , m_name(name) {
}

QString Player::name() const {
    return m_name;
}

qint64 Player::pnl() const {
    return m_pnl;
}

void Player::updateName(const QString& name) {
    if (name == m_name)
        return;
    m_name = name;
    emit nameUpdated();
}

void Player::updatePnl(const qint64& pnl) {
    if (pnl == m_pnl)
        return;
    m_pnl = pnl;
    emit pnlUpdated(m_pnl);
}
