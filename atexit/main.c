#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t start, end;

void cleanup(void);

int main(void) {
    int age;

    time(&start); // Get the current time
    atexit(cleanup); // Register cleanup function, which will be called when the program exits
    printf("Enter your age:");
    scanf_s("%d", &age);
    printf("You are %d years old\n", age);
    return 0;
}

void cleanup(void) {
    time(&end);
    printf("The program ran for %.2f seconds\n", difftime(end, start));
}