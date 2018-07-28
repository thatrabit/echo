#ifndef ECHO_AGENT_HPP
#define ECHO_AGENT_HPP

#include <QtCore/QtCore>
#include "rep_agent_merged.h"

class Agent : public AgentSimpleSource {
    Q_OBJECT
public:
    explicit Agent(QObject* parent = nullptr);
    Agent(const QString& id, QObject* parent = nullptr);
    ~Agent();
    virtual void addOrder(QString symbol, qint64 quantity);
    QString id() const;
public slots:
signals:
    void orderReceived(QString, qint64);
private:
    const QString m_id;
private slots:
};

#endif
