#include <stdio.h>
#include <stdarg.h>

// Function to print variable number of arguments
void print(int num, ...); // Prototype, "..." is used to specify variable number of arguments

int main(void) {
    print(3, 1, 2, 3);
    return 0;
}

void print(int num, ...) {
    va_list args; // Variable argument list
    va_start(args, num); // Initialize the argument list
    for (int i = 0; i < num; i++) {
        printf("%d\n", va_arg(args, int)); // Get the next argument
    }
    va_end(args); // End the argument list
}