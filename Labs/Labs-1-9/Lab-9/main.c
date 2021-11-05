#include <ctype.h>
#include <stdio.h>
void main() {
    // Why 1000? Because in this fucking
    // language we must specify char* size
    // but we don't know it, because it may
    // be literally any size. So we put
    // here random big number. Why using +1
    // later? Because we must pass it
    // to size for null-terminator. Why?
    // Try to ask Satan - maybe, he knows.
    const unsigned length = 1000; 
    char text[length + 1];
    printf("Input text: ");
    // Oh my God! What this holy shit is?
    // Ah, yes, we need it. Why? Maybe,
    // because scanf is a piece of shit,
    // like whole C, is not it?
    scanf("%[^\n]%*c", text);

    // Here we can't use split, because
    // fucking char* has no such function.
    // We also can't use strtok function,
    // because by much fucking more stupid
    // task we must save separators. So we
    // will loop through text character by
    // character and add it to new (empty)
    // text variable. Thx fucking ONPU with
    // it's shitty teachers and the worst
    // programming language for algorithms
    // called "C" for making us doing this
    // bastard task. With God.

    char result_text[length * 2 + 1];
    unsigned index = 0;
    unsigned even_word = 0;
    unsigned odd_space = 1;
    for (unsigned i = 0; i < length; ++i) {
        char character = text[i];
        if (isspace(character) && (i == length - 1  || !isspace(text[i + 1]))) {
            if (odd_space) {
                result_text[index] = character;
                index++;
            }
            odd_space = !odd_space;
            even_word = !even_word;
            result_text[index] = character;
            index++;
        } else if (!ispunct(character)) {
            result_text[index] = character;
            index++;
            if (even_word && !isspace(text[i + 1]) && !ispunct(text[i + 1])) {
                result_text[index] = '_';
                index++;
            }
        }
    }

    printf("Result text: \"%s\"", result_text);

    printf("\n");
}
