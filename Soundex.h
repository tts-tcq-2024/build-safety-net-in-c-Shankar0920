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
    if (name[0] == '\0')
    {
        result = "";
    }
    char soundex[5] = "";
    char soundex_1[5] = "";
    soundex_1[5] = calculateSoundex(name, soundex);
     while (strlen(soundex_1) < 4)
    {
        soundex[strlen(soundex_1)] = '0';
    }
    strcpy(result, soundex_1);
}

#endif 
