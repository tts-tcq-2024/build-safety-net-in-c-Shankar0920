#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to get Soundex code for a character
char getSoundexCode(char c) {
    static const char soundexCodes[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5',
        '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    return soundexCodes[toupper(c) - 'A'];
}

// Function to eliminate zeros and repeated values
char eliminateZeroAndRepeatedValue(char prevcode, char* soundex, size_t i, const char* name) {
    char code = getSoundexCode(name[i]);
    if (code != '0' && code != prevcode) {
        soundex[i - 1] = code; // Store the Soundex code in the correct position
        prevcode = code; // Update prevcode to current code
    }
    return prevcode; // Return updated prevcode
}

// Function to initialize Soundex with the first character of the name
void initializeSoundex(char* soundex, char firstChar) {
    soundex[0] = toupper(firstChar); // Convert firstChar to uppercase and store it in soundex[0]
}

// Function to pad Soundex with zeros to ensure it's 4 characters long
void padSoundex(char* soundex) {
    size_t len = strlen(soundex); // Get current length of soundex
    while (len < 4) {
        soundex[len++] = '0'; // Add zeros until soundex has length 4
    }
    soundex[4] = '\0'; // Ensure soundex is null-terminated
}

// Function to generate Soundex code for a name
void generateSoundex(const char* name, char* soundex) {
    initializeSoundex(soundex, name[0]); // Initialize soundex with the first character of name
    char prevCode = getSoundexCode(name[0]); // Get Soundex code for the first character

    size_t i = 1;
    while (name[i] != '\0' && i < 4) {
        prevCode = eliminateZeroAndRepeatedValue(prevCode, soundex, i, name); // Process each subsequent character
        i++;
    }
    padSoundex(soundex); // Ensure soundex is exactly 4 characters long
}
