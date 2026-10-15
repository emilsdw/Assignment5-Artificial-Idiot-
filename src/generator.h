#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>


using namespace std;


class Generator{
    public:
        string generate_new_word(const string& text, int k, float alpha, int length, set<char> alphabet);


    private: 
        map<string, map<char, int>> next_char_counter(const string& text, int k);            //function to count how often c follow w

        map<char, float> prob(                                                              //function that calculates the probability P(w,c) for each c in the input alphabet. 
            const map<string, map<char, int>> & counts,
            const string& w,  
            float alpha,
            const set<char>& alphabet
        );

};