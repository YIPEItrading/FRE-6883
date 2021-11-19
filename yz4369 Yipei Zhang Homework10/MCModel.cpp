//
//  MCModel.cpp
//  yz4369 Yipei Zhang Homework10
//
//  Created by Yipei Zhang on 11/17/21.
//


#include "MCModel.hpp"
#include <cmath>
namespace fre {
    const double pi = 4.0 * atan(1.0);
    double Gauss()
    {
        double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
        double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);
        return sqrt(-2.0 * log(U1)) * cos(2.0 * pi * U2);
    }
    void MCModel::GenerateSamplePath(double T, int m, SamplePath& S) const
    {
        double St = S0;
        for (int k = 0; k < m; k++)
        {
            S[k] = St * exp((r - sigma * sigma * 0.5) * (T / m) + sigma * sqrt(T / m) * Gauss());
            St = S[k];
        }
    }
}
