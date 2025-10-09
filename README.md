# Hangman in C++

My goto project when I'm learning a new language. Actually, I learnt C++ over 30 years ago, 
but C++ and I have moved on a lot in that time.

So, here in 2025, I'm learning C++20 (it would be C++23, but I'm on a Mac with XCode not 
even supporting all of C++20).

I'm embracing the old and the new:

- Tmux - I've tried to get into this a few times, but I now have a real handle on it.
- NeoVim - I learnt vi more than 40 years ago, but NeoVim has re-ignited my interest.
- Lazygit - What a great Git front-end.

## Word list

This has now been updated to use a word list constructed from
Kevin Atkinson's [wordlist page](http://wordlist.sourceforge.net/).
I have included the whole copyright file that comes with the download, since
all the component word lists have ultimately been placed in the public domain,
but there are a number of different statements of copyright contained. Clearly,
I am deeply in Kevin's debt for the word list and acknowledge the sterling work
that he has done.

The wordlist that I have chosen to construct from his files is:

- Level 60, with...
- English and British up to variant 1.
- No abbreviations, proper names, Roman numerals, and hacker words.
- Word lengths 5 to 16.

## Build

It is built using cmake

Clone the repository

`cd` into the `build` directory, and run

`cmake ..
cmake - build .`

et voila.

## latest state

The hanged entity is now a robot. The text has colours now, including the robot.
New word list.
