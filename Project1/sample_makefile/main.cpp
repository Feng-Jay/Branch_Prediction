#include <iostream>
#include <fstream>
#include <iomanip>
#include "bim_predictor.h"
#include "gshare.h"

using std::cout; using std::endl;

int main(int argc, char* argv[])
{
    int m =atoi(argv[1]);
    int n = atoi(argv[2]);
    string file = argv[5];
    // cout<<m<<endl;
    std::ifstream input("../traces/traces_all/"+file);
    // Bimpre bim(m);
    // bim.simulate(input);
    Gshare bim(m,n);
    bim.simulate(input);



    cout<<"COMMAND\n./sim gshare ";
    // cout./sim bimodal 7 0 0 "<<file<<endl;
    for(int i=1; i<argc;i++){
        cout<<argv[i]<<" ";
    }
    cout<<endl;
    cout<<"OUTPUT"<<endl;
    cout<<"number of predictions:   "<<bim.totalnum<<endl;
    cout<<"number of mispredictions:    "<<bim.wrong<<endl;
    cout<<"misprediction rate: "<<std::fixed<<std::setprecision(2)<<bim.wrong*1.0/bim.totalnum*1.0*100<<"%"<<endl;
    cout<<"FINAL GSHARE CONTENTS"<<endl;
    for(int i =0; i<pow(2,m); i++){
        cout <<i<<" "<<bim.bht[i]<<endl;
    }
    return 0;
}