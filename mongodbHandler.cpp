#include "mongodbHandler.h"

MongodbHandler::MongodbHandler() :
    uri("mongodb://localhost:27017"),
    client(uri),
    db(client["GalleryTEC"])
    {}

bool MongodbHandler::addUserToDb(const string username, const string password) {
    mongocxx::collection userColl = db["UserMetadata"];
    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::document::value doc_to_add = builder
            << "username" << username
            << "password" << password
            << bsoncxx::builder::stream::finalize;

    userColl.insert_one(doc_to_add.view());
    return true;
}

bool MongodbHandler::findElementFromUserColl(const string field, const string value) {
    mongocxx::collection userColl = db["UserMetadata"];
    bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result =
            userColl.find_one(document{} << field << value << finalize);
    if(maybe_result) {
        return true;
    }
    return false;
}

