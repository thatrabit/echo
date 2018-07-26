#ifndef ECHO_PLAYER_HPP
#define ECHO_PLAYER_HPP

#include "global.hpp"
#include "amount.hpp"

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
signals:
    void nameUpdated();
    void pnlUpdated(qint64);
private:
    QString m_name;
    Amount m_pnl;
private slots:
};

#endif
