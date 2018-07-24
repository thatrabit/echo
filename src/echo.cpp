#include "echo.h"

Echo::Echo(QObject* parent)
    : QObject(parent) {
}

bool Echo::addPlayer(const QString& name) {
    m_playerList.append(new Player(name));
    return true;
}
