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
            << "galleries" << bsoncxx::builder::stream::open_array
            << close_array
            << bsoncxx::builder::stream::finalize;

    userColl.insert_one(doc_to_add.view());
    return true;
}

bool MongodbHandler::findElementFromUserColl(const string field, const string value) {
    mongocxx::collection userColl = db["UserMetadata"];
    bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result =
            userColl.find_one(make_document(kvp(field, value)));
    if(maybe_result) {
        return true;
    }
    return false;
}

vector<string> MongodbHandler::getUserGalleries(const string username) {
    vector<string> galleriesVector;
    mongocxx::collection userColl = db["UserMetadata"];

    auto cursor = userColl.find({});
    for(auto&& doc : cursor){
        bsoncxx::document::element userGalleries = doc["username"];
        string dbUsernameString = (string) userGalleries.get_utf8().value;
        if (dbUsernameString == username){
            userGalleries = doc["galleries"];
            if(userGalleries && userGalleries.type() == bsoncxx::type::k_array){
                bsoncxx::array::view galleries{userGalleries.get_array().value};
                for (bsoncxx::array::element subdocument : galleries){
                    string galleryName = (string) subdocument.get_utf8().value;
                    galleriesVector.push_back(galleryName);
                }
            }
        }
    }
    return galleriesVector;
}

bool MongodbHandler::addGallery(const string galleryName, const string username) {
    mongocxx::collection userColl = db["UserMetadata"];
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value update_statement = builder
            << "$push" << bsoncxx::builder::stream::open_document
            << "galleries" << bsoncxx::builder::stream::open_document
            << "$each" << bsoncxx::builder::stream::open_array
            << galleryName
            << bsoncxx::builder::stream::close_array
            << bsoncxx::builder::stream::close_document
            << bsoncxx::builder::stream::close_document
            << bsoncxx::builder::stream::finalize;
    userColl.update_one(bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("username", username)), update_statement.view());

    return true;
}
//bool MongodbHandler::deleteGallery(const string username, const string galleryName) {
//    mongocxx::collection userColl = db["UserMetadata"];
//    auto cursor = userColl.find({});
//    for(auto&& doc : cursor){
//        int count = 0;
//        bsoncxx::document::element userGalleries = doc["username"];
//        string dbUsernameString = (string) userGalleries.get_utf8().value;
//        if (dbUsernameString == username){
//            userGalleries = doc["galleries"];
//            if(userGalleries && userGalleries.type() == bsoncxx::type::k_array){
//                bsoncxx::array::view galleries{userGalleries.get_array().value};
//                for (bsoncxx::array::element subdocument : galleries){
//                    string name = (string) subdocument.get_utf8().value;
//                    if(name == galleryName){
//                        userColl.delete_one(make_document(kvp("galleries",galleries[count])));
//                        return true;
//                    }
//                    count++;
//                }
//            }
//        }
//    }
//    return false;
//}

bool MongodbHandler::addImage(const string username, const string galleryName, const string imageName) {
    mongocxx::collection imgColl = db["ImgMetadata"];
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value update_statement = builder
            << "username" << username
            << "gallery" << galleryName
            << "Name" << imageName
            << "Author" << " "
            << "Year" << " "
            << "Size" << " "
            << "Description" << " "
            << finalize;
    imgColl.insert_one(update_statement.view());
    return true;
}

bool MongodbHandler::deleteImage(const string galleryName, const string imgName, const string username) {
    mongocxx::collection imgColl = db["ImgMetadata"];
    imgColl.delete_one(make_document(kvp("username", username), kvp("gallery", galleryName), kvp("Name", imgName)));
    return true;
}

vector<string> MongodbHandler::getGalleryImages(const string username, const string galleryName) {
    vector<string> galleryImagesVector;
    mongocxx::collection imgColl = db["ImgMetadata"];
    auto cursor = imgColl.find({});
    for (auto &&doc: cursor) {
        bsoncxx::document::element galleryImages = doc["username"];
        string dbUsernameString = (string) galleryImages.get_utf8().value;
        if (dbUsernameString == username) {
            galleryImages = doc["gallery"];
            string dbGalleryString = (string) galleryImages.get_utf8().value;
            if (dbGalleryString == galleryName) {
                galleryImages = doc["Name"];
                string imageName = (string) galleryImages.get_utf8().value;
                galleryImagesVector.push_back(imageName);

            }
        }
    }
    return  galleryImagesVector;
}

bool MongodbHandler::setImageMetadata(const string Name, const string gallery, const string field,
                                      const string newValue, const string username) {
    mongocxx::collection imgColl = db["ImgMetadata"];
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value update_statement = builder
            << "$set" << open_document
            << field << newValue
            << close_document
            << finalize;
    imgColl.update_one(make_document(kvp("username", username),kvp("Name", Name),kvp("gallery", gallery)), update_statement.view());
    return true;
}

vector<string> MongodbHandler::getImageMetadata(const string Name, const string gallery, const string username) {
    vector<string> imageMetadataVector;
    mongocxx::collection imgColl = db["ImgMetadata"];
    auto cursor = imgColl.find({});
    for (auto &&doc: cursor) {
        bsoncxx::document::element galeryName = doc["username"];
        string dbUsernameString = (string) galeryName.get_utf8().value;
        if (dbUsernameString == username) {
            galeryName = doc["gallery"];
            string dbGalleryString = (string) galeryName.get_utf8().value;
            if (dbGalleryString == gallery) {
                galeryName = doc["Name"];
                string dbImageString = (string) galeryName.get_utf8().value;
                if (dbImageString == Name){
                    imageMetadataVector.push_back(dbImageString);
                    imageMetadataVector.push_back((string) doc["Author"].get_utf8().value);
                    imageMetadataVector.push_back((string) doc["Year"].get_utf8().value);
                    imageMetadataVector.push_back((string) doc["Size"].get_utf8().value);
                    imageMetadataVector.push_back((string) doc["Description"].get_utf8().value);
                }
            }
        }
    }
    return imageMetadataVector;
}
