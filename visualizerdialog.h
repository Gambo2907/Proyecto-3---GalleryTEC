#ifndef VISUALIZERDIALOG_H
#define VISUALIZERDIALOG_H

#include <QDialog>

namespace Ui {
class VisualizerDialog;
}

class VisualizerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VisualizerDialog(QWidget *parent = nullptr);
    ~VisualizerDialog();

private slots:
    void on_pushButton_list_clicked();

private:
    Ui::VisualizerDialog *ui;
};

#endif // VISUALIZERDIALOG_H
