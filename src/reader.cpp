#include "reader.h"







string Reader::read(const string& filename){
    ifstream file(filename);
    
    if (!file.is_open()){
        cerr << "Can't open the file!" << endl;
    };
    
    string text;
    string line;


    while(getline(file,line)){
        text += line;               
    }

    return text;
}


map<string, map<char, float>> Reader::weight_counter(int k){        

    
}

/*
Need to implement for to calculate weights and put them into the map for each char for each k-gram.
Might be smart to split it into two functions, one for calcualting one for putting into map. (Doent sound smart now that I think about it)
*/