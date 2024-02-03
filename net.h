#include <Eigen/Eigen/Dense>
#include <vector>
#include <iostream>
#include "activation.h"

class NET{
    Eigen::VectorXd input;
    int depth;
    std::vector<int> sizes;
    std::vector<activation> functions;
    std::vector<Eigen::MatrixXd> weights;
    std::vector<Eigen::VectorXd> layers;
    std::vector<Eigen::VectorXd> biases;
public:
    // constructors
    NET(std::vector<int> num = {1,3,1});
    void Feed();

};