#include "reader.h"
#include "generator.h"
#include <exception>
#include <stdexcept>

using namespace std;








int main(int argc, char* argv[]) {
    try {
        Reader reader;
        Generator generator;

        float alpha;
        int k_gram_size;
        string text;
        int number_of_new_characters;


        

        if (argc != 4 && argc != 6) {
            throw invalid_argument(
                "Usage: slm [-a alpha] <k> <training_file> <length>"
            );
        }



        size_t pos;

        if (argc == 6) {
            if (string(argv[1]) != "-a") {
                throw invalid_argument("Unknown option: expected -a");
            }

            alpha = stof(argv[2], &pos);
            if (pos != string(argv[2]).size()) {
                throw invalid_argument("Alpha must be a number");
            }

            k_gram_size = stoi(argv[3], &pos);
            if (pos != string(argv[3]).size()) {
                throw invalid_argument("K must be an integer");
            }

            number_of_new_characters = stoi(argv[5], &pos);
            if (pos != string(argv[5]).size()) {
                throw invalid_argument("Output length must be an integer");
            }

            text = reader.read(argv[4]);
        }
        else {
            alpha = 0.0;

            k_gram_size = stoi(argv[1], &pos);
            if (pos != string(argv[1]).size()) {
                throw invalid_argument("K must be an integer");
            }

            number_of_new_characters = stoi(argv[3], &pos);
            if (pos != string(argv[3]).size()) {
                throw invalid_argument("Output length must be an integer");
            }

            text = reader.read(argv[2]);
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