#include "galerydialog.h"
#include "ui_galerydialog.h"
#include "QPixmap"

GaleryDialog::GaleryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GaleryDialog)
{
    ui->setupUi(this);
    QPixmap pixImage("/home/juanda/CLionProjects/Proyecto-3-GalleryTEC/imgs/image1.jpg");
    ui->label_galeryImg->setPixmap(pixImage.scaled(491,361,Qt::KeepAspectRatio));
}

GaleryDialog::~GaleryDialog()
{
    delete ui;
}
