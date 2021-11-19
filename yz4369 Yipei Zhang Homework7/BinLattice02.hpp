//
//  BinLattice02.hpp
//  yz4369 Yipei Zhang Homework6
//
//  Created by Yipei Zhang on 10/20/21.
//

#ifndef BinLattice02_hpp
#define BinLattice02_hpp

#include <stdio.h>
#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
namespace fre {
template<typename Type>
class BinLattice {
    private:
        int N;
        vector< vector<Type> > Lattice;
    public:
        BinLattice() : N(0) {}
        BinLattice(int N_) :N(N_) {
            Lattice.resize(N + 1);
            for (int n = 0; n <= N; n++) Lattice[n].resize(n + 1);
        }
        ~BinLattice() {}
    
        void SetN(int N_)
        {
            N=N_;
            Lattice.resize(N + 1);
            for (int n = 0; n <= N; n++) Lattice[n].resize(n + 1); }
    
        void SetNode(int n, int i, Type x)
        {
            Lattice[n][i] = x; }
            Type GetNode(int n, int i)
            { return Lattice[n][i]; }
    
        void Display(ofstream& foutput)
        {
            foutput << setiosflags(ios::fixed) << setprecision(3); for (int n = 0; n <= N; n++)
            {
                for (int i = 0; i <= n; i++)
                    foutput << setw(15) << GetNode(n, i);
                foutput << endl;
            }
            foutput << endl;
        }
    };
}
#endif /* BinLattice02_hpp */
