//
// Created by Victor on 16.04.2018.
//

#ifndef MYLS_USERCHOISE_H
#define MYLS_USERCHOISE_H

#include <map>
#include <string>
class UserChoise {

private:

    const std::string sortByName = "sortByName";
    const std::string sortBySize = "sortBySize";
    const std::string sortByLastModifyTime ="sortByLastModifyTime";
    const std::string unsorted = "unsorted";
    const std::string sortByExtension = "sortByExtension";

    bool directoriesFirst;
    bool reverceSortingOrder;
public:
    bool isDirectoriesFirst() const;

    void setDirectoriesFirst(bool directoriesFirst);

    bool isReverceSortingOrder() const;

    void setReverceSortingOrder(bool reverceSortingOrder);

    const std::map<std::string, bool> &getChoises() const;

    void setChoises(const std::map<std::string, bool> &choises);

private:

    std::map<std::string, bool> choises;
public:
    const std::string &getSortByName() const;

    const std::string &getSortBySize() const;

    const std::string &getSortByLastModifyTime() const;

    const std::string &getUnsorted() const;

    const std::string &getSortByExtension() const;

    UserChoise();


};


#endif //MYLS_USERCHOISE_H