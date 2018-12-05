// Qt5
#include <QObject>

//newspaper.h

class Newspaper:public QObject
{
    Q_OBJECT//必須要加上的宏
public:
    Newspaper(const QString & name)://構造函數，用於初始化Newspaper類
        m_name(name){}

    void send()
    {
        emit newPaper(m_name);//在適當的地方將信息emit出去
    }

signals:
    void newPaper(const QString & name);//signails的函數返回值爲void

private:
    QString m_name;

};
