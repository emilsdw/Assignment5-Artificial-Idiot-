#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>


class Generator{


    map<string, map<char, int>> next_char_counter(const string& text, int k);            //function to count how often c follow w

    map<char, float> prob(                                                              //function that calculates the probability P(w,c) for each c in the input alphabet. 
        const map<string, map<char, int>> & counts,
        const string& w,  
        float alpha,
        const set<char>& alphabet
    );

};