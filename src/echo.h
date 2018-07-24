#ifndef ECHO_ECHO_H
#define ECHO_ECHO_H

#include "global.h"
#include "player.h"

class ECHO_SHARED_EXPORT Echo : public QObject {
    Q_OBJECT
public:
    explicit Echo(QObject* parent = nullptr);
    void addPlayer(const QString& name);
public slots:
private slots:
signals:
    void playerAdded(QString, bool);
private:
    QHash<QString, Player*> m_playerData;
};

#endif
