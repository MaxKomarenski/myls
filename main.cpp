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
    SortAlgorithms algorithms(userChoise);
    Sorter sorter(algorithms, userChoise);

    for(auto dir:dirs) {
        std::vector<std::string> files = fileRolver.getFiles(dir);
        std::cout<<dir<<"\n";
        files = sorter.sort(files);
        Printer printer(userChoise);
        printer.print_results(files);
    }


    return 0;

}


