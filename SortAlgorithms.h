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
#include "UserChoise.h"



class SortAlgorithms {

    typedef void (SortAlgorithms::*sortFn)(std::vector<std::string>&v, bool type);
private:
    std::map<std::string,sortFn> functions;
    long GetFileSize(std::string filename);
    bool is_dir(std::string path);
    void sort_by_size(std::vector<std::string> &v, bool type);
    void sort_by_last_write_time(std::vector<std::string> &v, bool type);
    void sort_by_extension(std::vector<std::string> &v, bool type);
    void sort_by_name(std::vector<std::string> &v, bool type);
    void at_first_show_the_directories(std::vector<std::string> &v, bool type);
    void show_special_file(std::vector<std::string> &v, bool type);

public:
    SortAlgorithms(const UserChoise &userChoise);

    sortFn get_method_by_name(std::string name)const;
};




#endif //MYLS_SORT_H
