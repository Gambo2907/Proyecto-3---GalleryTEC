#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setHandler(MongodbHandler *handler) {
    mainHandler = handler;
}

void MainWindow::on_pushButton_register_clicked()
{
    hide();
    registerWindow = new RegisterDialog(this);
    registerWindow->show();
}

void MainWindow::on_pushButton_signIn_clicked()
{
    if(mainHandler->findElementFromUserColl("username",ui->lineEdit_username->text().toStdString()) &&
            mainHandler->findElementFromUserColl("password",ui->lineEdit_password->text().toStdString())){
        qDebug() << "Ingresando.....";
        hide();
        galleriesWindow = new GalleriesDialog(this);
        galleriesWindow->show();
    }else{
        qDebug() << "Usuario o constrasegna incorrecta";
    }
}
