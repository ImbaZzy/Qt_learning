#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>
//#include <QHBoxLayout>
#include <QVBoxLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QWidget window;
    window.setWindowTitle("Enter your age");

    QSpinBox *spinbox = new QSpinBox(&window);
    QSlider *slider = new QSlider(Qt::Horizontal,&window);
    spinbox -> setRange(0,130);
    slider -> setRange(0,130);

    QObject::connect(slider,&QSlider::valueChanged,spinbox,&QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;

/*不能直接使用 QObject::connect(spinBox, &QSpinBox::valueChanged, slider, &QSlider::setValue);编译器认为 QSpinBox::valueChanged 是一个 overloaded 的函数。我们看一下 QSpinBox 的文档发现，QSpinBox 的确有两个信号：

    void valueChanged(int)
    void valueChanged(const QString &)


当我们使用 &QSpinBox::valueChanged 取函数指针时，编译器不知道应该取哪一个函数（记住前面我们介绍过的，经过 moc 预处理后，signal 也是一个普通的函数。）的地址，因此报错。
我们就显式指定一个函数。方法就是，我们创建一个函数指针，这个函数指针参数指定为 int：

    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;


然后我们将这个函数指针作为 signal，与 QSlider 的函数连接：

    QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);


这样便避免了编译错误。*/

    QObject::connect(spinbox,spinBoxSignal,slider,&QSlider::setValue);
    spinbox->setValue(35);

//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(spinbox);
//    layout->addWidget(slider);
//    window.setLayout(layout);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(spinbox);
    layout->addWidget(slider);
    window.setLayout(layout);


    window.show();

    return a.exec();
}
