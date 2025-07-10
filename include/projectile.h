#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "raylib.h"

typedef struct Game Game;

static const int projectileWidth = 8;
static const int projectileHeight = 16;
static const int projectileSpeed = 750;
static const int projectileLifetime = 3;
static const int projectilePiercing = 2;

typedef struct Projectile {
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
    float lifetime;
    float angle;
    bool active;
    int piercing;
} Projectile;

void InitProjectile(Projectile *projectile);

void UpdateProjectile(Projectile *projectile);

void DrawProjectile(Projectile *projectile, Game *game);

void SetProjectile(Projectile *projectile, Vector2 position, Vector2 direction);

#endif