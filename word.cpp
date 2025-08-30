#include "word.h"

bool Word::guess(char ltr)
{
    if (in_word(ltr))
    {
        guessed_letters.push_back(ltr);
        return true;
    }

    return false;
}
