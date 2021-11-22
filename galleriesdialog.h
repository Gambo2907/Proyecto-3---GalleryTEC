#ifndef GALLERIESDIALOG_H
#define GALLERIESDIALOG_H

#include <QDialog>

namespace Ui {
class GalleriesDialog;
}

class GalleriesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GalleriesDialog(QWidget *parent = nullptr);
    ~GalleriesDialog();

private:
    Ui::GalleriesDialog *ui;
};

#endif // GALLERIESDIALOG_H
