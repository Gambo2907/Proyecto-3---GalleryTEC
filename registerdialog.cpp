#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "QPixmap"
#include "qdebug.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    QPixmap pixImage(":/imgs/imgs/image1.jpg");
    QPixmap pixFolder(":/imgs/imgs/carpeta1.jpg");
    ui->label_pictures->setPixmap(pixImage.scaled(121,121,Qt::KeepAspectRatio));
    ui->label_folder->setPixmap(pixFolder.scaled(121,121,Qt::KeepAspectRatio));

}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::setHandler(MongodbHandler *handler) {
    mainHandler = handler;
}

void RegisterDialog::on_pushButton_back_clicked()
{
    hide();
    parentWidget()->show();
}

void RegisterDialog::on_pushButton_register_clicked()
{
    string username = ui->lineEdit_username->text().toStdString();
    string password = ui->lineEdit_password->text().toStdString();
    if(mainHandler->addUserToDb(username,password)){
        qDebug() <<  "Usuario registrado correctamente";
    }else{
        qDebug() <<  "No se puedo registrar el usuario";
    }
    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
}
