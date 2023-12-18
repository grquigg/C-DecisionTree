#include <iostream>
#include <cassert>
#include "tree.h"
#include "helper.h"
#include <string>

int main(int argc, char** argv)
{
  ///////////////////////////
  std::cout << "Hello World." << std::endl;
  std::cout << argv[0] << std::endl;
  //data ingestion
  std::cout << "Data ingestion here:" << std::endl;
  DecisionTree tree("entropy");
  readFromFile("../../loan.csv");
  return 0;
}

