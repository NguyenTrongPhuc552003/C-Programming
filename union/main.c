#include <stdio.h>
#include <string.h>

// The key difference between struct and union is that in struct,
// each member has its own memory location, whereas in union, all
// members share the same memory location.
// So, the advantage of using union is that it reduces the memory
// required to store the data.

union data {
    int i;
    double f;
    char str[20];
};

struct info {
    int type;
    union data* d;
};

int main(void) {
    struct info inf;
    union data d;

    d.i = 10;
    d.f = 220.5;
    strcpy_s(d.str, sizeof(d.str), "C Programming");
    printf("d.i : %d\n", d.i); // The value of d.i is garbage value
    printf("d.f : %f\n", d.f); // The value of d.f is garbage value
    printf("d.str : %s\n", d.str); // The value of d.str is C Programming
    // The value of d.i and d.f is garbage value because the value of d.str,
    // it is the last assigned value (overwritten the previous value).

    // => The solution for this problem is to use only one member at a time.
    d.i = 10;
    printf("d.i : %d\n", d.i); // The value of d.i is 10

    d.f = 220.5;
    printf("d.f : %f\n", d.f); // The value of d.f is 220.500000

    strcpy_s(d.str, sizeof(d.str), "C Programming");
    printf("d.str : %s\n", d.str); // The value of d.str is C Programming

    // The size of a union is the size of its largest member.
    printf("Size of union data : %llu\n", sizeof(union data)); // 20

    inf.d = &d;
    inf.d->i = 12;
    printf("Enter your choice : ");
    scanf_s("%d", &inf.type);
    if (inf.type == 0) {
        printf("Enter an integer : ");
        scanf_s("%d", &inf.d->i);
        printf("inf.d->i = %d\n", inf.d->i);
    } else if (inf.type == 1) {
        printf("Enter a float : ");
        scanf_s("%lf", &inf.d->f);
        printf("inf.d->f = %f\n", inf.d->f);
    } else {
        memset(inf.d->str, 'a', sizeof(inf.d->str));
        printf("inf.d->str = %s\n", inf.d->str);
    }
    return 0;
}
