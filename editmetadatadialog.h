/**
 * @file editmetadatadialog.h
 * @version 1.0
 * @date 25-11-21
 * @author Juan Daniel Rodríguez
 * @brief funciones principales para la ventana de edición de metadata.
 */

#ifndef EDITMETADATADIALOG_H
#define EDITMETADATADIALOG_H

#include <QDialog>
#include "mongodbHandler.h"
#include "imageOperations.h"

namespace Ui {
class EditMetadataDialog;
}
/**
 * @brief The EditMetadataDialog class permite desplegar una interfaz que muestra
 * la manera de editar la metadata de la imagen.
 */
class EditMetadataDialog : public QDialog
{
    Q_OBJECT

public:
/**
     * @brief EditMetadataDialog constructor de la clase EditMetadataDialog.
     * @param parent
     */
    explicit EditMetadataDialog(QWidget *parent = nullptr);
    ~EditMetadataDialog();
    /**
     * @brief genera conexión con la base de datos
     * @param handler handler
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
    void setLength(int length);
    /**
     * @brief obtiene el nombre de las imágenes
     * @param imageName imagenes
     */
    void setImagename(string imageName);
    /**
     * @brief obtiene las imágenes
     * @param images imagenes
     */
    void setImagesVector(std::vector<string> images);
private slots:
/**
     * @brief on_pushButton_clicked Valida los eventos del botón clicked.
     */
    void on_pushButton_clicked();
    /**
     * @brief on_pushButton_2_clicked Valida los eventos del botón clicked.
     */
    void on_pushButton_2_clicked();

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
     * @brief ui Instancia de la intefaz grafica.
     */
    Ui::EditMetadataDialog *ui;
};

#endif // EDITMETADATADIALOG_H
