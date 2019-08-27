#include "kalman_filter.h"
#include <iostream>

using std::cout;
using std::endl;

KalmanFilter::KalmanFilter()
{
}

KalmanFilter::~KalmanFilter()
{
}

void KalmanFilter::InitState(VectorXd &x_in, MatrixXd &P_in)
{
    x_ = x_in;
    P_ = P_in;
}

void KalmanFilter::Predict(MatrixXd F_, MatrixXd Q_)
{
    cout << "KalmanFilter::Predict()" << endl;
    cout << "Pre" << endl;
    cout << "x: " << x_ << endl;
    cout << "P: " << P_ << endl;
    cout << "Q: " << Q_ << endl;
    x_ = F_ * x_;
    P_ = F_ * P_ * F_.transpose() + Q_;
    cout << F_ * P_ * F_.transpose() << "\n" << endl;
    cout << "Post" << endl;
    cout << "x: " << x_ << endl;
    cout << "P: " << P_ << endl;
}

void KalmanFilter::Update(const VectorXd &z, MatrixXd H_, MatrixXd R_)
{
    cout << "Update()" << endl;
    VectorXd y = z - H_ * x_;
    MatrixXd S = H_ * P_ * H_.transpose() + R_;
    MatrixXd K = P_ * H_.transpose() * S.inverse();

    cout << "y: " << y << endl;
    cout << "S: " << S << endl;
    cout << "K: " << K << endl;
    cout << "H: " << H_ << endl;
    cout << "R: " << R_ << endl;
    cout << "P: " << P_ << endl;
    x_ = x_ + (K * y);
    MatrixXd I_ = MatrixXd::Identity(x_.size(), x_.size());
    P_ = (I_ - K * H_) * P_;
}

void KalmanFilter::UpdateEKF(const VectorXd &z, MatrixXd H_, MatrixXd R_)
{

}

VectorXd KalmanFilter::GetX()
{
    return x_;
}
