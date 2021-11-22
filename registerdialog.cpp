#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "QPixmap"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    QPixmap pixImage("/home/juanda/CLionProjects/Proyecto-3-GalleryTEC/imgs/image1.jpg");
    QPixmap pixFolder("/home/juanda/CLionProjects/Proyecto-3-GalleryTEC/imgs/carpeta1.jpg");
    ui->label_pictures->setPixmap(pixImage.scaled(121,121,Qt::KeepAspectRatio));
    ui->label_folder->setPixmap(pixFolder.scaled(121,121,Qt::KeepAspectRatio));

}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_pushButton_back_clicked()
{
    hide();
    parentWidget()->show();
}
