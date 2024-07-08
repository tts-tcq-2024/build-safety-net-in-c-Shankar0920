#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Soundex.h"
char getSoundexCode(char c) {
    c = toupper(c);
    // Define a mapping from characters to their corresponding Soundex codes
    const char soundexCodes[] = {
        /* A, B, C, ..., Z */
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5',
        '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    // Calculate index for the character
    int index = c - 'A'; 
    // Check if the index is within valid range
    if (index >= 0 && index < 26) {
        return soundexCodes[index];
    } else {
        return '0'; // Default case for characters not handled
    }
}

void generateSoundex(const char* name, char* soundex) {
    if (strlen(name) == 0) {
        soundex[0] = '\0';
        return;
    }

    soundex[0] = toupper(name[0]);
    char prevCode = getSoundexCode(name[0]);

    prevCode = getStringCode(name, soundex, prevCode);

    while (strlen(soundex) < 4) {
        soundex[strlen(soundex)] = '0';
    }
    soundex[4] = '\0';
}
#endif // SOUNDEX_H
