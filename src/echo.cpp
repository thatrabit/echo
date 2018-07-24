#include "echo.h"

Echo::Echo(QObject* parent)
    : QObject(parent) {
}

void Echo::addPlayer(const QString& name) {
    if (m_playerData.contains(name)) {
        emit playerAdded(name, false);
        return;
    }
    m_playerData[name] = new Player(name);
    emit playerAdded(name, true);
}
