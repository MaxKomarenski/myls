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

std::vector<std::string> getFiles(){
    std::vector<std::string> v;
    boost::filesystem::path path = boost::filesystem::current_path();
    for(boost::filesystem::path  p : boost::filesystem::directory_iterator(path.string())){
        v.push_back(p.filename().string());
    }

    return v;
}


int main(int argc, char *argv[]) {

//    if (argc > 1)
//    {
//        std::vector<std::string> strs;
//        strs.assign(argv + 1, argv + argc);
//
//        if(find_help(strs)){
//            return 0;
//        }
//
//        Sort sort;
//
//        std::vector<std::string> vector = getFiles();
//
//        sort.sort_by_size(vector);
//
//        for (auto const& element : vector) {
//
//            std::cout << element << std::endl;
//        }

//    UserChoise userChoise;
//    userChoise.parseArgs(argc, argv);
//
//
//    std::cout<<userChoise;

    std::vector<std::string> v = getFiles();
    Sort sort;

    //sort.sort_by_last_write_time(v);


        return 0;


}

