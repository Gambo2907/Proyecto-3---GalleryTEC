#include "visualizerdialog.h"
#include "ui_visualizerdialog.h"

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

void VisualizerDialog::on_pushButton_list_clicked()
{
    hide();
    parentWidget()->show();
}
