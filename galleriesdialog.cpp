#include "galleriesdialog.h"
#include "ui_galleriesdialog.h"
#include <QDir>
GalleriesDialog::GalleriesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GalleriesDialog)
{

    ui->setupUi(this);
    //QListWidgetItem *item = new QListWidgetItem(QIcon(":rec/imgs/carpeta.png"),"Carpeta");
    //ui->listWidget_galleries->addItem(item);
    QDir dir (":/Proyecto-3-GalleryTEC/imgs");
    foreach(QFileInfo var, dir.drives()){
        ui->listWidget_galleries->addItem(dir.dirName());

    }

}

GalleriesDialog::~GalleriesDialog()
{
    delete ui;
}

void GalleriesDialog::on_pushButton_GSelect_clicked()
{
    hide();
    imageWindow = new ImagesDialog(this);
    imageWindow->show();
}



void GalleriesDialog::on_pushButton_Gback_clicked()
{
    hide();
    parentWidget()->show();
}


//#include "galleriesdialog.h"
//#include "ui_galleriesdialog.h"
//#include <QDir>
//GalleriesDialog::GalleriesDialog(QWidget *parent) :
//        QDialog(parent),
//        ui(new Ui::GalleriesDialog)
//{
//
//    ui->setupUi(this);
//    //QListWidgetItem *item = new QListWidgetItem(QIcon(":rec/imgs/carpeta.png"),"Carpeta");
//    //ui->listWidget_galleries->addItem(item);
//    QDir dir (":/Proyecto-3-GalleryTEC/imgs");
//            foreach(QFileInfo var, dir.drives()){
//            ui->listWidget_galleries->addItem(dir.dirName());
//
//        }
//
//}
//
//GalleriesDialog::~GalleriesDialog()