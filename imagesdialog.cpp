#include "imagesdialog.h"
#include "ui_imagesdialog.h"

ImagesDialog::ImagesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImagesDialog)
{
    ui->setupUi(this);
}

ImagesDialog::~ImagesDialog()
{
    delete ui;
}
