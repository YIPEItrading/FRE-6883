//
//  strangle.cpp
//  yz4369 Yipei Zhang Homework4
//
//  Created by Yipei Zhang on 10/7/21.
//

#include "strangle.hpp"
namespace fre{
    double StrangleOpt::Payoff(double z) const
        {
            if (z <= K1) return K1 - z;
            if (K1 < z and z <= K2) return 0;
            return z - K2;
        }
}
