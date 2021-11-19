//
//  NonlinearSolver02.hpp
//  yz4369 Yipei Zhang Homework8
//
//  Created by Yipei Zhang on 10/29/21.
//

#pragma once
#include "Function02.hpp"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
namespace fre {
    class NonlinearSolver {
        private:
            double Tgt;
            double LEnd;
            double REnd;
            double Acc;
            double Guess;
            double F;
            double T;
            
            
        public:
            vector <double> Coupon;
            vector <double> Tn;
            NonlinearSolver() : Tgt(0), LEnd(0), REnd(0), Acc(0), Guess(0), F(0), T(0), Coupon(0), Tn(0) {}
        
            NonlinearSolver(double Tgt_, double LEnd_, double REnd_, double Acc_, double Guess_, double F_, double T_, vector <double> Coupon_, vector <double> Tn_) : Tgt(Tgt_), LEnd(LEnd_), REnd(REnd_), Acc(Acc_), Guess(Guess_), F(F_), T(T_), Coupon(Coupon_), Tn(Tn_){}
            ~NonlinearSolver() {}
        
            void UpdateSolver(double Tgt_, double LEnd_, double REnd_, double Acc_, double Guess_, double F_, double T_, vector <double> Coupon_, vector <double> Tn_) {
                Tgt = Tgt_;
                LEnd = LEnd_; REnd = REnd_; Acc = Acc_; Guess = Guess_;
                F = F_; T = T_;
                Coupon = Coupon_; Tn = Tn_;
            }
            
        
            double SolveByBisect(Function* Fct);
            double SolveByNR(Function* Fct);
    };
}

    
    
    
