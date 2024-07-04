#include <stdio.h>
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    c = toupper(c);
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V') {
        return '1';
    } else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') {
        return '2';
    } else {
        return '3';
    }
}
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    char prevCode = getSoundexCode(name[0]);

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '3' && code != prevCode) {
            soundex[sIndex++] = code;
        }
        prevCode = code;
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

int main() {
    const char *name = "Soundex";
    char soundex[5];
    generateSoundex(name, soundex);
    printf("Soundex code for '%s' is '%s'\n", name, soundex);
    return 0;
}
