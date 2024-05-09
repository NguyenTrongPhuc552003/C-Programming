#include <stdio.h>

int main(void) {
    /*Left shift with n-bit*/
    int a = 0x00000001; // 1
    a <<= 1; // multiply by 2 (2^1)
    printf("Left shift with n-bit\n");
    printf("a = %d\n", a);
    printf("a = a << 1 = %d\n", a);

    /*Right shift with n-bit*/
    int b = 0x00000008; // 8
    b >>= 1; // divide by 2 (2^1)
    printf("\nRight shift with n-bit\n");
    printf("b = %d\n", b);
    printf("b = b >> 1 = %d\n", b);

    /*And operator*/
    int c = 0x0000000F; // 15
    int d = 0x0000000A; // 10
    int e = c & d; // 0x0000000A (0b00001010) & 0x0000000F (0b00001111) = 0x0000000A (0b00001010)
    printf("\nAnd operator\n");
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("e = c & d = %d\n", e);

    /*Or operator*/
    c = 0x0000000F; // 15
    d = 0x0000000A; // 10
    e = c | d; // 0x0000000A (0b00001010) | 0x0000000F (0b00001111) = 0x0000000F (0b00001111)
    printf("\nOr operator\n");
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("e = c | d = %d\n", e);

    /*Xor operator*/
    c = 0x0000000F; // 15
    d = 0x0000000A; // 10
    e = c ^ d; // 0x0000000A (0b00001010) ^ 0x0000000F (0b00001111) = 0x00000005 (0b00000101)
    printf("\nXor operator\n");
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("e = c ^ d = %d\n", e);

    /*Not operator*/
    d = 0x0000000F; // 15
    e = ~d; // 0x0000000F (0b00001111) = 0xFFFFFFF0 (0b11110000)
    printf("\nNot operator\n");
    printf("d = %d\n", d);
    printf("e = ~d = %d\n", e);
    return 0;
}
