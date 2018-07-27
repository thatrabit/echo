#include "echo.hpp"

Echo::Echo(QObject* parent) : QObject(parent) {
    agent = new Agent;
    agent->setIsActive(true);
    agent->start();
    connect(agent, SIGNAL(idUpdated()), this, SIGNAL(agentIdUpdated()));
}

Echo::~Echo() {
    agent->stop();
}

QString Echo::agentId() const {
    return agent->id();
}

void Echo::updateAgentId(const QString& id) {
    if (id == agent->id())
        return;
    agent->updateId(id);
}
