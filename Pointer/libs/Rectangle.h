//
// Created by Trong_Phuc on 18/11/2023.
//

#ifndef POINTER_RECTANGLE_H
#define POINTER_RECTANGLE_H


#include "Shape.h"

typedef struct Rectangle {
    struct Shape shape;
    float width, height;
} Rectangle;

extern float Rectangle_computeArea(const Shape *shape);

extern void Rectangle_createRectangle(struct Rectangle *rectangle);

extern void Rectangle_setLength(struct Rectangle *rectangle, float width, float height);


#endif //POINTER_RECTANGLE_H
