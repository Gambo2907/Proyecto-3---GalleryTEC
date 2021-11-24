#ifndef IMAGESDIALOG_H
#define IMAGESDIALOG_H

#include <QDialog>
#include "visualizerdialog.h"

namespace Ui {
class ImagesDialog;
}

class ImagesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImagesDialog(QWidget *parent = nullptr);
    ~ImagesDialog();

private slots:

    void on_pushButton_Iback_clicked();

    void on_pushButton_IVisualizer_clicked();

private:
    VisualizerDialog *visualizerWindow;
    Ui::ImagesDialog *ui;
};

#endif // IMAGESDIALOG_H
