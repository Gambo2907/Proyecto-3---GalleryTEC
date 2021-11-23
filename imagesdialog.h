#ifndef IMAGESDIALOG_H
#define IMAGESDIALOG_H

#include <QDialog>

namespace Ui {
class ImagesDialog;
}

class ImagesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImagesDialog(QWidget *parent = nullptr);
    ~ImagesDialog();

private:
    Ui::ImagesDialog *ui;
};

#endif // IMAGESDIALOG_H
