#include "imagesdialog.h"
#include "ui_imagesdialog.h"
#include <QFileDialog>
#include "qdebug.h"

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
void ImagesDialog::setHandler(MongodbHandler *handler) {
    mainHandler = handler;
}

void ImagesDialog::setUserName(string username) {
    this->username = username;
}

void ImagesDialog::setGalleryName(string galleryname) {
    this->galleryname = galleryname;
}

void ImagesDialog::showContent() {
    ui->listWidget_images->clear();
    vector<string> vector = mainHandler->getGalleryImages(username,galleryname);
    for (int i = 0; i < vector.size() ; ++i) {
        ui->listWidget_images->addItem(QString::fromStdString(vector[i]));
    }
}

void ImagesDialog::on_pushButton_IVisualizer_clicked()
{
    hide();
    visualizerWindow = new VisualizerDialog(this);
    visualizerWindow->setUserName(username);
    visualizerWindow->setGalleryName(galleryname);
    visualizerWindow->setHandler(mainHandler);
    visualizerWindow->showContent();
    visualizerWindow->setLength(mainHandler->getGalleryImages(username,galleryname).size());
    visualizerWindow->setImagesVector(mainHandler->getGalleryImages(username, galleryname));
    visualizerWindow->show();
}
void ImagesDialog::on_pushButton_Iback_clicked()
{
    hide();
    parentWidget()->show();
}

void ImagesDialog::on_pushButton_IAdd_clicked()
{
    //RAID
    //abrir el directorio para obtener la ruta de alguna imagen png
    QPixmap image;
    QImage *objetoImagen;
    std::string directory = "/home/juanda/CLionProjects/Proyecto-3-GalleryTEC/imgs";

    const QString rutaImagen = QFileDialog::getOpenFileName(this,tr("Select Image"), QString::fromStdString(directory) ,"Images (*.png)");
    objetoImagen = new QImage();
    objetoImagen->load(rutaImagen);
    image= QPixmap::fromImage(*objetoImagen);
    QList<int> intArray = imageOperations->convertImgToBytesArray(image); //representacion entera del bytesarray
    imageOperations->convertBytesArrayToImg(intArray);
    //QList<QList<int>> dividedArray = imageOperations->divideListArray(intArray);
    //imageOperations->storageInRAID(intArray);

    //DATABASE
    string newImage = ui->lineEdit_imageName->text().toStdString();
    mainHandler->addImage(username, galleryname, newImage);
    ui->lineEdit_imageName->clear();
    showContent();
}

void ImagesDialog::on_pushButton_IDelete_clicked()
{
    const QString& string = ui->listWidget_images->currentItem()->text();
    QString imageQ = string;
    std::string image = imageQ.toStdString();
    mainHandler->deleteImage(galleryname,image,username);
    showContent();
}