/**
 * @file galleriesdialog.h
 * @version 1.0
 * @date 24-11-21
 * @author Juan Daniel Rodríguez
 * @brief funciones principales para la ventana de las galerias
 */

#ifndef GALLERIESDIALOG_H
#define GALLERIESDIALOG_H

#include <QDialog>
#include "imagesdialog.h"
#include "mongodbHandler.h"

namespace Ui {
class GalleriesDialog;
}
/**
 * @brief The GalleriesDialog class permite desplegar una interfaz que muestra
 * las galerías que el usuario conectado tiene, además de poder agregar o eliminarlas.
 */
class GalleriesDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief GalleriesDialog constructor de la clase GalleriesDialog.
     * @param parent Padre
     */
    explicit GalleriesDialog(QWidget *parent = nullptr);
    ~GalleriesDialog();

    void setHandler(MongodbHandler *handler);
    void setUserName(string username);
    void showContent();

private slots:
    /**
     * @brief on_pushButton_GSelect_clicked Valida los eventos del boton select.
     */
    void on_pushButton_GSelect_clicked();
    /**
     * @brief on_pushButton_Gback_clicked Valida los eventos del boton back.
     */
    void on_pushButton_Gback_clicked();

    void on_pushButton_GAdd_clicked();


private:
    string username;
    MongodbHandler *mainHandler;
    /**
     * @brief imageWindow instancia de la clase ImagesDialog
     */
    ImagesDialog *imageWindow;
    /**
     * @brief ui Instancia de la intefaz grafica.
     */
    Ui::GalleriesDialog *ui;
};

#endif // GALLERIESDIALOG_H
