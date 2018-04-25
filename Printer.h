//
// Created by Victor on 23.04.2018.
//

#ifndef MYLS_PRINTER_H
#define MYLS_PRINTER_H

#include "UserChoise.h"
#include <boost/algorithm/string/predicate.hpp>
#include <libgen.h>

class Printer {

public:
    void print_results( std::vector<std::string> files);

    Printer(const UserChoise &userChoice);


private:
    const UserChoise userChoice;
    void mark_specal_file(std::string& files);
    void print_regular(std::vector<std::string>& files);
    void print_detailed(std::vector<std::string>& files);

};


#endif //MYLS_PRINTER_H
