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
    //qDebug()<<bytesArray;
    return bytesArray;
}

void ImageOperations::convertBytesArrayToImg(QList<int> bytesArray) {
    QByteArray byteArrayNuevo;
    QDataStream stream(&byteArrayNuevo,QIODevice::WriteOnly);
    for(auto x : bytesArray){
        stream << x;
    }
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
    qDebug() << result[0];
    qDebug() << result[1];
    qDebug() << result[2];
    //qDebug() << result;
    return result;
}

QList<int> ImageOperations::calculateParity(QList<QList<int>> bytesTriplet) {
    int length = bytesTriplet[0].size();
    for (int i = 0; i < 3; ++i) {
    }

}