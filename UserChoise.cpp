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
    detailedDescription = false;
    directoriesFirst = false;
    reverceSortingOrder = false;
    specialFiles = false;
    markedSpecialFiles = false;
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

    std::string option;
    for(int i = 1; i< argc ; i++){
        if(boost::contains(argv[i],"--sort=")) {
            option = argv[i];
            int j = option.find('=');
            for (; j < option.size(); j++) {
                if (option[j] == '=') {
                    continue;
                }
                if (option[j] == 'U') {
                    changeChoise(unsorted);
                }
                else if (option[j] == 'S') {
                    changeChoise(sortBySize);
                }
                else if (option[j] == 't') {
                    changeChoise(sortByLastModifyTime);
                } else if (option[j] == 'X') {
                    changeChoise(sortByExtension);
                } else if (option[j] == 'N') {
                    changeChoise(sortByName);
                }
                else if (option[j] == 'D') {
                    directoriesFirst = true;
                }
                else if (option[j] == 's') {
                    specialFiles = true;
                }

            }
        } else if(std::strcmp(argv[i], "-r") == 0)
            reverceSortingOrder = true;
        else if(std::strcmp(argv[i], "-F") == 0)
            markedSpecialFiles = true;
        else if(std::strcmp(argv[i], "-l") == 0){
            detailedDescription = true;
        }

    }
    return dirs;
}

void UserChoise::changeChoise(std::string choise) {

    for(auto elem:choises){
        choises[elem.first] = false;

    }
    choises[choise] = true;
}

bool UserChoise::isSpecialFiles() const {
    return specialFiles;
}

bool UserChoise::isMarkedSpecialFiles() const {
    return markedSpecialFiles;
}

std::ostream &operator<<(std::ostream &os, const UserChoise &choise) {
    std::stringstream ss;
    os << " choises:\n ";
    for(auto elem:choise.getChoises()) {
        os  << elem.first<<" "<<elem.second<<"\n";
    }
    os << "dirs first "<< choise.directoriesFirst<<"\n";
    os << "reverse sorting order "<<choise.reverceSortingOrder<<"\n";
    os << "special files "<<choise.specialFiles<<"\n";
    os << "marked special files "<<choise.markedSpecialFiles<<"\n";
    return os;
}

bool UserChoise::isDetailedDescription() const {
    return detailedDescription;
}



