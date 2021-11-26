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
#include "visualizerdialog.h"
#include "imageOperations.h"
#include "mongodbHandler.h"

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

    void setHandler(MongodbHandler *handler);
    void setUserName(string username);
    void setGalleryName(string galleryname);
    void showContent();
    void setLength(int length);
    void setImagesVector(std::vector<string> images);

private slots:
    /**
     * @brief on_pushButton_list_clicked Valida los eventos del botón list.
     */
    void on_pushButton_list_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_next_clicked();

private:
    std::vector<string> images;
    int length;
    int length_aux;
    string username;
    string galleryname;
    MongodbHandler *mainHandler;
    /**
     * @brief ui Instancia de la intefaz grafica.
     */
    Ui::VisualizerDialog *ui;
};

#endif // VISUALIZERDIALOG_H
