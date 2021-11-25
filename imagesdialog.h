/**
 * @file imagesdialog.h
 * @version 1.0
 * @date 24-11-21
 * @author Juan Daniel Rodríguez
 * @brief funciones principales para la ventana de las imágenes
 */

#ifndef IMAGESDIALOG_H
#define IMAGESDIALOG_H

#include <QDialog>
#include "visualizerdialog.h"
#include "imageOperations.h"

namespace Ui {
    class ImagesDialog;
}
/**
 * @brief The ImagesDialog class permite desplegar una interfaz que muestra
 * las imágenes que el usuario conectado tiene en la galería anteriormente seleccionada,
 * además de poder agregar, visualizar o eliminarlas.
 */
class ImagesDialog : public QDialog
{
Q_OBJECT

public:
    /**
     * @brief ImagesDialog constructor de la clase ImagesDialog.
     * @param parent Padre.
     */
    explicit ImagesDialog(QWidget *parent = nullptr);
    ~ImagesDialog();

private slots:
    /**
     * @brief on_pushButton_Iback_clicked Valida los eventos del boton back.
     */
    void on_pushButton_Iback_clicked();
    /**
     * @brief on_pushButton_IVisualizer_clicked Valida los eventos del boton visualizer.
     */
    void on_pushButton_IVisualizer_clicked();
    /**
     * @brief on_pushButton_IAdd_clicked Valida los eventos del boton add.
     */
    void on_pushButton_IAdd_clicked();

private:
    /**
     * @brief imageOperations instancia de la clase ImagesOperations.
     */
    ImageOperations *imageOperations;
    /**
     * @brief visualizerWindow instancia de la clase VisualizerDialog.
     */
    VisualizerDialog *visualizerWindow;
    /**
     * @brief ui Instancia de la intefaz grafica.
     */
    Ui::ImagesDialog *ui;
};

#endif // IMAGESDIALOG_H