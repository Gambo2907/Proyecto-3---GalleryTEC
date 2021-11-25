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
#include <mongocxx/client_session.hpp>
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
using namespace mongocxx;
using namespace bsoncxx::builder::basic;
using namespace bsoncxx::builder::stream;
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

    bool addGallery(const string galleryName, const string username);
    vector<string> getUserGalleries(const string username);
    bool deleteGallery(const string username, const string galleryName); //no funciona
    bool addImage(const string username,const string galleryName,const string imageName);
    bool deleteImage(const string galleryName, const string imgName, const string username);
    vector<string> getGalleryImages(const string username, const string galleryName);
    bool setImageMetadata(const string Name, const string gallery, const string field,const string newValue, const string username);
    vector<string> getImageMetadata(const string Name, const string gallery, const string username);

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
