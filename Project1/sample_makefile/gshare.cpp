#include "gshare.h"

Gshare::Gshare(int m, int n):m(m),n(n)
{
    totalnum =0; right=0; wrong =0;
    maskn = pow(2,n)-1;
    maskatt =pow(2,m-n)-1;
    gbhr = 0;
    int num = pow(2,m);
    bht = new int [num];
    for(int i=0;i<num;++i){
        bht[i]=2;
    }
    // cout<<"work!"<<endl;
}

void Gshare::simulate(ifstream& infile)
{
    string line;
    while(getline(infile,line)){
        ++totalnum;
        int pc = std::stoi(line.substr(0,8),0,16);
        string jmp = line.substr(7,line.length());
        int attach = (pc>>2) & maskatt;
        int xorn = (pc>>(m-n+2)) & maskn;
        xorn = xorn^gbhr;
        int index = (xorn<<(m-n))+attach;
        // cout<<index<<endl;
        // break;
        switch (this->bht[index])
        {
        case 0 :{
            if(jmp == "t"){
                bht[index]=1;
                ++wrong;
            }else ++right;
        }
            break;

        case 1:{
            if(jmp == "n"){
                bht[index]=0;
                ++right;
            }else{
                bht[index]=2;
                ++wrong;
            }
        }
            break;
        case 2:{
            if(jmp=="t"){
                bht[index]=3;
                ++right;
            }else{
                bht[index]=1;
                ++wrong;
            }
        } 
            break;
        case 3:{
            if(jmp=="n"){
                bht[index]=2;
                ++wrong;
            }else ++right;
        }
            break;
        default:
            cout<<"Alert: format wrong!!!"<<endl;
            break;
        }
        gbhr=gbhr>>1;
        if(jmp=="t"){
            gbhr+=pow(2,n-1);
        }
    }
}

Gshare::~Gshare(){
    delete [] bht;
}