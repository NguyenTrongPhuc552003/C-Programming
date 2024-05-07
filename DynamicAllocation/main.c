#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

typedef struct {
    int r;
} Circle;

void enterCircle(Circle* c) {
    printf("Enter the radius of the circle: ");
    scanf_s("%d", &c->r);
}

double areaCircle(Circle* c) {
    return PI * c->r * c->r;
}

typedef struct {
    int w;
    int h;
} Rectangle;

void enterRectangle(Rectangle* r) {
    printf("Enter the width of the rectangle: ");
    scanf_s("%d", &r->w);
    printf("Enter the height of the rectangle: ");
    scanf_s("%d", &r->h);
}

int areaRectangle(Rectangle* r) {
    return r->w * r->h;
}

void initShapes(void**, int); // prototype (declaration of the function initShapes)

void changeShapes(void**, int); // prototype (declaration of the function changeShapes)

void printShapes(void**, int); // prototype (declaration of the function printShapes)

void freeShapes(void**, int); // prototype (declaration of the function freeShapes)

int main(void) {
    void* shapes[5]; // 2 circles and 3 rectangles
    int n = sizeof(shapes) / sizeof(void*); // 5

    initShapes(shapes, n); // initialize the shapes
    changeShapes(shapes, n); // change the shapes
    printShapes(shapes, n); // print the shapes
    freeShapes(shapes, n); // free the shapes

    system("pause");
    return 0;
}

void initShapes(void** shapes, int n) {
    int order = 0; // order of the shape

    // enter the radius of the first circle and the width and height of the first rectangle
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { // circle
            shapes[i] = malloc(2 * sizeof(Circle));
            for (Circle* c = shapes[i]; c < (Circle*)shapes[i] + 2; c++) { // the amount of circles is 2
                printf("Shape %d.%d/\n", i + 1, ++order);
                enterCircle(c);
            }
        } else { // rectangle
            shapes[i] = malloc(3 * sizeof(Rectangle));
            for (Rectangle* r = shapes[i]; r < (Rectangle*)shapes[i] + 3; r++) { // the amount of rectangles is 3
                printf("Shape %d.%d/\n", i + 1, ++order);
                enterRectangle(r);
            }
        }
        order = 0;
    }
}

void changeShapes(void** shapes, int n) {
    int order; // order of the shape

    printf("Reallocating memory...\n");
    for (int i = 0; i < n; i++) { // reallocate the memory with each of the shapes is 5
        if (i % 2 == 0) {
            order = 2;
            shapes[i] = realloc(shapes[i], 5 * sizeof(Circle));
            for (Circle* c = (Circle*)shapes[i] + 2; c < (Circle*)shapes[i] + 5; c++) { // enter the radius of the next circle
                printf("Shape %d.%d/\n", i + 1, ++order);
                enterCircle(c);
            }
        } else {
            order = 3;
            shapes[i] = realloc(shapes[i], 5 * sizeof(Rectangle));
            for (Rectangle* r = (Rectangle*)shapes[i] + 3; r < (Rectangle*)shapes[i] + 5; r++) { // enter the width and height of the next rectangle
                printf("Shape %d.%d/\n", i + 1, ++order);
                enterRectangle(r);
            }
        }
    }
}

void printShapes(void** shapes, int n) {
    // print the area of each shape
    for (int i = 0; i < n; i++) {
        printf("%d/ The area of ", i + 1);
        if (i % 2 == 0) {
            printf("circle:\n");
            for (int j = 0; j < 5; j++) { // the amount of circles is 5
                printf("- %d: %f\n", j + 1, areaCircle((Circle*)shapes[i] + j));
            }
        } else {
            printf("rectangle:\n");
            for (int j = 0; j < 5; j++) { // the amount of rectangles is 5
                printf("- %d: %d\n", j + 1, areaRectangle((Rectangle*)shapes[i] + j));
            }
        }
    }
}

void freeShapes(void** shapes, int n) {
    for (int i = 0; i < n; i++) {
        free(shapes[i]);
    }
}