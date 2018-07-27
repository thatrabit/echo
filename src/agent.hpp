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
    virtual void addOrder_slot(QString symbol, qint64 quantity);
    QString id() const;
    void updateId(QString id);
    void start();
    void stop();
public slots:
signals:
    void idUpdated();
    void orderReceived(QString, qint64);
    void activated(bool);
private:
    QString m_id;
private slots:
};

#endif
