#include "game.hpp"

Game::Game(QObject* parent) : QObject(parent) {
}

void Game::addPlayer(Player* player) {
    if (m_playerData.contains(player->name())) {
        emit playerAdded(player->name(), false);
        return;
    }
    m_playerData[player->name()] = player;
    emit playerAdded(player->name(), true);
}

void Game::addMarket(Market* market) {
    if (m_marketData.contains(market->mic())) {
        emit marketAdded(market->mic(), false);
        return;
    }
    m_marketData[market->mic()] = market;
    emit marketAdded(market->mic(), true);
}
