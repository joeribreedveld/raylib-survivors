#include "utils.h"

#include <math.h>

float GetRandomDirection()
{
    return DEG2RAD * GetRandomValue(0, 359);
}

Rectangle RectangleFromTopLeft(Vector2 position, Vector2 size)
{
    return (Rectangle){position.x, position.y, size.x, size.y};
}

Rectangle RectangleFromCenter(Vector2 center, Vector2 size)
{
    return (Rectangle){center.x - size.x / 2, center.y - size.y / 2, size.x,
                       size.y};
}

float Vector2AngleValue(Vector2 vector)
{
    return atan2f(vector.y, vector.x);
}
