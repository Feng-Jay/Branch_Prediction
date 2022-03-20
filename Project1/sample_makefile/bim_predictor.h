#ifndef _BIM_PRE_
#define _BIM_PRE_

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
// #include <sstream>
using std:: cout; using std::endl;
using std::istream; using std::string;

class Bimpre{

public:
    int m;
    unsigned int mask;
    int * bht;
    int total_num;
    int right;
    int wrong;
    Bimpre();
    Bimpre(int m);
    void simulate(istream& infile);
    ~Bimpre();
};



#endif