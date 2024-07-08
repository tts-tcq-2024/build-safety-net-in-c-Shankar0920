#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Soundex.h"

char getSoundexCode(char c) {
    c = toupper(c);
        /* A, B, C, ..., Z */
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5',
        '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    int index = c - 'A'; 
    if (index >= 0 && index < 26) {
        return soundexCodes[index];
    } 
    else {
        return '0';
    }
}

char algorithmCheck(char prevcode, char* soundex, size_t index, const char* name) {
    char code = getSoundexCode(name[index]);
    if (code != '0' && code != prevcode) {
        soundex[strlen(soundex)] = code;
    }
    return code;
}
char soundexCode(const char* name, char* soundex, char prevcode)
{
    for (size_t i = 1; i < strlen(name) && strlen(soundex) < 4; ++i)
    {
        prevcode = algorithmCheck(prevcode, soundex, i, name);
    }
    return prevcode;
}

void generateSoundex(const char* name, char* soundex)
{
    if (strlen(name) == 0)
    {
        soundex[0] = '\0';
        return;
    }

    soundex[0] = toupper(name[0]);
    char prevCode = getSoundexCode(name[0]);

    prevCode = soundexCode(name, soundex, prevCode);

    while (strlen(soundex) < 4)
    {
        soundex[strlen(soundex)] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
