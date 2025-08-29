#include <format>
#include <iostream>

#include "wordlist.h"

int main()
{
    Wordlist words("words-2019.txt");

    std::cout << "Hangman V1.0\n\n";
    std::cout << std::format("Words: {}\n", words.size());
}
