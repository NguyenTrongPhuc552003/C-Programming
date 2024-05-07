#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct Student {
    char name[20];
    int age;
    int score;
};

typedef struct Student student; // typedef: define a new type

typedef struct {
    int *array;
} data;

void printStudent(student* s) {
    printf_s("Name: %s, Age: %d, Score: %d\n", s->name, s->age, s->score);
}

int main(void) {
    /*struct */student s[4] = { { "Tom", 20, 90 },
                                { "Jerry", 21, 80 },
                                { "Mickey", 22, 70 },
                                { .age = 23, .score = 85, .name = "Donald" } };
    /*struct */student s1, s2 = {
                                    .name = "Tom",
                                    .age = 20,
                                    .score = 90
                                };
    data d[5];

    strcpy_s(s1.name, sizeof(s1.name), "StrongFood");
    printf_s("s1's Name: %s\n", s1.name);
    printf_s("s2's Name: %s\n", s2.name);
    for (/*struct */student *p = s; p < s + 4; p++) {
//        printf_s("Name: %s, Age: %d, Score: %d\n", p->name, p->age, p->score);
        printStudent(p);
    }

    for (data *p = d; p < d + 5; p++) {
        p->array = (int*)calloc(10, sizeof(int));
        printf_s("Address: %p ( ", p->array);
        for (int i = 0; i < 10; i++) {
            printf_s("%d ", p->array[i]);
        }
        printf_s(")\n");
        free(p->array);
    }
    return 0;
}
