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

char algorithmCheck(char prevcode, char* soundex, size_t i, const char* name)
{
   char code = getSoundexCode(name[i]);
   if (code != '0' && code != prevcode)
    {
        soundex[strlen(soundex)] = code;
        prevcode = code;
    } 
    return prevcode;
}

char calculateSoundex(const char* name, char* soundex)
{
    if (name[0] == '\0') return '\0';

    soundex[0] = toupper(name[0]);
    char prevCode = getSoundexCode(name[0]);

    size_t i = 1;
    while (name[i] != '\0' && strlen(soundex) < 4)
    {
        prevCode = algorithmCheck(prevCode, soundex, i, name);
        i++;
    }

   
    return prevCode;
}

void generateSoundex(const char* name, char* result)
{
    char soundex = "";
    soundex = calculateSoundex(name, soundex);
     while (strlen(soundex) < 4)
    {
        soundex[strlen(soundex)] = '0';
    }
    strcpy(result, soundex);
}

#endif 
