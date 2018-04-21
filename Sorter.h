//
// Created by Victor on 21.04.2018.
//

#ifndef MYLS_SORTER_H
#define MYLS_SORTER_H

#include "SortAlgorithms.h"
#include "UserChoise.h"
#include <vector>
#include <string>


class Sorter {

private:
    SortAlgorithms algorithms;
    UserChoise userChoice;

    typedef void (SortAlgorithms::*sort_method_t)(std::vector<std::string>&v, bool type);
    typedef std::map<bool, sort_method_t> ways_of_sorting;
    ways_of_sorting  sorting_ways;


public:
    Sorter(const SortAlgorithms &algorithms, const UserChoise &userChoice);
    std::vector<std::string> sort(std::vector<std::string> files);

};


#endif //MYLS_SORTER_H
