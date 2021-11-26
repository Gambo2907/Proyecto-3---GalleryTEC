/**
 * @file mainwindow.h
 * @version 1.0
 * @date 24-11-21
 * @author Juan Daniel Rodríguez
 * @brief funciones principales para la ventana principal de la aplicación
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registerdialog.h"
#include "galleriesdialog.h"
#include "mongodbHandler.h"

namespace Ui {
class MainWindow;
}
/**
 * @brief The MainWindow class permite desplegar una interfaz que muestra
 * la ventana principal de la aplicación.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor de la clase MainWindow.
     * @param parent Padre.
     */
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**
     * @brief genera conexión con la base de datos
     * @param handler handler
     */
    void setHandler(MongodbHandler *handler);

private slots:
    /**
     * @brief on_pushButton_register_clicked Valida los eventos del botón register.
     */
    void on_pushButton_register_clicked();
    /**
     * @brief on_pushButton_signIn_clicked Valida los eventos del botón signIn.
     */
    void on_pushButton_signIn_clicked();

private:
    /**
     * @brief mainHandler Instancia de la clase MongodbHandler
     */
    MongodbHandler *mainHandler;
    /**
     * @brief galleriesWindow Instancia de la clase GalleriesDialog
     */
    GalleriesDialog *galleriesWindow;
    /**
     * @brief registerWindow Instancia de la clase RegisterDialog
     */
    RegisterDialog *registerWindow;
    /**
     * @brief ui Instancia de la intefaz grafica.
     */
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
