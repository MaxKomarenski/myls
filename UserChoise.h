//
// Created by Victor on 16.04.2018.
//

#ifndef MYLS_USERCHOISE_H
#define MYLS_USERCHOISE_H

#include <map>
#include <string>
#include <vector>
#include <boost/algorithm/string/predicate.hpp>
#include <ostream>
#include <sstream>
#include <iostream>
#include "boost/filesystem/operations.hpp"

#include <sys/stat.h>

class UserChoise {

private:

    const std::string sortByName = "sortByName";
    const std::string sortBySize = "sortBySize";
    const std::string sortByLastModifyTime ="sortByLastModifyTime";
    const std::string unsorted = "unsorted";
    const std::string sortByExtension = "sortByExtension";
    bool detailedDescription;
    bool directoriesFirst; // Опція згідно якої директорія виводится перщою
    bool reverceSortingOrder; // Опція згідно якої поряд сорутвання інвертується
    bool specialFiles; // спеціальні файли
    bool markedSpecialFiles; // вказує  типи спеціальних файлів

    std::map<std::string, bool> choises;
    void changeChoise(std::string choise);
public:

    std::vector<std::string> parseArgs(int argc, char *argv[]);
    bool isDirectoriesFirst() const;

    void setDirectoriesFirst(bool directoriesFirst);

    bool isReverceSortingOrder() const;

    void setReverceSortingOrder(bool reverceSortingOrder);

    const std::map<std::string, bool> &getChoises() const;

    void setChoises(const std::map<std::string, bool> &choises);

    const std::string &getSortByName() const;

    const std::string &getSortBySize() const;

    const std::string &getSortByLastModifyTime() const;

    const std::string &getUnsorted() const;

    const std::string &getSortByExtension() const;

    bool isSpecialFiles() const;

    bool isMarkedSpecialFiles() const;

    friend std::ostream &operator<<(std::ostream &os, const UserChoise &choise);

    bool isDetailedDescription() const;

    UserChoise();


};


#endif //MYLS_USERCHOISE_H
