#ifndef EDITMETADATADIALOG_H
#define EDITMETADATADIALOG_H

#include <QDialog>
#include "mongodbHandler.h"
#include "imageOperations.h"

namespace Ui {
class EditMetadataDialog;
}

class EditMetadataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditMetadataDialog(QWidget *parent = nullptr);
    ~EditMetadataDialog();

    void setHandler(MongodbHandler *handler);
    void setUserName(string username);
    void setGalleryName(string galleryname);
    void showContent();
    void setLength(int length);
    void setImagename(string imageName);
    void setImagesVector(std::vector<string> images);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    std::vector<string> images;
    int length;
    int length_aux;
    string imageName;
    string username;
    string galleryname;
    MongodbHandler *mainHandler;
    Ui::EditMetadataDialog *ui;
};

#endif // EDITMETADATADIALOG_H
