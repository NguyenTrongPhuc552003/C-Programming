#include <stdio.h>

char *remove_char(char [], char); /*Nguyen Trong Phuc remove 'n' => Nguye Tong Phuc*/

int main() {
    char str[] = "Nguyen Trong Phuc";
    printf("Result: %s\n", remove_char(str, 'n'));
    return 0;
}

char *remove_char(char str[], char rm) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == rm) {
            for (int j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            i--;
        }
    }
    return str;
}