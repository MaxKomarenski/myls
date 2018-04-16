//
// Created by Victor on 16.04.2018.
//

#include "UserChoise.h"

UserChoise::UserChoise() {
    choises[sortByName] = true;
    choises[sortBySize] = false;
    choises[sortByExtension] = false;
    choises[sortByLastModifyTime] = false;
    choises[unsorted] = false;

    directoriesFirst = false;
    reverceSortingOrder = false;

}

const std::string &UserChoise::getSortByName() const {
    return sortByName;
}

const std::string &UserChoise::getSortBySize() const {
    return sortBySize;
}

const std::string &UserChoise::getSortByLastModifyTime() const {
    return sortByLastModifyTime;
}

const std::string &UserChoise::getUnsorted() const {
    return unsorted;
}

const std::string &UserChoise::getSortByExtension() const {
    return sortByExtension;
}

bool UserChoise::isDirectoriesFirst() const {
    return directoriesFirst;
}

void UserChoise::setDirectoriesFirst(bool directoriesFirst) {
    UserChoise::directoriesFirst = directoriesFirst;
}

bool UserChoise::isReverceSortingOrder() const {
    return reverceSortingOrder;
}

void UserChoise::setReverceSortingOrder(bool reverceSortingOrder) {
    UserChoise::reverceSortingOrder = reverceSortingOrder;
}

const std::map<std::string, bool> &UserChoise::getChoises() const {
    return choises;
}

void UserChoise::setChoises(const std::map<std::string, bool> &choises) {
    UserChoise::choises = choises;
}
