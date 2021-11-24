#include <QApplication>
#include "mainwindow.h"
#include "mongocxx/instance.hpp"
#include "mongodbHandler.h"

int main(int argc, char *argv[])
{
    //TESTS  DATABASE
    mongocxx::instance instance;
    MongodbHandler mainHandler;
    //mainHandler.addUserToDb("sergio","123456");
    if(mainHandler.findElementFromUserColl("username","tata")){
        std::cout << "El usuario se encuentra"<<endl;
    }else{
        std::cout << "El usuario no se encuentra"<<endl;
    }


    //APP
    QApplication a(argc, argv);
    MainWindow w;
    w.setHandler(&mainHandler);
    w.show();
    return a.exec();
}