//
// Created by User on 25.04.2018.
//

#ifndef MYLS_FILERESOLVER_H
#define MYLS_FILERESOLVER_H
#include <string>
#include <vector>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include "FileResolver.h"
#include "UserChoise.h"

class FileResolver{
private:
    UserChoise userChoise;
    std::vector<std::string> files;

public:
    FileResolver(const UserChoise &userChoise);

    const std::vector<std::string> &getFiles() const;

    void setFiles(const std::vector<std::string> &files);

    std::vector<std::string> getFiles(std::string dir);

};


#endif //MYLS_FILERESOLVER_H
