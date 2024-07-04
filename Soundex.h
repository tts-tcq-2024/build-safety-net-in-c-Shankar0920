#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0';
}
 
