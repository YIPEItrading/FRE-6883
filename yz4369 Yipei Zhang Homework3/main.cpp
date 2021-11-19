//
//  main.cpp
//  yz4369 Yipei Zhang Homework3
//
//  Created by Yipei Zhang on 9/29/21.
//

#include <iostream>
#include <cmath>
#include "NumerMethods.hpp"
using namespace std;

double func(double x)
{
    return x*x*x-x*x+1;
}

int main()
{
    double a = 1.0;
    double b = 2.0;
    DefInt MyInt(a, b, func);

    cout << MyInt.ByTrapzoid(1000) << endl;
    cout << MyInt.BySimpson(1000) << endl;
    
}
