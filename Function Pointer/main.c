#include <stdio.h>
#include <string.h>

// Defining a structure
typedef struct {
    char info[50]; // Information of the person
    int exp; // Experience of the person
} Person;

// Input and Output information of the person
void enter(Person*, int);
void display(Person*, int);

// Show message
void show(char*);

// Math functions
int sum(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

// Introduction
char* intro(char*, int);

int main(void) {
    // Advantage of using function pointers is that we can store the address of a function in a variable and use it later
    // Disadvantage is that it makes the code harder to read and understand
    void (*e[])(Person*, int) = {enter, display}; // Array of function pointers, e[0] points to enter, e[1] points to display
    void (*p)(char*) = show; // Function pointer, p points to show (Function pointer to a function that takes a pointer to a character as an argument)
    int (*s)(int, int) = sum; // Function pointer, s points to sum (Function pointer to a function that takes two integers as arguments)
    char* (*i)(char*, int) = intro; // Function pointer, i points to intro (Function pointer to a function that takes a pointer to a character and an integer as arguments)
    int (*m[])(int, int) = {sum, sub, mul, div}; // Array of function pointers, m[0] points to sum, m[1] points to sub, m[2] points to mul, m[3] points to div
    void (*arr[]) = {show, sum, intro}; // Array of function pointers, arr[0] points to show, arr[1] points to sum, arr[2] points to intro

    Person per[3]; // Array of Person structures
    int n = sizeof(per) / sizeof(per[0]); // Number of elements in the array
    (*e[0])(per, n); // Enter information of the person
    (*e[1])(per, n); // Display information of the person

    // Using the function pointers
    p("Hello, World!");
    printf("Sum: %d\n", s(1, 2));
    printf("%s\n", i("John", 25));

    // Using the array of function pointers
    for (int j = 0; j < 4; j++) {
        switch (j) {
            case 0:
                printf("Sum: %d\n", (*m[j])(1, 2));
                break;
            case 1:
                printf("Sub: %d", (*m[j])(1, 2));
                break;
            case 2:
                printf("Mul: %d", (*m[j])(1, 2));
                break;
            default:
                printf("Div: %d", (*m[j])(1, 2));
        }
    }

    // Using the function pointers stored in the array
    ((void (*)(char*))arr[0])("Hello, World!");
    printf("Sum: %d\n", ((int (*)(int, int))arr[1])(1, 2));
    printf("%s\n", ((char* (*)(char*, int))arr[2])("John", 25));
    return 0;
}

void enter(Person* p, int n) {
    char name[20];
    int age;
    for (int i = 0; i < n; i++) {
        printf("Enter your name:");
        gets_s(name, sizeof(name));
        printf("Enter your age:");
        scanf_s("%d", &age);
        strcpy_s(p[i].info, sizeof(p[i].info), intro(name, age));
        printf("Enter your experience:");
        scanf_s("%d", &p[i].exp);
        getchar();
    }
}

void display(Person* p, int n) {
    for (int i = 0; i < n; i++) {
        printf("- Person %d\n", i + 1);
        printf("  + Info: %s\n", p[i].info);
        printf("  + Experience: %d\n", p[i].exp);
    }
}

void show(char* msg) {
    printf("%s\n", msg);
}

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

char* intro(char* name, int age) {
    char* msg = "My info is %s and I am %d years old.\n";
    sprintf(msg, name, age);
    return msg;
}