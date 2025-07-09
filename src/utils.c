#include "utils.h"

float GetRandomDirection() { return DEG2RAD * GetRandomValue(0, 15) * 22.5f; }

Rectangle RectangleFromTopLeft(Vector2 position, Vector2 size) {
    return (Rectangle){position.x, position.y, size.x, size.y};
}