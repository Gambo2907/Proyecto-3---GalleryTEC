#include "imagesdialog.h"
#include "ui_imagesdialog.h"
#include <QDir>
ImagesDialog::ImagesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImagesDialog)
{
    ui->setupUi(this);
    QDir dir (":/GitHub/Proyecto-3-GalleryTEC/imgs");
    foreach(QFileInfo var, dir.entryInfoList()){
        if(var.isFile()) {
            ui->listWidget_images->addItem(var.fileName());
        }

    }
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

