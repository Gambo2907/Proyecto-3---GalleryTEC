#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_register_clicked()
{
    hide();
    registerWindow = new RegisterDialog(this);
    registerWindow->show();
}

void MainWindow::on_pushButton_signIn_clicked()
{
    hide();
    galleriesWindow = new GalleriesDialog(this);
    galleriesWindow->show();
}
