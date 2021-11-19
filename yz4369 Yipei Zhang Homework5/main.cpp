//
//  main.cpp
//  yz4369 Yipei Zhang Homework4
//
//  Created by Yipei Zhang on 10/5/21.
//

#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.hpp"
#include "Option05.hpp"
#include "DoubDigitOpt.hpp"
#include "butterfly.hpp"
#include "strangle.hpp"
using namespace std;
using namespace fre;


int main()
{
    int N=8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K1 = 100, K2 = 110;
    BinomialTreeModel Model(S0, U, D, R);
    DoubDigitOpt doubDigitOpt(N, K1, K2);
    OptionCalculation optCalculation(&doubDigitOpt);
    cout << "European double digit option price = "
    << fixed << setprecision(2) << optCalculation.PriceByCRR(Model) << endl;
    
    StrangleOpt strangleOpt(N, K1, K2);
    OptionCalculation strangleOpt_Calculation(&strangleOpt);
    cout << "European strangle option price = "
    << fixed << setprecision(2) << strangleOpt_Calculation.PriceByCRR(Model) << endl;
    
    ButterflyOpt butterflyOpt(N, K1, K2);
    OptionCalculation butterflyOpt_Calculation(&butterflyOpt);
    cout << "European butterfly option price = "
    << fixed << setprecision(2) << butterflyOpt_Calculation.PriceByCRR(Model) << endl;
    return 0;
}

/*
 European double digit option price = 0.26
 European strangle option price = 28.39
 European butterfly option price = 1.04
 Program ended with exit code: 0
 */
