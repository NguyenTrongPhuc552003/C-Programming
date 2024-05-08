#include <stdio.h>
#include <string.h>

int main(void) {
    // memset(dst, value, size): set the first size bytes of dst to value
    char str[50] = "Hello, World!";
    printf("Before memset(): %s\n", str);
    memset(str, 'A', 7); // set the first 7 bytes to 'A'
    printf("After memset(): %s\n", str);

    // memcpy(dst, src, size): copy size bytes from src to dst
    char src[50] = "Hello, World!";
    char dest[50];
    printf("Before memcpy(): %s\n", dest);
    memcpy(dest, src, strlen(src) + 1); // copy the whole string, including the null terminator
    printf("After memcpy(): %s\n", dest);
    return 0;
}
