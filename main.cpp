#include <iostream>
#include <vector>
#include <map>
#include <sys/stat.h>
#include "boost/filesystem/operations.hpp"
#include "Sort.h"
#include "UserChoise.h"


bool find_help(std::vector<std::string> &v){
    for (int i = 0; i < v.size(); i++){
        if(v.at(i) == "-h" || v.at(i) == "--help"){
            std::cerr<<"HOW TO USE\n myls \n";
            return true;
        }
    }

    return false;
}

std::vector<std::string> getFiles(std::string file){
    std::vector<std::string> v;
    boost::filesystem::path path =  file;
    for(boost::filesystem::path  p : boost::filesystem::directory_iterator(path.string())){
        v.push_back(p.filename().string());
    }
    return v;
}


int main(int argc, char *argv[]) {

    UserChoise userChoise;
    std::vector<std::string> dirs = userChoise.parseArgs(argc, argv);






    return 0;


}

