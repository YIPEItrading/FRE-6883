//
//  NumerMethods.hpp
//  yz4369 Yipei Zhang Homework3
//
//  Created by Yipei Zhang on 9/29/21.
//

#ifndef NumerMethods_hpp
#define NumerMethods_hpp

#pragma once

#include <stdio.h>

class DefInt
{
private:
    double a;
    double b;
    double (*func)(double x);
public:
    DefInt(double a, double b, double (*func)(double x));
    double ByTrapzoid(int N);
    double BySimpson(int N);
    
};

#endif /* NumerMethods_hpp */

