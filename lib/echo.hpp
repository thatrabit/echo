#ifndef ECHO_ECHO_HPP
#define ECHO_ECHO_HPP

#include "global.hpp"
#include "player.hpp"

class ECHO_SHARED_EXPORT Echo : public QObject {
    Q_OBJECT
public:
    explicit Echo(QObject* parent = nullptr);
    void addPlayer(const QString& name);
public slots:
signals:
    void playerAdded(QString, bool);
private:
    QHash<QString, Player*> m_playerData;
private slots:
};

#endif
