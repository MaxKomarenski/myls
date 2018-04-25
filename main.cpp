#include <iostream>
#include <vector>
#include <map>
#include <sys/stat.h>
#include "boost/filesystem/operations.hpp"
#include "SortAlgorithms.h"
#include "UserChoise.h"
#include "Printer.h"
#include "Sorter.h"
#include "FileResolver.h"
#include <ctime>


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

    UserChoise userChoise;
    std::vector<std::string> dirs = userChoise.parseArgs(argc, argv);
    FileResolver fileRolver(userChoise);
    std::vector<std::string> files = fileRolver.getFiles(dirs[0]);


    std::cout<<"AFTER SORT\n";

    SortAlgorithms algorithms(userChoise);
    Sorter sorter(algorithms, userChoise);
    files =  sorter.sort(files);

    Printer printer(userChoise);

    printer.print_results(files);






//    struct stat path_stat;
//    for(auto elem : files){
//        std::string path = dirs[0]+"/"+elem;
//        //std::cout<<path<<"\n";
//        stat(path.c_str(), &path_stat);
//
//        if (!S_ISDIR(path_stat.st_mode)) {
//            if(userChoise.isDetailedDescription()){
//                char buffer[32];
//                std::time_t now = path_stat.st_mtime;
//                std::tm * ptm = std::localtime(&now);
//                std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
//                std::cout << elem << " " << path_stat.st_size << " bytes " << " " << buffer << "\n";
//            } else{
//                std::cout<<elem<<"\n";
//            }
//        } else{
//
//
//
//
//
//        }

  //  }




    return 0;


}


