//
//  Option01.cpp
//  hw1
//
//  Created by Yipei Zhang on 9/12/21.
//

#include "Option01.hpp"
#include "BinomialTreeModel.hpp"
#include <iostream>
#include <cmath>
using namespace std;
namespace fre {
double PriceByCRR(double S0, double U, double D, double R, int N, double K) {
double q = RiskNeutProb(U, D, R);
// If you are using MAC XCode
double Price[N];
// If you use Microsoft Visual Studio 2019,
//double Price[9];
for (int i = 0; i < sizeof(N); i++)
Price[i] = 0.0; 
for (int i = 0; i <= N; i++) {
Price[i] = CallPayoff(CalculateAssetPrice(S0, U, D, N, i), K); }
for (int n = N - 1; n >= 0; n--) {
for (int i = 0; i <= n; i++) {
Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / R; }
}
return Price[0]; }
double CallPayoff(double z, double K) {
if (z > K) return z - K;
return 0.0; }


double HW1Factorial(int n){
    double num = 1.0;
    if (n<= 0)
        return num;
    do{
        num = num * n;
        n--;
    }while (n>0);
    return num;
}
double HW1V2PriceByCRR(double S0, double U, double D, double R,
                       int N, double K){
    double q = RiskNeutProb(U, D, R);
    double Price = 0;
    double FactorialN = HW1Factorial(N);
    for(int i =0; i <= N; i++){
        Price = Price + FactorialN/(HW1Factorial(i) * HW1Factorial(N-i)) * pow(q, i) * pow(1-q, N-i) * CallPayoff(CalculateAssetPrice(S0, U, D, N, i), K);
    }
    Price = Price / pow(R, N);
    return Price;
}

    

}
