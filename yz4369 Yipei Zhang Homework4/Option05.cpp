//
//  Option05.cpp
//  yz4369 Yipei Zhang Homework4
//
//  Created by Yipei Zhang on 10/5/21.
//

#include "Option05.hpp"
#include <iostream>
#include <cmath>
#include "BinomialTreeModel02.hpp"
using namespace std;
namespace fre {
    EurOption::~EurOption() {}
    double Call::Payoff(double z) const {
        if(z>K) return z-K;
        return 0.0;
    }
    double Put::Payoff(double z) const {
        if(z<K) return K-z;
        return 0.0;
}
    double BullSpreads::Payoff(double z) const {
        if (z <= K1) return 0;
        if (z > K1 and z < K2) return z-K1;
        return K2 - K1;
    }
    double BearSpreads::Payoff(double z) const {
        if (z <= K1) return K2 - K1;
        if (z > K1 and z < K2) return K2 - z;
        return 0;
    }

double OptionCalculation::PriceByCRR(const BinomialTreeModel& Model)
{   double optionPrice = 0.0;
    double q = Model.RiskNeutProb();
    int N = pOption->GetN();
    
    double* pPrice = new double[N + 1];
    for (int i = 0; i <= N; i++)
    {
        pPrice[i] = pOption->Payoff(Model.CalculateAssetPrice(N, i));
    }
    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
            {
                pPrice[i] = (q * pPrice[i + 1] + (1 - q) * pPrice[i]) / Model.GetR();
            }
    }
    optionPrice = pPrice[0];
    delete[] pPrice;
    pPrice = nullptr;
    return optionPrice;
    }
}
