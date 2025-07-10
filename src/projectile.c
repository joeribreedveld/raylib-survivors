#include "projectile.h"

#include <stdlib.h>

#include "game.h"
#include "raymath.h"
#include "utils.h"

void InitProjectile(Projectile *projectile) {
    projectile->velocity = Vector2Zero();
    projectile->position = Vector2Zero();
    projectile->active = false;
    projectile->size = (Vector2){projectileWidth, projectileHeight};
    projectile->angle = 0.0f;
    projectile->piercing = projectilePiercing;
}

void UpdateProjectile(Projectile *projectile) {
    projectile->position =
        Vector2Add(projectile->position,
                   Vector2Scale(projectile->velocity, GetFrameTime()));

    projectile->lifetime -= GetFrameTime();

    if (projectile->lifetime <= 0) {
        projectile->active = false;
    }
}

void DrawProjectile(Projectile *projectile, Game *game) {
    float rotation = projectile->angle * RAD2DEG + 90.0f;

    Rectangle rectangle = {projectile->position.x, projectile->position.y,
                           projectile->size.x, projectile->size.y};

    Vector2 origin = {projectile->size.x / 2.0f, projectile->size.y / 2.0f};

    DrawRectanglePro(rectangle, origin, rotation, RED);
}

void SetProjectile(Projectile *projectile, Vector2 position,
                   Vector2 direction) {
    projectile->active = true;
    projectile->position = position;
    projectile->lifetime = projectileLifetime;

    projectile->velocity = Vector2Scale(direction, projectileSpeed);
    projectile->angle = Vector2AngleValue(direction);
}