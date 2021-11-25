/**
 * @file mongodbHandler.h
 * @version 1.0
 * @date 24-11-21
 * @author Juan Daniel Rodríguez
 * @brief funciones principales para el manejo de la base de datos mongodb
 */


#ifndef PROYECTO_3_GALLERYTEC_MONGODBHANDLER_H
#define PROYECTO_3_GALLERYTEC_MONGODBHANDLER_H
#include <cstdint>
#include <iostream>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;


using namespace std;
/**
 * @brief The MongodbHandler class permite el manejo de la base de datos.
 */
class MongodbHandler {
public:
    /**
     * @brief constructor de la clase MongodbHandler.
     */
    MongodbHandler();
    /**
     * @brief Añade un usuario a la base de datos
     * @param username nombre de usuario
     * @param password contraseña
     * @return true
     */
    bool addUserToDb(const string username, const string password);
    /**
     * @brief Encuentra un elemento de la base de datos
     * @param field campo
     * @param value valor
     * @return true
     */
    bool findElementFromUserColl(const string field, const string value);
    //(falta el tipo de dato que retorna) getGalleriesOfAUser(const string username);

private:
    /**
     * @brief instancia de la dirección de la base de datos.
     */
    mongocxx::uri uri;
    /**
     * @brief instancia del cliente.
     */
    mongocxx::client client;
    /**
     * @brief instancia de la base de datos.
     */
    mongocxx::database db;
};
#endif //PROYECTO_3_GALLERYTEC_MONGODBHANDLER_H
