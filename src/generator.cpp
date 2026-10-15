#include "generator.h"
#include "reader.h"

#include <random>
#include <vector>
#include <stdexcept>

using namespace std;


map<string, map<char, int>> 
Generator::next_char_counter(const string& text, int k){
    
    //Error handling:    
    if (k <= 0) {
        throw invalid_argument ("K must be positve");
    }
    if (text.size() <= static_cast<size_t>(k)){                     //size_t is a unsigned integer type, here its used because the size of a string cant be negative. 
        throw invalid_argument ("Training text is to short");
    }


    map<string, map<char, int>> counts;

    for(size_t i = 0; i < text.size() - k; i++){
        string word = text.substr(i,k);                            //creates a new string, substr(pos, length).
        char next = text[i + k]; 

        counts[word][next] ++;                                    //first key is word, second key is the char, then ++ increases that value by 1. So it counts how many times a specific word is followed by a specific char !!!
    }
    return counts;
}

map<char, float> Generator::prob(
        const map<string, map<char, int>>& counts,
        const string& w,  
        float alpha,
        const set<char>& alphabet){


            


            int nw = 0;
            if(counts.count(w) > 0){
                for(const auto& element : counts.at(w)){
                    nw += element.second;
                }
            }
            map<char, float> prob;
            float prob_wc;

            for(const auto& bokstav : alphabet){  
                char c = bokstav;
                
                int nwc = 0;
                if(counts.count(w) > 0 ){

                    const auto& following = counts.at(w);
                    if(following.count(c) > 0){
                        nwc = following.at(c);
                    }
                }



                prob_wc = (nwc + alpha) / (nw + alpha * alphabet.size());

                prob[c] = prob_wc; 
            }

            return prob; 
        }


string 
Generator::generate_new_word(const string& text, int k, float alpha, int length, set<char> alphabet) {
    
    //Error handling:
    if (!(alpha > 0)) {
        throw invalid_argument("Alpha must be positive");
    }

    if (length < 0) {
        throw invalid_argument("Length cannot be negative");
    }

 
    auto counts = next_char_counter(text, k);


   
    string w = text.substr(0, k);
    string result = w;

    //random number generator
    mt19937 engine(random_device{}());

    for (int i = 0; i < length; ++i) {
        auto probabilities = prob(counts, w, alpha, alphabet);

        vector<char> characters;
        vector<double> weights;

        for (const auto& entry : probabilities) {
            characters.push_back(entry.first);
            weights.push_back(entry.second);
        }

        //picks one weight randomly based on their probability
        discrete_distribution<int> choose(
            weights.begin(), weights.end()
        );

        char c = characters[choose(engine)];

        result += c;

        // Remove the first character and append the new one.
        w = w.substr(1) + c;
    }

    return result;
}


