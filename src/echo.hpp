#ifndef ECHO_ECHO_HPP
#define ECHO_ECHO_HPP

#include <QtCore/QtCore>

class Echo : public QObject {
    Q_OBJECT
public:
    explicit Echo(QObject* parent = nullptr);
public slots:
signals:
private:
private slots:
};

#endif
