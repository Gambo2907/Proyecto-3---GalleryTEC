#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H
#include <QDialog>
#include "mongodbHandler.h"

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();
    void setHandler(MongodbHandler *handler);

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_register_clicked();

private:
    MongodbHandler *mainHandler;
    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
