//
// Created by Trong_Phuc on 18/11/2023.
//

#ifndef POINTER_SHAPE_H
#define POINTER_SHAPE_H


typedef struct Shape {
    float (*computeArea)(const struct Shape *shape);
} Shape;

extern float Shape_computeArea(const Shape *shape);


#endif //POINTER_SHAPE_H
