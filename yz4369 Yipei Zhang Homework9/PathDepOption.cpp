//
//  PathDepOption.cpp
//  yz4369 Yipei Zhang Homework9
//
//  Created by Yipei Zhang on 11/17/21.
//

#include "PathDepOption.hpp"
#include <cmath>
namespace fre {
    double PathDepOption::PriceByMC(const MCModel& Model, long N)
    {
        double H = 0.0, Hsq = 0.0, Heps = 0.0;
        SamplePath S(m);
        for (long i = 0; i < N; i++)
        {
            Model.GenerateSamplePath(T, m, S);
            H = (i * H + Payoff(S)) / (i + 1.0);
        }
        Price = exp(-Model.GetR() * T) * H;
        return Price;
    }
    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        for (int k = 0; k < m; k++) Ave = (k * Ave + S[k]) / (k + 1.0);
        if (Ave < K) return 0.0;
        return Ave - K;
    }
    double EuroCall::Payoff(const SamplePath& S) const
    {
        if (S[m-1] < K) return 0.0;
        return S[m-1] - K;
    }
    double EuroPut::Payoff(const SamplePath& S) const
    {
        if (S[m - 1] > K) return 0.0;
        return K - S[m-1];
    }

}
