/**
* @file registerdialog.h
* @version 1.0
* @date 24-11-21
* @author Juan Daniel Rodríguez
* @brief funciones principales para la ventana de registro.
*/

#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H
#include <QDialog>
#include "mongodbHandler.h"

namespace Ui {
class RegisterDialog;
}
/**
 * @brief The RegisterDialog class permite desplegar una interfaz que muestra
 * las opciones para poder registrarse en la app.
 */
class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief RegisterDialog constructor de la clase RegisterDialog.
     * @param parent Padre.
     */
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();
    /**
     * @brief Permite registrar al usuario en la base de datos
     * @param handler instancia de la clase MongodbHandler.
     */
    void setHandler(MongodbHandler *handler);

private slots:
    /**
     * @brief on_pushButton_back_clicked Valida los eventos del boton back.
     */
    void on_pushButton_back_clicked();
    /**
     * @brief on_pushButton_register_clicked Valida los eventos del boton register.
     */
    void on_pushButton_register_clicked();

private:
    /**
     * @brief mainHandler Instancia de la clase MongodbHandler
     */
    MongodbHandler *mainHandler;
    /**
     * @brief ui Instancia de la intefaz grafica.
     */
    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
