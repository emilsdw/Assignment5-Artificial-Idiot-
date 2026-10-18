#include "reader.h"
#include "generator.h"
#include <exception>

using namespace std;





int main(int argc, char* argv[]){

    
    Reader reader;
    Generator generator;

    float alpha;
    int k_gram_size;
    string text;
    int number_of_new_characters;


    if (argc != 4 && argc != 6) {
        cerr << "Usage: " << argv[0]
            << " <-a> <alpha> <k> <training_file> <length>" << endl;
        return 1;
    }


    if (argc == 6) {
        if (string(argv[1]) != "-a") {
            cerr << "Expected -a before the alpha value" << endl;
            return 1;
        }

        alpha = stof(argv[2]);
        k_gram_size = stoi(argv[3]);
        text = reader.read(argv[4]);
        number_of_new_characters = stoi(argv[5]);
    }
    else {
        alpha = 0.0;
        k_gram_size = stoi(argv[1]);
        text = reader.read(argv[2]);
        number_of_new_characters = stoi(argv[3]);
    }


    set<char> alphabet = reader.alphabet(text);
    
    


    string generated = generator.generate_new_word(text, 
        k_gram_size, 
        alpha, 
        number_of_new_characters, 
        alphabet);

    cout << "Training text size: " << text.size() << '\n';
    cout << "Generated size: " << generated.size() << '\n';
    cout << "Generated: [" << generated << "]\n";

    return 0;
}


int main(int argc, char* argv[]) {
    try {
        Reader reader;
        Generator generator;

        float alpha;
        int k_gram_size;
        string text;
        int number_of_new_characters;


        if (argc != 4 && argc != 6) {
            cerr << "Usage: " << argv[0]
                << " <-a> <alpha> <k> <training_file> <length>" << endl;
            return 1;
        }


        if (argc == 6) {
            if (string(argv[1]) != "-a") {
                cerr << "Expected -a before the alpha value" << endl;
                return 1;
            }

            alpha = stof(argv[2]);
            k_gram_size = stoi(argv[3]);
            text = reader.read(argv[4]);
            number_of_new_characters = stoi(argv[5]);
        }
        else {
            alpha = 0.0;
            k_gram_size = stoi(argv[1]);
            text = reader.read(argv[2]);
            number_of_new_characters = stoi(argv[3]);
        }


        set<char> alphabet = reader.alphabet(text);
        
        


        string generated = generator.generate_new_word(text, 
            k_gram_size, 
            alpha, 
            number_of_new_characters, 
            alphabet);

        cout << "Generated: "<< generated << endl;
        return 0;
    }
    catch (const std::exception& error) {
        std::cerr << "slm: " << error.what() << '\n';
        return 1;
    }
}