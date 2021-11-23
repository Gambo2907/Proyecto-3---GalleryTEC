#include "galleriesdialog.h"
#include "ui_galleriesdialog.h"

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
