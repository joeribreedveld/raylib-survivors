#ifndef UTILS_H
#define UTILS_H

#include "raylib.h"

Vector2 Vector2DeltaVelocity(Vector2 direction, int speed);

Vector2 Vector2RandomNormalized();

float Vector2AngleValue(Vector2 vector);

#endif