#include "imagesdialog.h"
#include "ui_imagesdialog.h"
#include <QDir>
#include <QFileDialog>
ImagesDialog::ImagesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImagesDialog)
{
    ui->setupUi(this);
    QDir dir (":/GitHub/Proyecto-3-GalleryTEC/imgs");
    foreach(QFileInfo var, dir.entryInfoList()){
        if(var.isFile()) {
            ui->listWidget_images->addItem(var.fileName());
        }

    }
}

ImagesDialog::~ImagesDialog()
{
    delete ui;
}

void ImagesDialog::on_pushButton_IVisualizer_clicked()
{
    hide();
    visualizerWindow = new VisualizerDialog(this);
    visualizerWindow->show();
}
void ImagesDialog::on_pushButton_Iback_clicked()
{
    hide();
    parentWidget()->show();
}

void ImagesDialog::on_pushButton_IAdd_clicked()
{
    QPixmap imagen;
    QImage *objetoImagen;
    const QString rutaImagen = QFileDialog::getOpenFileName(this,tr("Seleccione una imagen"),"/imgs","Images (*.png)");
    objetoImagen = new QImage();
    objetoImagen->load(rutaImagen);
    //imagen= QPixmap::fromImage(*objetoImagen);
}


//#include "imagesdialog.h"
//#include "ui_imagesdialog.h"
//#include <QDir>
//ImagesDialog::ImagesDialog(QWidget *parent) :
//        QDialog(parent),
//        ui(new Ui::ImagesDialog)
//{
//    ui->setupUi(this);
//    QDir dir (":/GitHub/Proyecto-3-GalleryTEC/imgs");
//            foreach(QFileInfo var, dir.entryInfoList()){
//            if(var.isFile()) {
//                ui->listWidget_images->addItem(var.fileName());
//            }
//
//        }
//}
//
//ImagesDialog::~ImagesDialog()

