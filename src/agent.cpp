#include "agent.hpp"

Agent::Agent(QObject* parent) : AgentSimpleSource(parent) {
}

Agent::~Agent() {
}

void Agent::addOrder_slot(QString symbol, qint64 quantity) {
}

QString Agent::id() const {
    return m_id;
}

void Agent::updateId(QString id) {
    if (id == m_id)
        return;
    m_id = id;
    emit idUpdated();
}

void Agent::start() {
    if (isActive() == false)
        setIsActive(true);
}

void Agent::stop() {
    if(isActive() == true)
        setIsActive(false);
}
