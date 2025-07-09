#include "utils.h"

#include "raymath.h"

Vector2 Vector2DeltaVelocity(Vector2 direction, int speed) {
    return Vector2Scale(Vector2Normalize(direction), speed * GetFrameTime());
}

Vector2 Vector2RandomNormalized() {
    return Vector2Rotate((Vector2){1, 0}, GetRandomValue(0, 359));
}

Rectangle RectangleFromTopLeft(Vector2 position, Vector2 size) {
    return (Rectangle){position.x, position.y, size.x, size.y};
}

float Vector2AngleValue(Vector2 vector) {
    return atan2f(vector.y, vector.x) * RAD2DEG;
}