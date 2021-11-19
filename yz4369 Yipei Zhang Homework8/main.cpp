//
//  main.cpp
//  yz4369 Yipei Zhang Homework8
//
//  Created by Yipei Zhang on 10/29/21.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "Function02.hpp"
#include "NonlinearSolver02.hpp"
using namespace std;
using namespace fre;


int main()
{
    double Acc = 0.0001;
    double LEnd = 0.0;
    double REnd = 1.0;
    double Guess = 0.2;
    
    double F=100.0;
    double T=3.0;
    double C=1.2;
    double P=98.56;

    vector<double> coupon;
    vector<double> Tn;
    
    coupon.push_back(C); coupon.push_back(C); coupon.push_back(C);
    Tn.push_back(1.0); Tn.push_back(2.0); Tn.push_back(3.0);
    
    NonlinearSolver solver(P, LEnd, REnd, Acc, Guess, F, T, coupon, Tn);
    
   
    
    F1 MyF1;
    cout << "Yield by bisection methods: " << fixed << setprecision(4)
    << solver.SolveByBisect(&MyF1) << endl;
     cout << "Yeild by Newton - Raphson Medhos: " << fixed << setprecision(4)
    << solver.SolveByNR(&MyF1) << endl;
    
    
    return 0;
   }


/*
    double F=100.0;
    double T=3.0;
    double C=1.2;
    double P=98.56;

    double Acc=0.0001;
    double LEnd=0.0;
    double REnd=1.0;
    double Guess=0.2;
 
 Output:
     Yield by bisection methods: 0.0168
     Yeild by Newton - Raphson Medhos: 0.0168
     Program ended with exit code: 0
 
 */
