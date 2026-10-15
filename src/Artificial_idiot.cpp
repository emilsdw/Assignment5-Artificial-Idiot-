#include "reader.h"
#include "generator.h"

using namespace std;

/*
k-grams = words of size k

**Generating:**
- sample starting word (w)
- Use next-char-distribution to sample next char c
- w = w[1...k] + c //new "current" word

need:

- 2 classes
    - "reader" that read input and compute frequencies
    - "generator": current word and iterates (w = w[1...k] + c //new "current" word)




- Reader class:
    - one reader function that takes in the file and returns a string 
    - map  in map
        -first map is for every k-gram. The input is the k-gram and the output is another map
            -second map is for each k-gram, here the input is the letter and the output is the weight for that letter.





std::substr = creates a new string that is a copy of a section of the original string
*/




int main(int argc, char* argv[]){

    Reader reader;
    Generator generator;




    float alpha = 0.1;
    int number_of_new_characters = stoi(argv[3]);
    string text = reader.read(argv[2]);

    set<char> alphabet = reader.alphabet(text);
    int k_gram_size = stoi(argv[1]);
    


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
