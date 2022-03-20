#include "bim_predictor.h"

Bimpre::Bimpre(int m):m(m)
{
    total_num=0; wrong=0; right=0;
    int num=pow(2,m);
    bht = new int [num];
    mask = pow(2,m+2) -4;
    // init
    for(int i=0; i<pow(2,m); ++i)
        bht[i]=2;
    // cout<<"work!"<<endl;
}

void Bimpre::simulate(std::istream& infile){
    string line;
    // int i =0;
    while(getline(infile,line)){
        ++total_num;
        // std::cout<<line<<std::endl;
        int pc = std::stoi(line.substr(0,8),0,16);
        string jmp = line.substr(7,line.length());
        int index = (pc&this->mask)>>2;

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
        // cout<<pc<<endl;
        // cout<<index<<endl;
        // ++i;
    }
    // infile.open()
}

Bimpre::~Bimpre(){
    delete [] bht;
}