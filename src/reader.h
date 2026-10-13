#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;





class Reader{
    private:
    ifstream file();
    public:
    
    string read(const string& filename);

};