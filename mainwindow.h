#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registerdialog.h"
#include "galerydialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_signIn_clicked();

private:
    GaleryDialog *galeryWindow;
    RegisterDialog *registerWindow;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
