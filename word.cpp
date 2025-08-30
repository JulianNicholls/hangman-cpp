#include "word.h"

bool Word::guess(char ch)
{
    if (in_word(ch) && !good(ch))
    {
        good_letters.push_back(ch);
        return true;
    }
    else if (!bad(ch))
    {
        bad_letters.push_back(ch);
    }

    return false;
}
