//
//  main.cpp
//  yz4369 Yipei Zhang Homework9
//
//  Created by Yipei Zhang on 11/17/21.
//

#include <iostream>
#include "PathDepOption.hpp"
using namespace std;
using namespace fre;

int main()
{
    double S0 = 106.0;
    double r = 0.058;
    double sigma = 0.46;
    double T = 9.0 / 12.0;
    double K = 100.0;
    MCModel Model(S0, r, sigma);
    long N = 30000;

    EuroCall eurocall(T, K);
    eurocall.PriceByMC(Model, N);
    cout << "Eur Call Price = " << eurocall.GetPrice() << endl;

    EuroPut europut(T, K);
    europut.PriceByMC(Model, N);
    cout << "Eur Put Price = " << europut.GetPrice() << endl;

    return 0;
}

