#ifndef ECHO_AGENT_HPP
#define ECHO_AGENT_HPP

#include <QtCore/QtCore>
#include "player.hpp"
#include "market.hpp"
#include "order.hpp"

#include "rep_agent_merged.h"

class Agent : public AgentSimpleSource {
    Q_OBJECT
public:
    explicit Agent(QObject* parent = nullptr);
    ~Agent();
    virtual void server_slot(bool clientState);
public slots:
    void timeout_slot();
signals:
private:
    QTimer* stateChangeTimer;
private slots:
};

#endif
