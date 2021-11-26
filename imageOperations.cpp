#include "imageOperations.h"
#include <QBuffer>
#include "qdebug.h"
#include "QFile"

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
    //qDebug() << bytesArray;
    //qDebug() << ba;
    return bytesArray;
}

QPixmap ImageOperations::convertBytesArrayToImg(QList<int> bytesArray) {
    QByteArray byteArrayNuevo;
    QDataStream stream(&byteArrayNuevo,QIODevice::WriteOnly);
    for(auto x : bytesArray){
        stream << x;
    }

    //byte array a pixmap invertigar
    QPixmap pixmap;
    QBuffer buffer(&byteArrayNuevo);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");

    qDebug() << pixmap;
    return pixmap;

//    QPixmap mPixmap;
//    mPixmap.loadFromData(byteArrayNuevo,"PNG");
//    qDebug() << mPixmap;
//    return mPixmap;
}

QList<QList<int>> ImageOperations::divideListArray(QList<int> bytesArray) {
    QList<QList<int>> result;
    QList<int> p1,p2,p3;
    int arrayLarge = bytesArray.size();
    int p1Elements = arrayLarge/3;
    int p2Elements = (arrayLarge-p1Elements)/2;
    int p3Elements = arrayLarge-p1Elements-p2Elements;
    int count = 0;
    while (p1Elements > 0 || p2Elements > 0 || p3Elements != 0){
        if (p1Elements >  0){
            p1.append(bytesArray[count]);
            p1Elements --;
            count++;
        }else if(p2Elements > 0)
        {
            p2.append(bytesArray[count]);
            p2Elements--;
            count++;
        }
        else
        {
            p3.append(bytesArray[count]);
            p3Elements--;
            count++;
        }
    }
    result.append(p1);
    result.append(p2);
    result.append(p3);
    return result;
}

//QList<int> ImageOperations::calculateParity(QList<QList<int>> bytesTriplet) {
//    int length = bytesTriplet[0].size();
//    for (int i = 0; i < 3; ++i) {
//        if (bytesTriplet[i].size()){
//
//        }
//    }
//}

void ImageOperations::storageInRAID(QList<QList<int>> bytesTriplet, QList<int> parity) { //QPixmap
QImage RAID1 =  convertBytesArrayToImg(bytesTriplet[0]).toImage().convertToFormat(QImage::Format_ARGB32);
QImage RAID2 = convertBytesArrayToImg(bytesTriplet[1]).toImage().convertToFormat(QImage::Format_ARGB32);
QImage RAID3 = convertBytesArrayToImg(bytesTriplet[2]).toImage().convertToFormat(QImage::Format_ARGB32);
QImage RAID4 = convertBytesArrayToImg(parity).toImage().convertToFormat(QImage::Format_ARGB32);

}

