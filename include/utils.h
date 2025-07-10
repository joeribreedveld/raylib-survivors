#ifndef UTILS_H
#define UTILS_H

#include "raylib.h"

float GetRandomDirection();

Rectangle RectangleFromTopLeft(Vector2 position, Vector2 size);

Rectangle RectangleFromCenter(Vector2 center, Vector2 size);

float Vector2AngleValue(Vector2 vector);

#endif