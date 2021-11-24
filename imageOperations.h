#ifndef PROYECTO_3_GALLERYTEC_IMAGEOPERATIONS_H
#define PROYECTO_3_GALLERYTEC_IMAGEOPERATIONS_H
#include <QWidget>

class ImageOperations {
public:
    ImageOperations();
    QList<int> convertImgToBytesArray(QPixmap image);
    void convertBytesArrayToImg(QList<int> bytesArray);

private:

};


#endif //PROYECTO_3_GALLERYTEC_IMAGEOPERATIONS_H
