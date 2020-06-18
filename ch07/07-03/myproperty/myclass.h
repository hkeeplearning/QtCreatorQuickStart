#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName
               READ getUserName
               WRITE setUserName
               NOTIFY userNameChanged)

public:
    explicit MyClass(QObject *parent = nullptr);
    QString getUserName() const
    {
        return m_userName;
    }
    void setUserName(QString userName)
    {
        m_userName = userName;
        emit userNameChanged(userName);
    }

signals:
    void userNameChanged(QString);

public slots:

private:
    QString m_userName;
};

#endif // MYCLASS_H
