#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Soundex.h"

char getSoundexCode(char c)
{
    static const char soundexCodes[26] = {'0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'};
    return soundexCodes[toupper(c) - 'A'];
}

char eliminateZeroandRepeatedValue (char prevcode, char* soundex, size_t i, const char* name)
{
    char code = getSoundexCode(name[i]);
    if (code != '0' && code != prevcode)
    {
        soundex[i - 1] = code;
        prevcode = code;
    }
    return prevcode;
}
void initializeSoundex(char* soundex, char firstChar)
{
    soundex[0] = toupper(firstChar);
}
void padSoundex(char* soundex)
{
    size_t i = strlen(soundex);
    if (name[0] == '\0')
    {
        soundex[0] = '\0'; // Empty string case
        return;
    }
    while (i < 4)
    {
        soundex[i] = '0';
        i++;
    }
    soundex[4] = '\0'; // Ensure soundex is null-terminated
}
void generateSoundex(const char* name, char* soundex)
{
   
    initializeSoundex(soundex, name[0]);
    char prevCode = getSoundexCode(name[0]);
    size_t i = 1;
    while (name[i] != '\0' && i < 4)
    {
        prevCode = eliminateZeroandRepeatedValue(prevCode, soundex, i, name);
        i++;
    }

    padSoundex(soundex);
}
#endif
