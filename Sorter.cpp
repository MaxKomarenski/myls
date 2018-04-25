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
            //std::cout<<"SORTING "<<choice.first<<std::endl;
            CALL_MEMBER_FN(algorithms,algorithms.get_method_by_name(choice.first))(sorted_files, userChoice.isReverceSortingOrder());
        }
    }
    if(userChoice.isDirectoriesFirst()){
        CALL_MEMBER_FN(algorithms,algorithms.get_method_by_name(userChoice.getDirectoriesFirstToken()))
                (sorted_files, userChoice.isReverceSortingOrder());

    }

    return sorted_files;

}
