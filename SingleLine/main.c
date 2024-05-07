#include <stdio.h>

int main() {
    char s[100];

    printf_s("Enter your name here:");
    scanf("%[^\n]", s);
    printf_s("Your name is %s\n", s);
    return 0;
}
