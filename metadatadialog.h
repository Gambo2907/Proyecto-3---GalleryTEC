/**
 * @file metadatadialog.h
 * @version 1.0
 * @date 25-11-21
 * @author Juan Daniel Rodríguez
 * @brief funciones principales para la manipulación de metadata.
 */

#ifndef METADATADIALOG_H
#define METADATADIALOG_H

#include <QDialog>
#include "imageOperations.h"
#include "mongodbHandler.h"
#include "editmetadatadialog.h"

namespace Ui {
class MetadataDialog;
}
/**
 * @brief The MetadataDialog class permite desplegar una interfaz que muestra
 * la metadata asociada a la imagen correspondiente.
 */
class MetadataDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief MetadataDialog constructor de la clase MetadataDialog.
     * @param parent Padre.
     */
    explicit MetadataDialog(QWidget *parent = nullptr);
    ~MetadataDialog();
    /**
    *@brief genera la conexión con la base de datos
    @param handler handler
    */
    void setHandler(MongodbHandler *handler);
    /**
     * @brief obtiene el nombre de usuario
     * @param username nombre de usuario
     */
    void setUserName(string username);
     /**
     * @brief obtiene el nombre de las galerías
     * @param galleryname nombre de la galería
     */
    void setGalleryName(string galleryname);
    /**
     * @brief muestra el contenido en pantalla
     */
    void showContent();
    /**
     * @brief obtiene la cantidad de imágenes que hay en la galería
     * @param length cantidad
     */
    void setLength(int length, int length_aux);
    /**
     * @brief obtiene el nombre de las imágenes
     * @param imageName nombre de la imagen
     */
    void setImagename(string imageName);
    /**
     * @brief obtiene las imágenes
     * @param images imagenes
     */
    void setImagesVector(std::vector<string> images);
private slots:
/**
     * @brief on_pushButton_2_clicked Valida los eventos del botón clicked.
     */
    void on_pushButton_2_clicked();
/**
     * @brief on_pushButton_clicked Valida los eventos del botón clicked.
     */
    void on_pushButton_clicked();
/**
     * @brief on_pushButton_3_clicked Valida los eventos del botón clicked.
     */
    void on_pushButton_3_clicked();

private:
/**
     * @brief imágenes
     */
    std::vector<string> images;
    /**
     * @brief cantidad de imágenes
     */
    int length;
    /**
     * @brief auxiliar
     */
    int length_aux;
    /**
     * @brief nombre de la imagen
     */
    string imageName;
    /**
     * @brief nombre de usuario
     */
    string username;
    /**
     * @brief nombre de la galería
     */
    string galleryname;
    /**
     * @brief mainHandler Instancia de la clase MongodbHandler
     */
    MongodbHandler *mainHandler;
    /**
     * @brief EditMetadataWindow Instancia de la clase EditMetadataDialog
     */
    EditMetadataDialog *EditMetadataWindow;
    /**
     * @brief ui Instancia de la intefaz grafica.
     */
    Ui::MetadataDialog *ui;
};

#endif // METADATADIALOG_H
