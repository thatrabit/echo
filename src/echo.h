#ifndef ECHO_ECHO_H
#define ECHO_ECHO_H

#include "global.h"
#include "player.h"

class ECHO_SHARED_EXPORT Echo : public QObject {
    Q_OBJECT
public:
    explicit Echo(QObject* parent = nullptr);
    bool addPlayer(const QString& name);
public slots:
private slots:
signals:
private:
    QList<Player*> m_playerList;
};

#endif
