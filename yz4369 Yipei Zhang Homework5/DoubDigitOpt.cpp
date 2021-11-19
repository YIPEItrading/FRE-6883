//
//  DoubleDigitOpt.cpp
//  yz4369 Yipei Zhang Homework4
//
//  Created by Yipei Zhang on 10/7/21.
//

#include "DoubDigitOpt.hpp"

namespace fre{
    double DoubDigitOpt::Payoff(double z) const
        {
           if (K1 < z and z < K2)
               return 1.0;
            return 0.0;
        }
}
