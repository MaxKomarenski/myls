//
// Created by User on 25.04.2018.
//


#include "UserChoise.h"
#include "FileResolver.h"


std::vector<std::string> FileResolver::getFiles(std::string dir){


    boost::filesystem::path path =  dir;
    //std::cout<<"PATH "<<dir<<"\n";

    struct stat buf;
    if(userChoise.isRecursive()){
        for(boost::filesystem::path p : boost::filesystem::directory_iterator(path.string())){
            stat(p.string().c_str(), &buf);
            if(S_ISDIR(buf.st_mode)){
                //std::cout<<p.string()<<"\n";
                getFiles(p.string());
            }else{
               // std::cout<<"ELSE "<< dir<<std::endl;
                files.push_back(dir+"/"+p.filename().string());
            }
        }

    } else {
        for(boost::filesystem::path  p : boost::filesystem::directory_iterator(path.string())){
            files.push_back(dir+"/"+p.filename().string());
        }
    }
    std::vector<std::string> files_copy(files);

    files.clear();
    return files_copy;
}


FileResolver::FileResolver(const UserChoise &userChoise) : userChoise(userChoise) {

}

const std::vector<std::string> &FileResolver::getFiles() const {
    return files;
}

void FileResolver::setFiles(const std::vector<std::string> &files) {
    FileResolver::files = files;
}
