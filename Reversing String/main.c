#include <stdio.h>

char * reversing_string(char * string);

int main() {
    char * str = "Nguyen Trong Phuc";
    printf("Reversed string: %s", reversing_string(str));
}

char * reversing_string(char * string) { // abcde => edcba: odd_number | abcd => dcba: even_number
    if (*string == '\0') return NULL;

    size_t start = 0, end = 0;
    while (string[end] != '\0') end++;
    end--;

    while (start < end) {
        string[start] ^= string[end];
        string[end]   ^= string[start];
        string[start] ^= string[end];
        ++start;
        --end;
    }
    return string;
}