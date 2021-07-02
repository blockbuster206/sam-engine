//
// Created by sam on 26/6/21.
//

#include <iostream>

#ifndef SAM_ENGINE_VECTOR2_H
#define SAM_ENGINE_VECTOR2_H

class Vector2i {

};

class Vector2f {
    public:
        Vector2f();
        Vector2f(float x, float y);

        void zero();

        Vector2f add(const Vector2f vector);
        void subtract(const Vector2f vector);
        void multiply(const Vector2f vector);
        void divide(const Vector2f vector);


        void addEqual(const Vector2f vector);
        void subtractEqual(const Vector2f vector);
        void multiplyEqual(const Vector2f vector);
        void divideEqual(const Vector2f vector);

    private:
        float x;
        float y;
};

#endif //SAM_ENGINE_VECTOR2_H
