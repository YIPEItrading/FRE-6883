//
//  Options02.hpp
//  hw2
//
//  Created by Yipei Zhang on 9/12/21.
//

#ifndef Options02_hpp
#define Options02_hpp

#include <stdio.h>

#endif /* Options02_hpp */
#pragma once
namespace fre {
//inputting and displaying option data
int GetInputData(int& N, double& K);
//pricing European option
double * PriceByCRR(double S0, double U, double D, double R, int N, double K,
double (*Payoff)(double z, double K));
//computing Call Payoff
double CallPayoff(double z, double K);
//computing Put Payoff
double PutPayoff(double z, double K);

double DigitCallPayoff(double z, double K);
double DigitPutPayoff(double z, double K);

}
