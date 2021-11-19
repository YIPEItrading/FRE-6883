//
//  BSModel.hpp
//  yz4369 Yipei Zhang Homework7
//
//  Created by Yipei Zhang on 10/20/21.
//

#pragma once
#include <stdio.h>
#include "BinomialTreeModel02.hpp"
#include <cmath>
using namespace std;

class BSModel
{
private:
    double S0;
    double r;
    double sigma;
public:
    BSModel(double S0_, double r_, double sigma_) { S0 = S0_; r = r_; sigma = sigma_;}
    BinomialTreeModel ApproxBinModel(double h)
    {
        double U = exp(sigma * sqrt(h));
        double D = 1/U;
        double R = exp(r * h);
        BinomialTreeModel ApproxBinModel(S0, U, D, R);
        return ApproxBinModel;
    }
};
