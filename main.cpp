#include <QCoreApplication>
#include <QDebug>
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    qDebug() << "Hello World";
    return QApplication::exec();
    /*
    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";
    return QCoreApplication::exec();
     */
}


