#pragma once

struct Vector2f
{
    Vector2f();
    Vector2f(float x, float y);
    void getPosition() const;

    float mX, mY;
};
