#include <Eigen/Dense>
#include<iostream>
#include <vector>
#include <Eigen/IterativeLinearSolvers>
#include<string>
#include<random>
#include<algorithm>


using namespace std;
//declare of matrix
typedef Eigen::Matrix<float, 3, 3> MyMatrix33f;
typedef Eigen::Matrix<float, 3, 1> MyVector3f;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MyMatrix;

pair<Eigen::MatrixXf, Eigen::MatrixXf> GenerateData(size_t n) {
    vector<float> x_data(n,0);
    
    vector<float> y_data(n,0);

    // mutate data
    random_device rd;
    mt19937 re(rd());
    uniform_real_distribution<float> dist(-1.5f, 1.5f);

    for (auto& x : x_data) {
        x += dist(re);  // add noise
    }

    for (auto& y : y_data) {
        y += dist(re);  // add noise
    }

    // Make result
    Eigen::Map<Eigen::MatrixXf> x(x_data.data(), static_cast<Eigen::Index>(n), 1);
    Eigen::Map<Eigen::MatrixXf> y(y_data.data(), static_cast<Eigen::Index>(n), 1);

    return { x, y };
}

   int main(){
   size_t n = 1000;
    // generate training data
    Eigen::MatrixXf x1, y;
    std::tie(x1, y) = GenerateData(n);
    Eigen::MatrixXf x0 = Eigen::MatrixXf::Ones(n, 1);
    // setup line coeficients y = b(4) + k(0.3)*x
    y.array() *= 0.3f;
    y.array() += 4.f;
    Eigen::MatrixXf x(n, 2);
    x << x0, x1;

    // train estimator
    Eigen::LeastSquaresConjugateGradient<Eigen::MatrixXf> gd;
    gd.setMaxIterations(1000);
    gd.setTolerance(0.001f);
    gd.compute(x);
    Eigen::VectorXf b = gd.solve(y);
    cout << b << endl;

    // normal equations
    Eigen::VectorXf b_norm = (x.transpose() * x).ldlt().solve(x.transpose() * y);
    std::cout << "Estimated with normal equation parameters vector : " << b_norm
        << std::endl;

    Eigen::MatrixXf new_x(5, 2);
    new_x << 1, 1, 1, 2, 1, 3, 1, 4, 1, 5;
    auto new_y = new_x.array().rowwise() * b.transpose().array();
    std::cout << "Predicted values : \n" << new_y << std::endl;

    auto new_y_norm = new_x.array().rowwise() * b_norm.transpose().array();
    std::cout << "Predicted(norm) values : \n" << new_y_norm << std::endl;

    return 0;
    }
