#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registerdialog.h"
#include "galleriesdialog.h"
#include "mongodbHandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setHandler(MongodbHandler *handler);

private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_signIn_clicked();

private:
    MongodbHandler *mainHandler;
    GalleriesDialog *galleriesWindow;
    RegisterDialog *registerWindow;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
