#include <stdio.h>

#include "libs/Rectangle.h"

int main() {
    Rectangle rectangle;
    const float width = 10.F;
    const float height = 20.F;

    Rectangle_setLength(&rectangle, width, height);
    printf("Area of rectangle: %f\n", Rectangle_computeArea(&rectangle.shape));
    return 0;
}
