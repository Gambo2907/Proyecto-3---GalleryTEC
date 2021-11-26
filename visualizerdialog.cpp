#include "visualizerdialog.h"
#include "ui_visualizerdialog.h"
#include "QDebug"


VisualizerDialog::VisualizerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VisualizerDialog)
{
    ui->setupUi(this);
}

VisualizerDialog::~VisualizerDialog()
{
    delete ui;
}

void VisualizerDialog::showContent() {
    vector<string> vector = mainHandler->getGalleryImages(username,galleryname);
    ui->label_imageName->setText(QString::fromStdString(vector[0]));
    ui->label_galleryName->setText(QString::fromStdString(galleryname));
}

void VisualizerDialog::setHandler(MongodbHandler *handler) {
    mainHandler = handler;
}

void VisualizerDialog::setLength(int length) {
    this->length = length;
    this->length_aux = 0;
}

void VisualizerDialog::setImagesVector(std::vector<string> images) {
    this->images = images;
}

void VisualizerDialog::setUserName(string username) {
    this->username = username;
}

void VisualizerDialog::setGalleryName(string galleryname) {
    this->galleryname = galleryname;
}

void VisualizerDialog::on_pushButton_list_clicked()
{
    hide();
    parentWidget()->show();
}

void VisualizerDialog::on_pushButton_back_clicked()
{
    if (length_aux >0){
        length_aux--;
        ui->label_imageName->setText(QString::fromStdString(images[length_aux]));

    }else{
        qDebug() << "Se encuentra en la primera imagen";
    }
}

void VisualizerDialog::on_pushButton_next_clicked()
{
    if (length_aux < length){
        length_aux++;
        ui->label_imageName->setText(QString::fromStdString(images[length_aux]));

    }else{
        qDebug() << "Se encuentra en la ultima imagen";
    }
}

void VisualizerDialog::on_pushButton_metadata_clicked()
{
    hide();
    MetadataWindow = new MetadataDialog(this);
    MetadataWindow->setUserName(username);
    MetadataWindow->setGalleryName(galleryname);
    MetadataWindow->setHandler(mainHandler);
    MetadataWindow->setLength(length,length_aux);
    MetadataWindow->setImagesVector(mainHandler->getGalleryImages(username, galleryname));
    MetadataWindow->setImagename(images[length_aux]);
    MetadataWindow->showContent();
    MetadataWindow->show();
}
