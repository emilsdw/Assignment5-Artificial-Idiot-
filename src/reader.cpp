#include "reader.h"

string 
Reader::read(const string& filename){
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





