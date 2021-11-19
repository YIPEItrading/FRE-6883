//
//  NumerMethods.cpp
//  yz4369 Yipei Zhang Homework3
//
//  Created by Yipei Zhang on 9/29/21.
//

#include "NumerMethods.hpp"
#include<iostream>
#include<cmath>
using namespace std;


DefInt::DefInt(double a1, double b1, double (*f1)(double x))
{
    a = a1;
    b = b1;
    func = f1;
}

double DefInt::ByTrapzoid(int N)
{
    cout << "Trapzoid rule: " << endl;
    double h = (b - a) / N;
    double result = (func(a) + func(b)) / 2;
    for (int i = 1; i < N; i++)
    {
        result = result + 2 * func(a + h * i);
    }
    result = result * h / 2;
    return result;
}
double DefInt::BySimpson(int N)
{
    cout << "Simpson rule: " << endl;
    double n = N;
    double h = (b - a)/n;
    double sum_odds = 0.0;
    for (int i = 1; i < n; i += 2)
        {
            sum_odds += func(a + i * h);
        }
    double sum_evens = 0.0;
    for (int i = 2; i < n; i += 2)
        {
            sum_evens += func(a + i * h);
        }

    return (func(a) + func(b) + 2 * sum_evens + 4 * sum_odds) * h / 3;
    
}
    

