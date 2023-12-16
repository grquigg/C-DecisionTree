#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include <memory>
#include <ostream>

class Node {
    public:
        //constructor
        Node(void);
        //destructor
        Node(const Node&) = delete;
    private:
        //variables
        std::shared_ptr<const Node> right;
        std::shared_ptr<const Node> left;
        // vector<vector<float>> data;

        //methods

};

#endif 