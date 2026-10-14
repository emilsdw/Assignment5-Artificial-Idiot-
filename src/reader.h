#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;





class Reader{
    public:
    
    string read(const string& filename);
    map<string, map<char, float>> weight_counter(int k);



    
};