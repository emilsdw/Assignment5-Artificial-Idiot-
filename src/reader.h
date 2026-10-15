#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;





class Reader{
    public:

    string text;
    string read(const string& filename);
};