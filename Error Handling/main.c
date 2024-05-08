#include <stdio.h>
#include <string.h>
#include <errno.h>

extern int errno; // Defined in errno.h

int main(void) {
    FILE *fptr;
    printf("Error number before: %d\n", errno); // Defined in errno.h
    fopen_s(&fptr, "c:\\nonexistantfile.txt", "r");
    if (fptr == NULL) {
        printf("Error number now: %d (%s)\n", errno, strerror(errno)); // Defined in stdio.h, prints error message
//        perror("Error message: "); // Defined in stdio.h, prints error message
    } else {
        fclose(fptr);
    }
    return 0;
}
