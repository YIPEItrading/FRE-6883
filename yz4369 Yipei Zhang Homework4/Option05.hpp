//
//  Option05.hpp
//  yz4369 Yipei Zhang Homework4
//
//  Created by Yipei Zhang on 10/5/21.
//
#pragma once
#include "BinomialTreeModel02.hpp"

#ifndef Option05_hpp
#define Option05_hpp

#include <stdio.h>
namespace fre {
    class EurOption {
        private:
            EurOption() : N(0) {}
            EurOption(const EurOption& option) : N(option.N) {}
        protected:
            int N;
        public:
            EurOption(int N_) : N(N_) {}
            int GetN() const { return N; }
            virtual double Payoff(double z) const = 0;
            virtual ~EurOption() = 0;
};
    class Call :public EurOption {
        private:
            double K;
        public:
            Call(int N_, double K_) : EurOption(N_), K(K_) {}
            ~Call() {}
            double Payoff(double z) const;
};
    class Put : public EurOption {
        private:
            double K;
        public:
            Put(int N_, double K_) : EurOption(N_) , K(K_) {}
            ~Put() {}
            double Payoff(double z) const;
};
    class BullSpreads :public EurOption {
        private:
            double K1;
            double K2;
        public:
        BullSpreads(int N_, double K1_, double K2_) : EurOption(N_), K1(K1_), K2(K2_) {}
            ~BullSpreads() {}
            double Payoff(double z) const;
    };
    class BearSpreads :public EurOption {
        private:
            double K1;
            double K2;
        public:
        BearSpreads(int N_, double K1_, double K2_) : EurOption(N_), K1(K1_), K2(K2_) {}
            ~BearSpreads() {}
            double Payoff(double z) const;
    };
    class OptionCalculation {
        private:
            EurOption* pOption;
            OptionCalculation() : pOption(0) {}
            OptionCalculation(const OptionCalculation& optionCalculation)
                : pOption(optionCalculation.pOption) {}
        public:
            OptionCalculation(EurOption* pOption_) : pOption(pOption_) {}
            ~OptionCalculation() {}
            double PriceByCRR(const BinomialTreeModel& model);
};
}
#endif /* Option05_hpp */
