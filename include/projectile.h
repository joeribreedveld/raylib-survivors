#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "raylib.h"

static const int projectileWidth = 8;
static const int projectileHeight = 16;
static const int projectileSpeed = 400;

typedef struct Projectile {
    Vector2 position;
    Vector2 velocity;
    bool active;
    float lifetime;
} Projectile;

Projectile *InitProjectile();

void UpdateProjectile(Projectile *projectile);

void DrawProjectile(Projectile *projectile);

void ShootProjectile(Projectile *projectile, Vector2 position,
                     Vector2 velocity);

void UnloadProjectile(Projectile *projectile);

#endif