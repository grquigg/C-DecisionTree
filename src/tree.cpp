#include "tree.h"
#include <iostream>
//constructor

DecisionTree::DecisionTree(std::string split) {
    std::cout << split << std::endl;
    this->_split = split;
}