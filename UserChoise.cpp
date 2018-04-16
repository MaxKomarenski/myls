//
// Created by Victor on 16.04.2018.
//

#include <cstring>
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

std::vector<std::string> UserChoise::parseArgs(int argc, char **argv) {
    std::vector<std::string> dirs;

    for(int i = 1; i< argc ; i++){

        if(std::strcmp(argv[i], "--sort=U") == 0)
            changeChoise(unsorted);
        else if(std::strcmp(argv[i], "--sort=S") == 0)
            changeChoise(sortBySize);
        else if(std::strcmp(argv[i], "--sort=t") == 0)
            changeChoise(sortByLastModifyTime);
        else if(std::strcmp(argv[i], "--sort=X") == 0)
            changeChoise(sortByExtension);
        else if(std::strcmp(argv[i], "--sort=N") == 0)
            changeChoise(sortByName);
        else if(std::strcmp(argv[i], "-r") == 0)
            reverceSortingOrder = true;
        else if(std::strcmp(argv[i], "-F") == 0)
            markedSpecialFiles = true;

    }
}

void UserChoise::changeChoise(std::string choise) {

    for(auto elem:choises){
        choises[elem.first] = false;

    }
    choises[choise] = true;
}

