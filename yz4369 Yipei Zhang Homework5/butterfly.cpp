//
//  butterfly.cpp
//  yz4369 Yipei Zhang Homework4
//
//  Created by Yipei Zhang on 10/7/21.
//

#include "butterfly.hpp"

namespace fre{
    double ButterflyOpt::Payoff(double z) const
        {
            if (K1 < z and z <= (K1 + K2)/2) return z-K1;
            if ((K1 + K2)/2 < z and z <= K2) return K2 - z;
            return 0.0;
        }
}
