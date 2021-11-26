#include "galleriesdialog.h"
#include "ui_galleriesdialog.h"
#include <QDir>

GalleriesDialog::GalleriesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GalleriesDialog)
{
    ui->setupUi(this);
}

GalleriesDialog::~GalleriesDialog()
{
    delete ui;
}

void GalleriesDialog::setHandler(MongodbHandler *handler) {
    mainHandler = handler;
}

void GalleriesDialog::showContent() {
    ui->listWidget_galleries->clear();
    vector<string> vector = mainHandler->getUserGalleries(username);
    for (int i = 0; i <vector.size() ; ++i) {
        ui->listWidget_galleries->addItem(QString::fromStdString(vector[i]));
    }
}

void GalleriesDialog::on_pushButton_GSelect_clicked()
{
    hide();
    imageWindow = new ImagesDialog(this);
    imageWindow->setHandler(mainHandler);
    const QString& string = ui->listWidget_galleries->currentItem()->text();
    QString galleryQ = string;
    std::string gallery = galleryQ.toStdString();
    imageWindow->setGalleryName(gallery);
    imageWindow->setUserName(username);
    imageWindow->showContent();
    imageWindow->show();
}

void GalleriesDialog::setUserName(string username) {
    this->username = username;
}

void GalleriesDialog::on_pushButton_Gback_clicked()
{
    hide();
    parentWidget()->show();
}

void GalleriesDialog::on_pushButton_GAdd_clicked() //gallery name y user name
{
    string newGallery = ui->lineEdit_newGallery->text().toStdString();
    mainHandler->addGallery(newGallery,username);
    ui->lineEdit_newGallery->clear();
    showContent();
}
