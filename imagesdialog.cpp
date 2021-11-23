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

void ImagesDialog::on_pushButton_ISelect_clicked()
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
