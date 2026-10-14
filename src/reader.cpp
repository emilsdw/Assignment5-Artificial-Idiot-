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

    //Need one loop that goes through every letter in the text and one that goes through every k gram, 


    string text;
    map<string, map<char, float>> weights;
    int kmax;

    for(int i = 2; i < kmax; i++){
        for (int j = 0; i < static_cast<int>(text.size()); i++){

            //formula for calculating weight

            

        }

    }
}

/*
Need to implement for to calculate weights and put them into the map for each char for each k-gram.
Might be smart to split it into two functions, one for calcualting one for putting into map. (Doent sound smart now that I think about it)
*/