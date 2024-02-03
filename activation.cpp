#include "activation.h"

Eigen::MatrixXd tanh(const Eigen::MatrixXd &m)
{
    return m.array().tanh();
}
Eigen::MatrixXd dtanh(const Eigen::MatrixXd &m)
{
    return 1.0 - m.array().tanh().square();
}
Eigen::MatrixXd sigmoid(const Eigen::MatrixXd &m)
{
    return m.unaryExpr([](double x){
        return 1.0 / (1.0 + exp(-x));
    });
}
Eigen::MatrixXd dsigmoid(const Eigen::MatrixXd &m)
{
    auto sigm = sigmoid(m);
    return sigm.array() * (1.0 - sigm.array());
}

activation _sigm(sigmoid,dsigmoid,"sigmoid");
activation _tanh(tanh,dtanh,"tanh");