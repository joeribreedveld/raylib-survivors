#include "utils.h"

#include "raymath.h"

Vector2 GetDeltaVelocity(Vector2 direction, int speed) {
    return Vector2Scale(Vector2Normalize(direction), speed * GetFrameTime());
}