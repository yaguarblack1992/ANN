#include <Eigen/Eigen/Dense>

using function = Eigen::MatrixXd(*)(const Eigen::MatrixXd&);

Eigen::MatrixXd tanh(const Eigen::MatrixXd& m);
Eigen::MatrixXd dtanh(const Eigen::MatrixXd& m);
Eigen::MatrixXd sigmoid(const Eigen::MatrixXd& m);
Eigen::MatrixXd dsigmoid(const Eigen::MatrixXd& m);


struct activation
{
    function activ;
    function deriv;
    std::string name;
    activation(function a = tanh,function b = dtanh, std::string n = "tanh"){
        activ = a;
        deriv = b;
        name = n;
    }
};

extern activation _tanh;
extern activation _sigm;