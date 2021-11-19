//
//  PathDepOption.hpp
//  yz4369 Yipei Zhang Homework9
//
//  Created by Yipei Zhang on 11/17/21.
//

#pragma once
#include "MCModel.hpp"
namespace fre {
    class PathDepOption
    {
    protected:
        double Price;
        int m;
        double K;
        double T;
    public:
        PathDepOption(double T_, double K_, int m_) :Price(0.0), T(T_), K(K_), m(m_)
        {}
        virtual ~PathDepOption() {}
        virtual double Payoff(const SamplePath& S) const = 0;
        double PriceByMC(const MCModel& Model, long N);
        double GetT() { return T; }
        double GetPrice() { return Price; }
    };
    class ArthmAsianCall : public PathDepOption
    {
    public:
        ArthmAsianCall(double T_, double K_, int m_) :PathDepOption(T_, K_, m_) {}
        double Payoff(const SamplePath& S) const;
    };
    class EuroCall : public PathDepOption
    {
    public:
        EuroCall(double T_,double K_):PathDepOption(T_,K_,30){}
        double Payoff(const SamplePath& S) const;
    };
    class EuroPut : public PathDepOption
    {
    public:
        EuroPut(double T_, double K_) :PathDepOption(T_, K_, 30) {}
        double Payoff(const SamplePath& S) const;
    };
}
