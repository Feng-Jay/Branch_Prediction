#ifndef _G_SHARE_
#define _G_SHARE_

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using std::cout; using std::endl;
using std::ifstream; using std::string;

class Gshare{
public:
    int totalnum;
    int right;
    int wrong;
    int m; int n;
    int maskatt;
    int maskn;
    unsigned int gbhr;
    int * bht;
    Gshare();
    Gshare(int m, int n);
    void simulate(ifstream& infile);
    ~Gshare();
};




#endif