//
//  GmtrAsianCall.hpp
//  yz4369 Yipei Zhang Homework11
//
//  Created by Yipei Zhang on 11/17/21.
//

#include "PathDepOption.hpp"
namespace fre {
    class GmtrAsianCall : public PathDepOption
    {
    public:
        GmtrAsianCall(double T_, double K_, int m_) : PathDepOption(T_, K_, m_) {}
        double Payoff(const SamplePath& S) const;
        double PriceByBSFormula(const MCModel& Model);
        double DeltaByBSFormula(const MCModel& Model);
    };
}
