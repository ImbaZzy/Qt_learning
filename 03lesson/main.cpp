//main.cpp

#include <QCoreApplication>
#include "newpaper.h"
#include "reader.h"

int main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);

    Newspaper newpaper("newspaper a");
    Reader reader;
    QObject::connect(&newpaper,&Newspaper::newPaper,&reader,&Reader::receiveNewspaper);

    newpaper.send();
    return a.exec();
}
