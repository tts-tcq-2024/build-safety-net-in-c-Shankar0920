#include <stdio.h>
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c)
{
    static const char soundexCodes[26] = {'0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'};
    return soundexCodes[toupper(c) - 'A'];
}
 
char eliminateZeroAndRepeatedValue(char prevcode, char* soundex, size_t i, const char* name)
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
    size_t len = strlen(soundex);
    while (len < 4)
    {
        soundex[len] = '0';
        len++;
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
        prevCode = eliminateZeroAndRepeatedValue(prevCode, soundex, i, name);
        i++;
    }
    padSoundex(soundex);
}
