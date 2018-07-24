#ifndef ECHO_PLAYER_H
#define ECHO_PLAYER_H

#include "global.h"

class ECHO_SHARED_EXPORT Player : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE updateName NOTIFY nameUpdated)
    Q_PROPERTY(qint64 pnl READ pnl WRITE updatePnl NOTIFY pnlUpdated)
public:
    explicit Player(QObject* parent = nullptr);
    Player(const QString& name, QObject* parent = nullptr);
    QString name() const;
    qint64 pnl() const;
public slots:
    void updateName(const QString& name);
    void updatePnl(const qint64& pnl);
private slots:
signals:
    void nameUpdated();
    void pnlUpdated(qint64);
private:
    QString m_name;
    qint64 m_pnl;
};

#endif
