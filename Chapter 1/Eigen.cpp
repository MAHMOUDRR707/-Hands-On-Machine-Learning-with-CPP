#include <Eigen/Dense>
#include<iostream>
#include <vector>

using namespace std;
//declare of matrix
typedef Eigen::Matrix<float, 3, 3> MyMatrix33f;
typedef Eigen::Matrix<float, 3, 1> MyVector3f;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MyMatrix;


int main() {
    {
        

        MyMatrix33f a;
        MyVector3f v;
        MyMatrix m(10, 15);

        //zero matrix
        a = MyMatrix33f::Zero();
        cout << "Zero matrix:\n" << a << endl;

        //  identity matrix
        a = MyMatrix33f::Identity();
        cout << "Identity matrix:\n" << a << endl;

        //random matrix
        v = MyVector3f::Random();
        cout << "Random vector:\n" << v <<endl;

        // input of matrix
        a << 1, 2, 3, 4, 5, 6, 7, 8, 9;
       cout << "Comma initilized matrix:\n" << a << endl;

       // change value
       a(0, 0) = 11;
       cout << "Comma initilized matrix After :\n" << a << endl;

       // declare with another method using map
       int data[] = { 1,2,3,4 };
       Eigen::Map<Eigen::RowVectorXi> v_map(data, 4);
       cout << " map of v matrix : \n" << v_map <<endl;

       vector<float> v_data = { 1,2,3,4,5,6,7,8,9 };
       Eigen::Map<MyMatrix33f> a_map(v_data.data());
       cout << " map of v matrix : \n" << a_map << endl;
       }

    {
        
          // arithmetic
       Eigen::Matrix2d a;
       a << 1, 2, 3, 4;
       Eigen::Matrix2d b;
       b << 1, 2, 3, 4;
       cout << "Add the matrix \n" << a.array() + b.array() << endl;
       cout << "Add the matrix \n" << a + b << endl;
       cout << "multi the matrix \n" << a.array() * b.array() << endl;
       cout << "substract the matrix \n " << a.array() - b.array() << endl;
       cout << "divide the matrix \n" << a.array()/b.array() << endl;
       }

    {

        // patial access

        Eigen::MatrixXf m(4, 4);
        m << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16;
        cout << m << "\n";
        Eigen::Matrix2f b = m.block(1, 1, 2, 2); // copying the middle part of matrix
        cout << b << "\n";
        m.block(1, 1, 2, 2) *= 4; // change values in original matrix
        cout << m << "\n";
        m.row(3).array() += 4;
        cout << m << "\n";

        m.col(3).array() += 4;
        cout << m << "\n";

        m.row(3).col(3).array() *= 4;
        cout << m << "\n";

       }
    {
        // broadcasting
    Eigen::MatrixXf mat = Eigen::MatrixXf::Random(2, 4);
    Eigen::VectorXf v = Eigen::VectorXf::Random(2); // column vector
    cout << "v vector : \n" << " " << v << endl;
    cout << "mat matrix : \n " << "     " << mat << endl;
    mat += v;
    cout << "without col wise or row wise : \n" << mat << endl;
    mat.colwise() += v;
    cout << "col wise : \n" << mat << endl;

    return 0;
}
    }
