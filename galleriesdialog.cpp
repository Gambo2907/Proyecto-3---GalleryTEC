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
