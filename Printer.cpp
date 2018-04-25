//
// Created by Victor on 23.04.2018.
//

#include "Printer.h"

void Printer::print_results(std::vector<std::string> files) {

    if(userChoice.isDetailedDescription()){
        print_detailed(files);
    } else{
        print_regular(files);
    }
}

void Printer::mark_specal_file(std::string &file) {

    struct stat st;
        stat(file.c_str(), &st);
        if(boost::algorithm::ends_with(file, ".exe")) {
            file.append("*");

        }
        else if (boost::filesystem::symlink_status(file).type() == boost::filesystem::symlink_file)
            file.append("@");
        else if(S_ISFIFO(st.st_mode))
            file.append("|");
        else if(S_ISSOCK(st.st_mode))
            file.append("=");
        else if(!S_ISREG(st.st_mode))
            file.append("?");


}

void Printer::print_detailed(std::vector<std::string> &files) {


    struct stat path_stat;
    if(userChoice.isMarkedSpecialFiles()){
        for (auto elem : files) {
            stat(elem.c_str(), &path_stat);
            char buffer[32];
            std::time_t now = path_stat.st_mtime;
            std::tm *ptm = std::localtime(&now);
            std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
            mark_specal_file(elem);
            std::cout << basename(const_cast<char *>(elem.c_str())) << " " << path_stat.st_size << " bytes " << " "
                      << buffer << "\n";
        }

    } else {
        for (auto elem : files) {
            stat(elem.c_str(), &path_stat);
            char buffer[32];
            std::time_t now = path_stat.st_mtime;
            std::tm *ptm = std::localtime(&now);
            std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
            std::cout << basename(const_cast<char *>(elem.c_str())) << " " << path_stat.st_size << " bytes " << " "
                      << buffer << "\n";
        }
    }


}

void Printer::print_regular(std::vector<std::string> &files) {
    if(userChoice.isMarkedSpecialFiles()){
        for(auto s: files){
            mark_specal_file(s);
            std::cout << basename(const_cast<char *>(s.c_str())) << std::endl;
        }
    } else{
        for(auto s: files){
            std::cout << basename(const_cast<char *>(s.c_str())) << std::endl;
        }
    }
}

Printer::Printer(const UserChoise &userChoice) : userChoice(userChoice) {}

