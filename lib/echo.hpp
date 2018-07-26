#ifndef ECHO_ECHO_HPP
#define ECHO_ECHO_HPP

#include "global.hpp"

class ECHO_SHARED_EXPORT Echo : public QObject {
    Q_OBJECT
public:
    explicit Echo(QObject* parent = nullptr);
public slots:
signals:
private:
private slots:
};

#endif
