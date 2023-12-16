#ifndef _TREE_H_
#define _TREE_H_

#include <string>
#include "node.h"

class DecisionTree {
    public:
        //constructor
        // DecisionTree(void);
        DecisionTree(std::string split="gini");
    private:
        std::shared_ptr<const Node> root;
        std::string _split;
};

#endif /* _TREE_H_ */