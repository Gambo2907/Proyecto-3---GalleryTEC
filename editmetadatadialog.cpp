#include "editmetadatadialog.h"
#include "ui_editmetadatadialog.h"

EditMetadataDialog::EditMetadataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMetadataDialog)
{
    ui->setupUi(this);
}

EditMetadataDialog::~EditMetadataDialog()
{
    delete ui;
}

void EditMetadataDialog::showContent() {
    vector<string> vector = mainHandler->getGalleryImages(username,galleryname);
    ui->label_2->setText(QString::fromStdString(username));
    ui->label_3->setText(QString::fromStdString(galleryname));
    ui->label_4->setText(QString::fromStdString(imageName));
}

void EditMetadataDialog::setHandler(MongodbHandler *handler) {
    mainHandler = handler;
}

void EditMetadataDialog::setLength(int length) {
    this->length = length;
    this->length_aux = 0;
}

void EditMetadataDialog::setImagesVector(std::vector<string> images) {
    this->images = images;
}

void EditMetadataDialog::setUserName(string username) {
    this->username = username;
}

void EditMetadataDialog::setImagename(string imageName) {
    this->imageName = imageName;
}

void EditMetadataDialog::setGalleryName(string galleryname) {
    this->galleryname = galleryname;
}
void EditMetadataDialog::on_pushButton_clicked()
{
    string Author = ui->lineEdit->text().toStdString();
    string Year = ui->lineEdit_2->text().toStdString();
    string Size = ui->lineEdit_3->text().toStdString();
    string Description = ui->lineEdit_4->text().toStdString();

    mainHandler->setImageMetadata(imageName,galleryname,"Author",Author,username);
    mainHandler->setImageMetadata(imageName,galleryname,"Year",Year,username);
    mainHandler->setImageMetadata(imageName,galleryname,"Size",Size,username);
    mainHandler->setImageMetadata(imageName,galleryname,"Description",Description,username);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}

void EditMetadataDialog::on_pushButton_2_clicked()
{
    hide();
    parentWidget()->show();
}
