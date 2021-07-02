//
// Created by sam on 26/6/21.
//

#include "Vector2f.h"
#include <iostream>

// vector2 float
Vector2f::Vector2f() {
    this->x = 0.0f;
    this->y = 0.0f;
}

Vector2f::Vector2f(float x, float y) {
    this->x = x;
    this->y = y;
}

void Vector2f::zero() {
    this->x = 0.0f;
    this->y = 0.0f;
}

Vector2f Vector2f::add(const Vector2f vector) {
    this->x += vector.x;
    this->y += vector.y;
    return *this;
}
