#include "BinomialTreeModel02.hpp"
#include "Option08.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
using namespace fre;
int main()
{
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K = 100.00;
    BinomialTreeModel Model(S0, U, D, R);
    
    ofstream fout;
    fout.open("Results.txt");
    
    BinLattice<double> PriceTree;
    BinLattice<double> XTree;
    BinLattice<double> YTree;
    
    Call call(N, K);
    OptionCalculation callCalculation(&call);
    
    fout << "European call prices by PriceByCRR:"
    << fixed << setprecision(3) << callCalculation.PriceByCRR(Model) << endl << endl;
    
    fout << "European call prices by HW6 PriceByCRR:"
    << fixed << setprecision(3) << callCalculation.PriceByCRR(Model, PriceTree, XTree, YTree) << endl << endl;
    
    fout << "Stock positions in replicating strategy:" << endl << endl;
    XTree.Display(fout);
    fout << "Money market account positions in replicating strategy:" << endl << endl;
    YTree.Display(fout);
    
    Put put(N, K);
    OptionCalculation putCalculation(&put);
    
    fout << "European call prices by PriceByCRR:"
    << fixed << setprecision(3) << putCalculation.PriceByCRR(Model) << endl << endl;
    
    fout << "European call prices by HW6 PriceByCRR:"
    << fixed << setprecision(3) << putCalculation.PriceByCRR(Model, PriceTree, XTree, YTree) << endl << endl;
    
    fout << "Stock positions in replicating strategy:" << endl << endl;
    XTree.Display(fout);
    fout << "Money market account positions in replicating strategy:" << endl << endl;
    YTree.Display(fout);
    
    return 0;
}
