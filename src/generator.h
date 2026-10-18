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
        //Count how often c follow w
        map<string, map<char, int>> next_char_counter(const string& text, int k);
        //Calculates the probability P(w,c) for each c in the input alphabet.           
        map<char, float> prob(                                                               
            const map<string, map<char, int>> & counts,
            const string& w,  
            float alpha,
            const set<char>& alphabet
        );

};