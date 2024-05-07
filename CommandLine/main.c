#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { // compile -> run with arguments (ex: ./a.out arg1 arg2)
    for (int i = 0; i < argc; i++) printf("argv[%d] = %s\n", i, argv[i]);

    if (argc != 3) {
        printf("Usage: %s <lower> <upper>\n", argv[0]);
        return 1;
    }
    int lower = atoi(argv[1]);
    int upper = atoi(argv[2]);
    for (int i = lower; i <= upper; i++) printf("%d\n", i);
    return 0;
}
