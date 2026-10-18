#include "reader.h"
#include <stdexcept>


string Reader::read(const string& filename) {
    ifstream file(filename, ios::binary);

    if (!file) {
        throw runtime_error("Cannot open file '" + filename + "'");
    }

    string text;
    char character;

    while (file.get(character)) {
        text += character;
    }

    if (file.bad()) {
        throw runtime_error("Failed to read file '" + filename + "'");
    }

    return text;
}



set<char> Reader::alphabet(const string& text){
    set<char> alphabet;
    for (char c : text){
        alphabet.insert(c);
    }
    return alphabet;
    }








