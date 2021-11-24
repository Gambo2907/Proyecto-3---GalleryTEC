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
class MongodbHandler {
public:
    MongodbHandler();
    bool addUserToDb(const string username, const string password);
    bool findElementFromUserColl(const string field, const string value);
    //(falta el tipo de dato que retorna) getGalleriesOfAUser(const string username);

private:
    mongocxx::uri uri;
    mongocxx::client client;
    mongocxx::database db;
};
#endif //PROYECTO_3_GALLERYTEC_MONGODBHANDLER_H
