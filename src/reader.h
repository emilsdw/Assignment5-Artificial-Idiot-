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
    
    string read(const string& filename);                                                //function to read a file and save it as a string 

    map<string, map<char, int>> next_char_counter(const string& text, int k);            //function to count how often c follow w

    float prob(
        const map<string, map<char, int>> & counts,
        const string& w, 
        char c, 
        float alpha,
        int alphabet_size
    );

    
};