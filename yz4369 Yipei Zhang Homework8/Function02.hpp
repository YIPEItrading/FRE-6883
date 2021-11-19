//
//  Function02.hpp
//  yz4369 Yipei Zhang Homework8
//
//  Created by Yipei Zhang on 11/4/21.
//

#pragma once
#include <vector>

using namespace std;
namespace fre {
    class Function{

        
    public:
        virtual double Value(double x, double F, double T, vector <double> Coupon, vector <double> Tn) = 0;
        virtual double Deriv(double x, double F, double T, vector <double> Coupon, vector <double> Tn) = 0;
        virtual ~Function() {}
    };

    class F1 : public Function {
    public:
        double Value(double x, double F, double T, vector <double> Coupon, vector <double> Tn);
        double Deriv(double x, double F, double T, vector <double> Coupon, vector <double> Tn);
    };

    class F2 : public Function {
    private:
        double a; //any real number
    public:
        F2(double a_) { a = a_; }
        double Value(double x, double F, double T, vector <double> Coupon, vector <double> Tn);
        double Deriv(double x, double F, double T, vector <double> Coupon, vector <double> Tn);
    };
}
