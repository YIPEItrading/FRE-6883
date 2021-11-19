//
//  main.cpp
//  yz4369 Yipei Zhang Homework11
//
//  Created by Yipei Zhang on 11/17/21.
//

#include <iostream>
#include "PathDepOption.hpp"
#include "GmtrAsianCall.hpp"
using namespace std;
using namespace fre;

int main()
{
    double S0 = 100.0, r = 0.03, sigma = 0.2;
    MCModel Model(S0, r, sigma);
    double T = 1.0 / 12.0, K = 100.0;
    int m = 30;
    ArthmAsianCall Option(T, K, m);
    GmtrAsianCall CVOption(T, K, m);
    long N = 30000;
    double epsilon = 0.001;
    Option.PriceByVarRedMC(Model, N, CVOption, epsilon);
    cout << "Arithmetic call price = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl
        << "delta = " << Option.GetDelta() << endl << endl;
    Option.PriceByMC(Model, N, epsilon);
    cout << "Price by direct MC = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl
        << "delta = " << Option.GetDelta() <<endl << endl;
    return 0;
}
