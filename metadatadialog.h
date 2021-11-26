#ifndef METADATADIALOG_H
#define METADATADIALOG_H

#include <QDialog>
#include "imageOperations.h"
#include "mongodbHandler.h"

namespace Ui {
class MetadataDialog;
}

class MetadataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MetadataDialog(QWidget *parent = nullptr);
    ~MetadataDialog();

    void setHandler(MongodbHandler *handler);
    void setUserName(string username);
    void setGalleryName(string galleryname);
    void showContent();
    void setLength(int length);
    void setImagename(string imageName);
    void setImagesVector(std::vector<string> images);
private:
    std::vector<string> images;
    int length;
    int length_aux;
    string imageName;
    string username;
    string galleryname;
    MongodbHandler *mainHandler;
    Ui::MetadataDialog *ui;
};

#endif // METADATADIALOG_H
