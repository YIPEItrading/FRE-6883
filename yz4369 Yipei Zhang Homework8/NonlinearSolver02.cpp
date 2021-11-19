//
//  NonlinearSolver02.cpp
//  yz4369 Yipei Zhang Homework8
//
//  Created by Yipei Zhang on 10/29/21.
//

#include "NonlinearSolver02.hpp"
#include <iostream>
namespace fre {
    double NonlinearSolver::SolveByBisect(Function* Fct){
        double left = LEnd, right = REnd, mid = (left + right) / 2;
        double Future = F, Time = T;
        vector <double> Coupon_list = Coupon;
        vector <double> Tn_list = Tn;
        double y_left = Fct->Value(left, Future, Time, Coupon_list, Tn_list) - Tgt, y_mid = Fct->Value(mid, Future, Time, Coupon_list, Tn_list) - Tgt;
        while (mid - left > Acc){
            if ((y_left > 0 && y_mid > 0) || (y_left < 0 && y_mid < 0)) {
                left = mid; y_left = y_mid; }
            else right = mid;
            mid = (left + right) / 2;
            y_mid = Fct->Value(mid, Future, Time, Coupon_list, Tn_list) - Tgt;
        }
        return mid;
    }
    double NonlinearSolver::SolveByNR(Function* Fct){
        double x_prev = Guess;
        double Future = F, Time = T;
        vector <double> Coupon_list = Coupon;
        vector <double> Tn_list = Tn;
        double x_next = x_prev - (Fct->Value(x_prev, Future, Time, Coupon_list, Tn_list) - Tgt) / Fct->Deriv(x_prev, Future, Time, Coupon_list, Tn_list);
        while (x_next - x_prev > Acc || x_prev - x_next > Acc){
            x_prev = x_next;
            x_next = x_prev - (Fct->Value(x_prev, Future, Time, Coupon_list, Tn_list) - Tgt) / Fct->Deriv(x_prev, Future, Time, Coupon_list, Tn_list);
        }
        return x_next;
    }
    
   
}
