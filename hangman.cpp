#include <format>
#include <iostream>

#include "word.h"
#include "wordlist.h"

int main()
{
    Wordlist words("words-2019.txt");

    std::cout << "Hangman V1.0\n\n";
    std::cout << std::format("Words: {}\n", words.size());

    const std::string temp = words.random();
    Word word(temp);
    std::cout << std::format("\n{}: {}\n", temp, word);
    ;
}
