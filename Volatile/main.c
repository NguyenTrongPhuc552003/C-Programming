#include <stdio.h>

int main (void) {
    const volatile int prepBuddy = 125;
    int *ptr = ( int* ) &prepBuddy;
    printf("The initial value of the prepBuddy is  : %d\n", prepBuddy);
    *ptr = 251;
    printf("The modified value of the prepBuddy is : %d\n", prepBuddy);
    return 0;
}