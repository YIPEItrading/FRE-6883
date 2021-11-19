//
//  Function02.cpp
//  yz4369 Yipei Zhang Homework8
//
//  Created by Yipei Zhang on 11/4/21.
//

#include "Function02.hpp"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

namespace fre {
    double F1::Value(double x, double F, double T, vector <double> Coupon, vector <double> Tn) {

        double value = 0;
        for (int i = 0; i <= T - 1; i++)
        {
            value += Coupon[i] * exp(-1 * x * Tn[i]);
            //cout << x << ","<< Tn[i] << ","<< Coupon[i]<< endl;
        }
        value += F * exp(-1 * x * T);
        return value;
    }
    double F1::Deriv(double x, double F, double T, vector <double> Coupon, vector <double> Tn) {
        double deriv = 0;
        for (int i = 0; i <= T - 1; i++)
        {
            deriv += -1 * Tn[i] * Coupon[i] * exp(-1 * x * Tn[i]);
        }
        deriv += -1 * F * T * exp(-1 * x * T);
        return deriv;
    }
    double F2::Value(double x, double F, double T, vector <double> Coupon, vector <double> Tn) { return x * x - a; }
    double F2::Deriv(double x, double F, double T, vector <double> Coupon, vector <double> Tn) { return 2 * x; } }
