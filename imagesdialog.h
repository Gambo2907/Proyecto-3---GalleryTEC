#ifndef IMAGESDIALOG_H
#define IMAGESDIALOG_H

#include <QDialog>
#include "visualizerdialog.h"
#include "imageOperations.h"

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

    void on_pushButton_IAdd_clicked();

private:
    ImageOperations *imageOperations;
    VisualizerDialog *visualizerWindow;
    Ui::ImagesDialog *ui;
};

#endif // IMAGESDIALOG_H
