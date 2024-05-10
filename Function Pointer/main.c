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

// Function pointer to a function that takes two integers as arguments and returns an integer
int answer(int (*)(int, int));

// Temperature conversion, function pointers, and array of function pointers
int celsius(int);
int fahrenheit(int);
int kelvin(int);
void convert(int (*[])(int));

int main(void) {
    /* Advantage of using function pointers is that we can store the address of a function in a variable and use it later
     * Disadvantage is that it makes the code harder to read and understand, especially for beginners
     * Function pointers are used in callback functions, event handling, and dynamic loading of libraries
     * Function pointers can be used to create an array of function pointers, which can be used to store multiple functions
     * */
    void  (*e[])(Person*, int) = {enter, display}; // Array of function pointers, e[0] points to enter, e[1] points to display
    void  (*p)(char*)          = show; // Function pointer, p points to show (Function pointer to a function that takes a pointer to a character as an argument)
    int   (*s)(int, int)       = sum; // Function pointer, s points to sum (Function pointer to a function that takes two integers as arguments)
    char* (*i)(char*, int)     = intro; // Function pointer, 'i' points to intro (Function pointer to a function that takes a pointer to a character and an integer as arguments)
    int   (*m[])(int, int)     = {sum, sub, mul, div}; // Array of function pointers, m[0] points to sum, m[1] points to sub, m[2] points to mul, m[3] points to div
    void  (*a[])               = {show, sum, intro}; // Array of function pointers, a[0] points to show, a[1] points to sum, a[2] points to intro
    int   (*c[])(int)          = {celsius, fahrenheit, kelvin}; // Array of function pointers, c[0] points to Celsius, c[1] points to Fahrenheit, c[2] points to kelvin

    Person per[2]; // Array of Person structures
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
    ((void (*)(char*))a[0])("Hello, World!");
    printf("Sum: %d\n", ((int (*)(int, int))a[1])(1, 2));
    printf("%s\n", ((char* (*)(char*, int))a[2])("John", 25));

    // Using the function pointer as an argument
    while (1) {
        int choice;
        printf("Enter your choice:\n");
        printf("1. Sum\n");
        printf("2. Sub\n");
        printf("3. Mul\n");
        printf("4. Div\n");
        printf("5. Exit\n");
        printf("Your choice:");
        scanf_s("%d", &choice);
        if (choice == 5) break;
        printf("Answer: %d\n", answer(m[choice - 1]));
    }

    // Using the array of function pointers
    convert(c);
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

int answer(int (*f)(int, int)) {
    int a, b;
    printf("Enter your first number:");
    scanf_s("%d", &a);
    printf("Enter your second number:");
    scanf_s("%d", &b);
    return f(a, b);
}

int celsius(int temp) {
    return temp < 0;
}

int fahrenheit(int temp) {
    return temp < 32;
}

int kelvin(int temp) {
    return temp < 273;
}

void convert(int (*f[])(int)) {
    int temp, choice;
    do {
        printf("Select temperature threshold:\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");
        printf("Your choice:");
        scanf_s("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > 3);
    printf("Enter the temperature:");
    scanf_s("%d", &temp);
    if ((*f[choice - 1])(temp)) {
        printf("The temperature is below freezing point.\n");
    } else {
        printf("The temperature is above freezing point.\n");
    }
}