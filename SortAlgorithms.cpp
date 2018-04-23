//
// Created by Max Komarenski on 16.04.2018.
//

#include <algorithm>
#include <iostream>
#include <ctime>
#include <boost/filesystem/operations.hpp>
#include "SortAlgorithms.h"

long SortAlgorithms::GetFileSize(std::string filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

bool SortAlgorithms::is_dir(std::string path) {
    struct stat buf;
    stat(path.c_str(), &buf);
    return S_ISDIR(buf.st_mode);
}

void SortAlgorithms::sort_by_size(std::vector<std::string> &v, bool type){
    std::map<std::string, long> m;

    for (auto const& element : v) {
        m[element] = GetFileSize(element);

    }


    std::sort(v.begin(),v.end(), [&m](const std::string& a, const std::string& b){return m[a] > m[b]; });

    if(type)
        std::reverse(v.begin(), v.end());

}

void SortAlgorithms::sort_by_last_write_time(std::vector<std::string> &v, bool type){
    std::map<std::string, long> m;

    for(std::string s:v){
        boost::filesystem::path p(s);

        std::time_t t = boost::filesystem::last_write_time(p);
        m[s] = t;

    }

    std::sort(v.begin(),v.end(), [&m](const std::string& a, const std::string& b){return m[a] > m[b]; });

    if(type)
        std::reverse(v.begin(), v.end());
}

void SortAlgorithms::show_special_file(std::vector<std::string> &v, bool type) {
    std::map<std::string, int> m;
    struct stat st;
    for(std::string s:v) {
        stat(s.c_str(), &st);
        if(s.substr(s.find_last_of(".") + 1) == "exe")
            m[s] = 5;
        else if (boost::filesystem::symlink_status(s).type() == boost::filesystem::symlink_file)
            m[s] = 4;
        else if(S_ISFIFO(st.st_mode))
            m[s] = 3;
        else if(S_ISSOCK(st.st_mode))
            m[s] = 2;
        else
            m[s] = 1;
    }
}

void SortAlgorithms::sort_by_extension(std::vector<std::string> &v, bool type) {
    std::map<std::string, std::string> m;
    for(std::string s:v){
        m[s] = s.substr(s.find_last_of(".") + 1);
    }

    std::sort(v.begin(),v.end(), [&m](const std::string& a, const std::string& b){return m[a] > m[b]; });

    if(type)
        std::reverse(v.begin(), v.end());
}

void SortAlgorithms::sort_by_name(std::vector<std::string> &v, bool type) {

    std::sort(v.begin(),v.end());

    if(type)
        std::reverse(v.begin(), v.end());
}

void SortAlgorithms::at_first_show_the_directories(std::vector<std::string> &v, bool type) {
    std::map<std::string, long> m;
    for(std::string s:v){
        if(is_dir(s))
            m[s] = 1;
        else
            m[s] = 0;
    }

    std::sort(v.begin(),v.end(), [&m](const std::string& a, const std::string& b){return m[a] > m[b]; });

    if(type)
        std::reverse(v.begin(), v.end());

}

SortAlgorithms::sortFn SortAlgorithms::get_method_by_name(std::string name) const {
    return functions.at(name);
}

SortAlgorithms::SortAlgorithms(const UserChoise &userChoise) {

    functions[userChoise.getSortByName()] = SortAlgorithms::sort_by_name;
    functions[userChoise.getSortByExtension()] = SortAlgorithms::sort_by_extension;
    functions[userChoise.getSortByLastModifyTime()] = SortAlgorithms::sort_by_last_write_time;
    functions[userChoise.getSortBySize()] = SortAlgorithms::sort_by_size;
    functions[userChoise.getDirectoriesFirstToken()] = SortAlgorithms::at_first_show_the_directories;

}
