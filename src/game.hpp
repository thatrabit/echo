#ifndef ECHO_GAME_HPP
#define ECHO_GAME_HPP

#include "player.hpp"
#include "market.hpp"

class Game : public QObject {
    Q_OBJECT
public:
    explicit Game(QObject* parent = nullptr);
    void addPlayer(Player* player);
    void addMarket(Market* market);
public slots:
signals:
    void playerAdded(QString, bool);
    void marketAdded(QString, bool);
private:
    QHash<QString, Player*> m_playerData;
    QHash<QString, Market*> m_marketData;
private slots:
};

#endif
