//
//  Option01.hpp
//  hw1
//
//  Created by Yipei Zhang on 9/12/21.
//

#ifndef Option01_hpp
#define Option01_hpp

#include <stdio.h>

#endif /* Option01_hpp */
#pragma once
namespace fre {
//pricing European option
double PriceByCRR(double S0, double U, double D, double R,
                  int N, double K);
//computing call payoff
double CallPayoff(double z, double K);



// HW1 version 2
double HW1Factorial(int n);
double HW1V2PriceByCRR(double S0, double U, double D, double R,
                  int N, double K);
}
