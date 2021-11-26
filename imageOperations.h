/**
 * @file imageOperations.h
 * @version 1.0
 * @date 24-11-21
 * @author Juan Daniel Rodríguez
 * @brief funciones principales para las operaciones con imágenes.
 */

#ifndef PROYECTO_3_GALLERYTEC_IMAGEOPERATIONS_H
#define PROYECTO_3_GALLERYTEC_IMAGEOPERATIONS_H
#include <QWidget>
/**
 * @brief The ImageOperations class permite las funciones principales de las
 * imágenes de cada galería.
 */
class ImageOperations {
public:
    /**
     * @brief ImagenID Constructor de la clase ImagenID.
     */
    ImageOperations();
    /**
     * @brief genera una lista que convierte la imagen en bytes.
     * @param image imagen
     * @return bytesArray.
     */
    QList<int> convertImgToBytesArray(QPixmap image);
    /**
     * @brief convierte un arreglo de bytes en imagen.
     * @param bytesArray arreglo con los bytes de la imagen.
     */
    QPixmap convertBytesArrayToImg(QList<int> bytesArray);
    QList<QList<int>> divideListArray(QList<int> bytesArray);
    QList<int> calculateParity(QList<QList<int>> bytesTriplet);
    void storageInRAID(QList<QList<int>> bytesTriplet, QList<int> parity);

private:

};


#endif //PROYECTO_3_GALLERYTEC_IMAGEOPERATIONS_H
