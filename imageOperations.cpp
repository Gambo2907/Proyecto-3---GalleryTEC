#include "imageOperations.h"
#include <QBuffer>
#include "qdebug.h"

ImageOperations::ImageOperations() {}

QList<int> ImageOperations::convertImgToBytesArray(QPixmap image) {
    QList<int> bytesArray;
    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer,"PNG");
    for(int i = 0; i < ba.size(); i++){
        bytesArray.append(int(ba[i]));
    }
    qDebug()<<bytesArray;
    return bytesArray;
}

void ImageOperations::convertBytesArrayToImg(QList<int> bytesArray) {
    QByteArray byteArrayNuevo;
    QDataStream stream(&byteArrayNuevo,QIODevice::WriteOnly);
    for(auto x : bytesArray){
        stream << x;
    }
}