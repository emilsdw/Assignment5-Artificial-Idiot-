#include "reader.h"







string 
Reader::read(const string& filename)
    {
    ifstream file(filename);
    
    if (!file.is_open()){
        cerr << "Can't open the file!" << endl;
    };
    
    string text;
    string line;


    while(getline(file,line)){
        text += line;
        text += '\n';            
    }

    return text;
}


map<string, map<char, float>> 
Reader::next_char_counter(const string& text, int k)
    {
        
    //Error handling:    
    if (k <= 0) {
        throw invalid_argument ("K must be positve");
    }
    if (text.size() <= static_cast<size_t>(k)){                     //size_t is a unsigned integer type, here its used because the size of a string cant be negative. 
        throw invalid_argument ("Training text is to short");
    }


    map<string, map<char, float>> counts;

    for(size_t i = 0; i < text.size() - k; i++){
        string word = text.substr(i,k);                            //creates a new string, substr(pos, length).
        char next = text[i + k]; 

        counts[word][next] ++;                                    //first key is word, second key is the char, then ++ increases that value by 1. So it counts how many times a specific word is followed by a specific char !!!
    }
    return counts;
}
