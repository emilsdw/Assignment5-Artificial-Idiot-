#include "reader.h"

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






    return 0;
}
