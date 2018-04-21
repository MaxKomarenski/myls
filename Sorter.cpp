//
// Created by Victor on 21.04.2018.
//

#include "Sorter.h"

Sorter::Sorter(const SortAlgorithms &algorithms, const UserChoise &userChoise) : algorithms(algorithms),
                                                                                 userChoice(userChoise) {

    for(auto choice : userChoise.getChoises()){

        if(choice.second){


        }

    }


    //sorting_ways[userChoise.getSortByName()] = &SortAlgorithms::sort_by_name;



}

std::vector<std::string> Sorter::sort(std::vector<std::string> files) {

    std::vector<std::string> sorted_files(files);











    return sorted_files;

}
