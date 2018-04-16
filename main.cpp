#include <iostream>
#include <vector>
#include "boost/filesystem/operations.hpp"

bool find_help(std::vector<std::string> &v){
    for (int i = 0; i < v.size(); i++){
        if(v.at(i) == "-h" || v.at(i) == "--help"){
            std::cerr<<"HOW TO USE\n myls \n";
            return true;
        }
    }

    return false;
}




int main(int argc, char *argv[]) {

    if (argc > 1)
    {
        std::vector<std::string> strs;
        strs.assign(argv + 1, argv + argc);

        if(find_help(strs)){
            return 0;
        }

        boost::filesystem::path path = boost::filesystem::current_path();
        for(boost::filesystem::path  p : boost::filesystem::directory_iterator(path.string())){
            std::cout << p.filename().string() << std::endl;
        }

        return 0;
    }

        return 1;
}