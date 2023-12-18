#ifndef _HELPER_H_
#define _HELPER_H_

#include <string>
#include "helper.h"
#include <fstream>
#include <stdexcept>

static void readFromFile(std::string filename) {
    std::ifstream myFile(filename);

    if(!myFile.is_open()) throw std::runtime_error("Could not open file");
    std::cout << "File successfully found" << std::endl;
};

#endif
