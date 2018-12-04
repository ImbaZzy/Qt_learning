#include <QObject>

//reader.h

#include <QDebug>

class Reader:public QObject
{
    Q_OBJECT
public:
    Reader(){}

    void receiveNewspaper(const QString & name)
    {
        qDebug()<<"Receives Newspaper:"<<name;
    }
};

