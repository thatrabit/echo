#ifndef ECHO_AGENT_HPP
#define ECHO_AGENT_HPP

#include <QtCore/QtCore>
#include "player.hpp"
#include "market.hpp"
#include "order.hpp"

class Agent : public QObject {
    Q_OBJECT
public:
    explicit Agent(QObject* parent = nullptr);
public slots:
signals:
private:
private slots:
};

#endif
