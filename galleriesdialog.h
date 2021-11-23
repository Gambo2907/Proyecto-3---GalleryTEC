#ifndef GALLERIESDIALOG_H
#define GALLERIESDIALOG_H

#include <QDialog>
#include "imagesdialog.h"

namespace Ui {
class GalleriesDialog;
}

class GalleriesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GalleriesDialog(QWidget *parent = nullptr);
    ~GalleriesDialog();

private slots:
    void on_pushButton_GSelect_clicked();

private:
    ImagesDialog *imageWindow;
    Ui::GalleriesDialog *ui;
};

#endif // GALLERIESDIALOG_H
