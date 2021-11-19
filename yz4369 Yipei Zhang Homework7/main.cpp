//
//  main.cpp
//  yz4369 Yipei Zhang Homework7
//
//  Created by Yipei Zhang on 10/8/21.
//

#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include"BSModel.hpp"
#include"BinomialTreeModel02.hpp"
#include "Option08.hpp"
#include "BinLattice02.hpp"


using namespace std;
using namespace fre;
int main()
{
    double S0=106.0;
    double r=0.058;
    double sigma=0.46;
    double T=(double)9/12;
    double K=100.0;
    int N=8;

    cout << setiosflags(ios::fixed) << setprecision(5);

    Call Option1(N, K);
    OptionCalculation callCalculation(&Option1);
    
    cout << "S0 = " << S0 << endl;
    cout << "r = " << r << endl;
    cout << "sigma = " << sigma << endl;
    cout << "T = " << T << endl;
    cout << "K = " << Option1.GetK() << endl;
    cout << "N = " << Option1.GetN() << endl;
    cout<<endl;
    
    
    
    BSModel Model(S0, r, sigma);
    double h = T / Option1.GetN();
    BinomialTreeModel ApproxBinModel = Model.ApproxBinModel(h);
    cout << "U = " << ApproxBinModel.GetU() << endl;
    cout << "D = " << ApproxBinModel.GetD() << endl;
    cout << "R = " << ApproxBinModel.GetR() << endl;
    
    BinLattice<double> PriceTree;
    BinLattice<bool> StoppingTree;

    cout << "American call option price = " << callCalculation.PriceBySnell(ApproxBinModel, PriceTree, StoppingTree) << endl;
     
    return 0;
}


/*
 S0 = 106.00000
 r = 0.05800
 sigma = 0.46000
 T = 0.75000
 K = 100.00000
 N = 8

 U = 1.15125
 D = 0.86862
 R = 1.00545
 American call option price = 21.68171
 Program ended with exit code: 0
 */
