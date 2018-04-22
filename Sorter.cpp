//
// Created by Victor on 21.04.2018.
//

#include "Sorter.h"

Sorter::Sorter(const SortAlgorithms &algorithms, const UserChoise &userChoise) : algorithms(algorithms),
                                                                                 userChoice(userChoise) {



}

std::vector<std::string> Sorter::sort(std::vector<std::string> files) {

    std::vector<std::string> sorted_files(files);

    for(auto choice : userChoice.getChoises()){
        if(choice.second){
            std::cout<<"SORTING "<<choice.first<<std::endl;
            CALL_MEMBER_FN(algorithms,algorithms.get_method_by_name(choice.first, userChoice))(sorted_files, userChoice.isReverceSortingOrder());
        }
    }
    if(userChoice.isDirectoriesFirst()){
        algorithms.at_first_show_the_directories(sorted_files,userChoice.isReverceSortingOrder());
    }

    return sorted_files;

}
