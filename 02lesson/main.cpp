// Qt5
#include <qapplication.h>
#include <qpushbutton.h>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QPushButton button("Quit");
    QObject::connect(&button, &QPushButton::clicked, /*&QApplication::quit*/[](bool){
        qDebug() << "You clicked me!";
    });
    button.show();
    return a.exec();
}
