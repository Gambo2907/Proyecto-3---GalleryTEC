/**
 * @file visualizerdialog.h
 * @version 1.0
 * @date 24-11-21
 * @author Juan Daniel Rodríguez
 * @brief funciones principales para la ventana de observación de imágenes
 */

#ifndef VISUALIZERDIALOG_H
#define VISUALIZERDIALOG_H

#include <QDialog>
#include "imageOperations.h"
#include "mongodbHandler.h"
#include "metadatadialog.h"

namespace Ui {
class VisualizerDialog;
}
/**
 * @brief The VisualizerDialog class permite desplegar una interfaz que muestra
 * la imagen seleccionada.
 */
class VisualizerDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief VisualizerDialog constructor de la clase VisualizerDialog.
     * @param parent
     */
    explicit VisualizerDialog(QWidget *parent = nullptr);
    ~VisualizerDialog();
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
     * @brief obtiene las imágenes
     * @param images imagenes
     */
    void setImagesVector(std::vector<string> images);

private slots:
    /**
     * @brief on_pushButton_list_clicked Valida los eventos del botón list.
     */
    void on_pushButton_list_clicked();
    /**
     * @brief on_pushButton_back_clicked Valida los eventos del botón back.
     */
    void on_pushButton_back_clicked();
    /**
     * @brief on_pushButton_next_clicked Valida los eventos del botón next.
     */
    void on_pushButton_next_clicked();

    void on_pushButton_metadata_clicked();

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
    Ui::VisualizerDialog *ui;

    MetadataDialog *MetadataWindow;
};

#endif // VISUALIZERDIALOG_H
