#include <iomanip>
#include <algorithm>
// #include <cctype>
// #include <functional>
#include "bim_predictor.h"
#include "gshare.h"

using std::cout; using std::endl;

template <typename cla>
void print(cla& bim,string str){
    cout<<"OUTPUT"<<endl;
    cout<<"number of predictions:   "<<bim.total_num<<endl;
    cout<<"number of mispredictions:    "<<bim.wrong<<endl;
    cout<<"misprediction rate: "<<std::fixed<<std::setprecision(2)<<bim.wrong*1.0/bim.total_num*1.0*100<<"%"<<endl;
    transform(str.begin(), str.end(), str.begin(),::toupper);
    cout<<"FINAL "<<str<<" CONTENTS"<<endl;
    for(int i =0; i<pow(2,bim.m); ++i){
        cout <<i<<" "<<bim.bht[i]<<endl;
    }
}

int main(int argc, char* argv[])
{

    string type = argv[1];
    string file;
    int m =atoi(argv[2]);
    int n = atoi(argv[3]);
    if(type=="bimodal")
        file = argv[5];
    else if (type=="gshare")
        file = argv[6];
    else{
        cout<<"Patameter error!"<<endl;
        return -1;
    }
    std::ifstream input("../traces/traces_all/"+file);
    cout<<"COMMAND\n";
    for(int i=0; i<argc;i++){
        cout<<argv[i]<<" ";
    }
    cout<<endl;
    
    if (type=="bimodal"){
        Bimpre bim(m);
        bim.simulate(input);
        print<Bimpre>(bim,type);
    }else {
        Gshare share(m,n);
        share.simulate(input);
        print<Gshare>(share,type);
    }
    return 0;
}