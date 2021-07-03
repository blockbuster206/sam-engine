//
// Created by sam on 26/6/21.
//

#include <iostream>

#ifndef SAM_ENGINE_VECTOR2_H
#define SAM_ENGINE_VECTOR2_H

class Vector2f {
    public:
        float x;
        float y;

        Vector2f();
        Vector2f(float x, float y);

        void zero();

        Vector2f add(const Vector2f vector);
        Vector2f subtract(const Vector2f vector);
        Vector2f multiply(const Vector2f vector);
        Vector2f divide(const Vector2f vector);
};

#endif //SAM_ENGINE_VECTOR2_H
