//
// Created by Victor on 21.04.2018.
//

#ifndef MYLS_SORTER_H
#define MYLS_SORTER_H
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

#include "SortAlgorithms.h"
#include "UserChoise.h"
#include <vector>
#include <string>



class Sorter {

private:
    SortAlgorithms algorithms;
    UserChoise userChoice;



public:
    Sorter(const SortAlgorithms &algorithms, const UserChoise &userChoice);
    std::vector<std::string> sort(std::vector<std::string> files);

};


#endif //MYLS_SORTER_H
