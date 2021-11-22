#ifndef GALERYDIALOG_H
#define GALERYDIALOG_H

#include <QDialog>

namespace Ui {
class GaleryDialog;
}

class GaleryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GaleryDialog(QWidget *parent = nullptr);
    ~GaleryDialog();

private:
    Ui::GaleryDialog *ui;
};

#endif // GALERYDIALOG_H
