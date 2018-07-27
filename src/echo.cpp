#include "echo.hpp"

Echo::Echo(QObject* parent) : QObject(parent) {
    agent = new Agent;
    agent->setIsActive(true);
    agent->start();
    connect(agent, SIGNAL(idUpdated()), this, SIGNAL(agentIdUpdated()));
    connect(agent, SIGNAL(orderReceived(QString, qint64)), this, SLOT(onOrderReceived(QString, qint64)));
    connect(agent, SIGNAL(activated(bool)), this, SLOT(onAgentActivated(bool)));
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

void Echo::onOrderReceived(QString symbol, qint64 quantity) {
}

void Echo::onAgentActivated(bool isActive) {
}
