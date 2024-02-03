#include <iostream>
#include <Eigen/Eigen/Dense>

Eigen::MatrixXd convolve(const Eigen::MatrixXd& input, const Eigen::MatrixXd& kernel){
    int size = input.rows() - kernel.rows() + 1;
    Eigen::MatrixXd result(size,size);

    for(int r = 0;r< size;++r)
        for (int c = 0; c < size; c++)
        {
            result(r,c) = (kernel.array() * ( input.block(r,c,kernel.rows(),kernel.cols())).array()).sum();
        }
      return result;  
}

int main(){
    Eigen::initParallel();
    Eigen::MatrixXd cell(4,4);
    Eigen::MatrixXd kernel(3,3);

    cell<<
        1,0,1,0,
        0,0,1,1,
        1,1,1,0,
        0,0,1,1;

    kernel<<
        1,2,1,
        0,0,0,
        -1,-2,-1;
    
    std::cout << convolve(cell,kernel);
    return 0;
}