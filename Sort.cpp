//
// Created by Max Komarenski on 16.04.2018.
//

#include <algorithm>
#include <iostream>
#include <ctime>
#include <boost/filesystem/operations.hpp>
#include "Sort.h"

long Sort::GetFileSize(std::string filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

void Sort::sort_by_size(std::vector<std::string> &v, bool type){
    std::map<std::string, long> m;

    for (auto const& element : v) {
        m[element] = GetFileSize(element);

    }


    std::sort(v.begin(),v.end(), [&m](const std::string& a, const std::string& b){return m[a] > m[b]; });

}

void Sort::sort_by_last_write_time(std::vector<std::string> &v, bool type){
    for(std::string s:v){
        boost::filesystem::path p(s);

        std::time_t t = boost::filesystem::last_write_time( p ) ;
        std::cout << "On " << t << " the file " << s << " was modified the last time!\n" ;

    }

}

void Sort::show_special_file(std::vector<std::string> &v, bool type) {

}

void Sort::sort_by_extension(std::vector<std::string> &v, bool type) {

}

void Sort::sort_by_name(std::vector<std::string> &v, bool type) {

}

void Sort::at_first_show_the_directories(std::vector<std::string> &v, bool type) {

}
