//
// Created by User on 25.04.2018.
//


#include "UserChoise.h"
#include "FileResolver.h"


std::vector<std::string> FileResolver::getFiles(std::string dir){

    boost::filesystem::path path =  dir;

    struct stat buf;


    if(userChoise.isRecursive()){
        for(boost::filesystem::path p : boost::filesystem::directory_iterator(path.string())){
            stat(p.filename().c_str(), &buf);
            if(S_ISDIR(buf.st_mode)){
                getFiles(p.filename().string());
            }else{
                files.push_back(dir+"/"+p.filename().string());
            }
        }

    } else {
        for(boost::filesystem::path  p : boost::filesystem::directory_iterator(path.string())){
            files.push_back(dir+"/"+p.filename().string());
        }
    }
    return files;
}


FileResolver::FileResolver(const UserChoise &userChoise) : userChoise(userChoise) {

}
