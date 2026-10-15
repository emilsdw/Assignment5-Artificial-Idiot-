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
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        result += line;
        result += '\n';            
    }

    return result;
}


set<char> 
Reader::alphabet(const string& text){
    set<char> alphabet;
    for (char c : text){
        alphabet.insert(c);
    }
    return alphabet;
    }








