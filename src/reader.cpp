#include "reader.h"

string 
Reader::read(const string& filename){
    ifstream file(filename);
    


    //need to change this error function
    if (!file.is_open()){
        cerr << "Can't open the file!" << endl;
    };
    
    string line;
    string result;


    while(getline(file,line)){
        result += line;
        result += '\n';            
    }

    text = result;
    return text;
}


set<char> 
Reader::alphabet(const string& text){
    set<char> alphabet;
    for (char c : text){
        alphabet.insert(c);
    }
    return alphabet;
    }








