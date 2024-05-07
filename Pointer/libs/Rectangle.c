//
// Created by Trong_Phuc on 18/11/2023.
//

#include "Rectangle.h"

float Rectangle_computeArea(const Shape *shape) {
    const struct Rectangle *rectangle = (const struct Rectangle *) shape;
    return rectangle->width * rectangle->height;
}

void Rectangle_createRectangle(struct Rectangle *rectangle) {
    rectangle->width = rectangle->width = 0.F;
    rectangle->shape.computeArea = Shape_computeArea;
}

void Rectangle_setLength(struct Rectangle *rectangle, float width, const float height) {
    Rectangle_createRectangle(rectangle);
    rectangle->width = width;
    rectangle->height = height;
}