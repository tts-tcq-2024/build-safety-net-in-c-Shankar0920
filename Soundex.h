#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to get the Soundex code for a character
char getSoundexCode(char c) {
    static const char soundexCodes[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5',
        '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    return soundexCodes[toupper(c) - 'A' ];
}

// Function to eliminate zero and repeated values in Soundex code
char eliminateZeroAndRepeatedValue(char prevcode, char* soundex, size_t i, const char* name) {
    char code = getSoundexCode(name[i]);
    if (code != '0' && code != prevcode) {
        soundex[strlen(soundex)] = code;
        prevcode = code;
    }
    return prevcode;
}

// Function to initialize Soundex code with the first character of the name
void initializeSoundex(char* soundex, char firstChar) {
    soundex[0] = toupper(firstChar);
}

// Function to pad Soundex code to 4 characters
void padSoundex(char* soundex) {
    size_t len = strlen(soundex);
    while (len < 4) {
        soundex[len++] = '0';
    }
    soundex[4] = '\0';
}

// Function to generate Soundex code for a given name
void generateSoundex(const char* name, char* soundex) {
   
    initializeSoundex(soundex, name[0]); // Initialize soundex with the first character of name
    char prevCode = getSoundexCode(name[0]); // Get Soundex code for the first character

    size_t i = 1;
    while (name[i] != '\0' && i < 4) {
        prevCode = eliminateZeroAndRepeatedValue(prevCode, soundex, i, name);
        i++;
    }
    padSoundex(soundex);
}
