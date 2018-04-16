//
// Created by User on 16.04.2018.
//

#include <algorithm>
#include <iostream>
#include "Sort.h"

long Sort::GetFileSize(std::string filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

void Sort::sort_by_size(std::vector<std::string> &v){
    std::map<std::string, long> m;

    for (auto const& element : v) {
        m[element] = GetFileSize(element);

    }


    std::sort(v.begin(),v.end(), [&m](const std::string& a, const std::string& b){return m[a] > m[b]; });

}
