#include "utils.h"

char * to_upper(char * string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 'a' - 'A';
        }
    }
    return string;
}