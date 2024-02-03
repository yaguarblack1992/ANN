#include "net.h"

NET::NET(std::vector<int> num){
    // create architecture
    sizes = num;
    depth = static_cast<int>(num.size()) - 1;

    for(int i = 1;i<depth+1 ; ++i){
        layers.push_back(Eigen::VectorXd::Zero(sizes[i]));
        biases.push_back(Eigen::VectorXd::Zero(sizes[i]));
        weights.push_back(Eigen::MatrixXd::Random(sizes[i],sizes[i-1]));
        functions.push_back(_tanh);
    }
    input = Eigen::VectorXd::Zero(sizes.front());

}

void NET::Feed(){

    
}