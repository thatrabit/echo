#ifndef ECHO_ECHO_HPP
#define ECHO_ECHO_HPP

#include <QtCore/QtCore>
#include "agent.hpp"

class Echo : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString agentId READ agentId WRITE updateAgentId NOTIFY agentIdUpdated);
public:
    explicit Echo(QObject* parent = nullptr);
    ~Echo();
    QString agentId() const;
    void updateAgentId(const QString& agentId);
public slots:
    void onOrderReceived(QString symbol, qint64 quantity);
    void onAgentActivated(bool isActive);
signals:
    void agentIdUpdated();
private:
    Agent* agent;
private slots:
};

#endif
