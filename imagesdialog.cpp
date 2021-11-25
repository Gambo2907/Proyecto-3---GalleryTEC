#include "imagesdialog.h"
#include "ui_imagesdialog.h"
#include <QFileDialog>

ImagesDialog::ImagesDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ImagesDialog),
        imageOperations()
{
    ui->setupUi(this);
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
    //abrir el directorio para obtener la ruta de alguna imagen png
    QPixmap image;
    QImage *objetoImagen;
    std::string directory = "/home/juanda/CLionProjects/Proyecto-3-GalleryTEC/imgs";
    const QString rutaImagen = QFileDialog::getOpenFileName(this,tr("Select Image"), QString::fromStdString(directory) ,"Images (*.png)");
    objetoImagen = new QImage();
    objetoImagen->load(rutaImagen);
    image= QPixmap::fromImage(*objetoImagen);

    QList<int> bytesArray = imageOperations->convertImgToBytesArray(image);
    imageOperations->convertBytesArrayToImg(bytesArray);
    QList<QList<int>> dividedArray = imageOperations->divideListArray(bytesArray);
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