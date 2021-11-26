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
    /**
     * @brief Añade una galería a la base de datos
     * @param galleryName nombre de la galería
     * @param username nombre del usuario
     * @return true
     */
    bool addGallery(const string galleryName, const string username);
    /**
     * @brief Obtiene las galerías del usuario
     * @param username nombre de usuario
     * @return galleries vector
     */
    vector<string> getUserGalleries(const string username);
    /**
     * @brief elimina una galería
     * @param username nombre de usuario
     * @param galleryName nombre de la galería
     * @return true
     */
    bool deleteGallery(const string username, const string galleryName); //no funciona
    /**
     * @brief añade una imagen a la galería
     * @param username nombre de usuario
     * @param galleryName nombre de la galería
     * @param imageName nombre de la imagen
     * @return true
     */
    bool addImage(const string username,const string galleryName,const string imageName);
    /**
     * @brief elimina una imagen de una galería
     * @param galleryName nombre de la galería
     * @param imgName nombre de la imagen
     * @param username nombre de usuario
     * @return true
     */
    bool deleteImage(const string galleryName, const string imgName, const string username);
    /**
     * @brief obtiene las imágenes de una galería
     * @param username nombre de usuario
     * @param galleryName nombre de la galería
     * @return galleryImagesVector
     */
    vector<string> getGalleryImages(const string username, const string galleryName);
    /**
     * @brief edita la información de la metadata de una imagen
     * @param Name nombre de la imagen
     * @param gallery nombre de la galería
     * @param field campo
     * @param newValue nuevo valor
     * @param username nombre de usuario
     * @return true
     */
    bool setImageMetadata(const string Name, const string gallery, const string field,const string newValue, const string username);
    /**
     * @brief obtiene la metadata de una imagen
     * @param Name nombre de la imagen
     * @param gallery nombre de la galería
     * @param username nombre de usuario
     * @return imageMetadataVector
     */
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
