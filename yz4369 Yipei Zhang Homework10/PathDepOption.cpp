//
//  PathDepOption.cpp
//  yz4369 Yipei Zhang Homework10
//
//  Created by Yipei Zhang on 11/17/21.
//

#include "PathDepOption.hpp"
#include <cmath>
namespace fre {
    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        for (int k = 0; k < m; k++) Ave = (k * Ave + S[k]) / (k + 1.0);
        if (Ave < K) return 0.0;
        return Ave - K;
    }
    void Rescale(SamplePath& S, double x)
    {
        int m = (int)S.size();
        for (int j = 0; j < m; j++) S[j] = x * S[j];
    }
    double PathDepOption::PriceByMC(const MCModel& Model, long N, double epsilon)
    {
        double H = 0.0, Hsq = 0.0, Heps = 0.0, Hminuseps = 0.0;
        SamplePath S(m);
        for (long i = 0; i < N; i++)
        {
            Model.GenerateSamplePath(T, m, S);
            H = (i * H + Payoff(S)) / (i + 1.0);
            Hsq = (i * Hsq + pow(Payoff(S), 2.0)) / (i + 1.0);
            Rescale(S, 1.0 + epsilon);
            Heps = (i * Heps + Payoff(S)) / (i + 1.0);
            Rescale(S, (1.0 - epsilon) / (1.0 + epsilon));
            Hminuseps = (i * Hminuseps + Payoff(S)) / (i + 1.0);
        }
        Price = exp(-Model.GetR() * T) * H;
        PricingError = exp(-Model.GetR() * T) * sqrt(Hsq - H * H) / sqrt(N - 1.0);
        delta = exp(-Model.GetR() * T) * (Heps - H) / (Model.GetS0() * epsilon);
        gamma = exp(-Model.GetR() * T) * (Heps - 2 * H + Hminuseps) / pow(epsilon * Model.GetS0(), 2);
        return Price;
    }
}
