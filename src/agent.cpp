#include "agent.hpp"

Agent::Agent(QObject* parent) : AgentSimpleSource(parent), m_id("anon") {
}

Agent::Agent(const QString& id, QObject* parent) : AgentSimpleSource(parent), m_id(id) {
}

Agent::~Agent() {
}

void Agent::addOrder(QString symbol, qint64 quantity) {
    emit orderReceived(symbol, quantity);
}

QString Agent::id() const {
    return m_id;
}
