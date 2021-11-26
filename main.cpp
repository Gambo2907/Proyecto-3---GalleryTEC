#include <QApplication>
#include "mainwindow.h"
#include "mongocxx/instance.hpp"
#include "mongodbHandler.h"

int main(int argc, char *argv[])
{
    //Database
    mongocxx::instance instance;
   MongodbHandler mainHandler;
//   vector<string> vector = mainHandler.getUserGalleries("axel");
//   mainHandler.addGallery("prueba","axel");
//    mainHandler.addImage("axel","prueba","sdfsdsdf");
//    mainHandler.deleteImage("prueba","perro","axel");

//    vector<string> vector = mainHandler.getGalleryImages("axel","prueba");
//    mainHandler.setImageMetadata("perro","prueba","Author","Author","axel");
//    vector<string> vector = mainHandler.getImageMetadata("perro","prueba","axel");  //(name,author,year,size,description)

    //App
    QApplication a(argc, argv);
    MainWindow w;
    w.setHandler(&mainHandler);
    w.show();
    return a.exec();
}