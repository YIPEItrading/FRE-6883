//
//  
//  hw1
//
//  Created by Yipei Zhang on 9/12/21.
//

#include <stdio.h>
#include "BinomialTreeModel.hpp"
#include "Option01.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace fre;
int main()
{ double u = 1.15125, d = 0.86862, r = 1.00545;
double s0 = 106.00, k = 100.00;
    const int N = 8;
    double optionPrice = HW1V2PriceByCRR(s0, u, d, r, N, k);
    cout << "European call option price = " << fixed <<
           setprecision(2) << optionPrice << endl;
return 0; }
//u = 1.15125 d = 0.86862 r = 1.00545
//s0 = 106 k = 100
//N = 8

// By Using modified fuction, European call option price = 21.68
