#include "agent.hpp"

Agent::Agent(QObject* parent) : AgentSimpleSource(parent) {
    stateChangeTimer = new QTimer(this);
    connect(stateChangeTimer, SIGNAL(timeout()), this, SLOT(timeout_slot()));
    stateChangeTimer->start(2000);
    qDebug() << "source node started";
}

Agent::~Agent() {
    stateChangeTimer->stop();
}

void Agent::server_slot(bool clientState) {
    qDebug() << "replica state: " << clientState;
}

void Agent::timeout_slot() {
    if (currState())
        setCurrState(false);
    else
        setCurrState(true);
    qDebug() << "source state: " << currState();
}
