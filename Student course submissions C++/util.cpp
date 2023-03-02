//
// Created by nick on 2/28/2023.
//

#include "util.h"

string Util::toLower(string input)
{
    //will be assigned to each character of the string
    char letter;
    for (int letterIndex = 0; letterIndex < input.length(); letterIndex++)
    {
        //take each letter and use it against the library function toLower.
        letter = input[letterIndex];
        input[letterIndex] = tolower(letter);
    }

    //return lower cased string
    return input;
}

