#include "metadatadialog.h"
#include "ui_metadatadialog.h"
#include "vector"

MetadataDialog::MetadataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MetadataDialog)
{
    ui->setupUi(this);
}

void MetadataDialog::showContent() {
    vector<string> metadata;
    vector<string> vector = mainHandler->getGalleryImages(username,galleryname);
    ui->label_9->setText(QString::fromStdString(username));
    ui->label_2->setText(QString::fromStdString(galleryname));
    ui->label_3->setText(QString::fromStdString(imageName));

    metadata = mainHandler->getImageMetadata(imageName,galleryname,username);  //(name,author,year,size,description)

    ui->label_4->setText(QString::fromStdString(metadata[1]));
    ui->label_5->setText(QString::fromStdString(metadata[2]));
    ui->label_6->setText(QString::fromStdString(metadata[3]));
    ui->label_7->setText(QString::fromStdString(metadata[4]));
}

void MetadataDialog::setHandler(MongodbHandler *handler) {
    mainHandler = handler;
}

void MetadataDialog::setLength(int length) {
    this->length = length;
    this->length_aux = 0;
}

void MetadataDialog::setImagesVector(std::vector<string> images) {
    this->images = images;
}

void MetadataDialog::setUserName(string username) {
    this->username = username;
}

void MetadataDialog::setImagename(string imageName) {
    this->imageName = imageName;
}

void MetadataDialog::setGalleryName(string galleryname) {
    this->galleryname = galleryname;
}

MetadataDialog::~MetadataDialog()
{
    delete ui;
}
