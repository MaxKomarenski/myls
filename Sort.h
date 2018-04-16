//
// Created by User on 16.04.2018.
//

#ifndef MYLS_SORT_H
#define MYLS_SORT_H


#include <string>
#include <vector>
#include <sys/stat.h>
#include <map>
#include <fstream>



class Sort {
public:
    long GetFileSize(std::string filename);

    void sort_by_size(std::vector<std::string> &v);
};


#endif //MYLS_SORT_H
