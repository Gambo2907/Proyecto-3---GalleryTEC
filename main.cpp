#include <QApplication>
#include "mainwindow.h"
#include "mongocxx/instance.hpp"
#include "mongodbHandler.h"

int main(int argc, char *argv[])
{
    //Database
    mongocxx::instance instance;
    MongodbHandler mainHandler;

    //App
    QApplication a(argc, argv);
    MainWindow w;
    w.setHandler(&mainHandler);
    w.show();
    return a.exec();
}