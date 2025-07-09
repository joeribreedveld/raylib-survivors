#include "projectile.h"

#include <stdlib.h>

#include "raymath.h"
#include "utils.h"

void InitProjectile(Projectile *projectile) {
    projectile->velocity = Vector2Zero();
    projectile->position = Vector2Zero();
    projectile->active = false;
    projectile->size = (Vector2){projectileWidth, projectileHeight};
    projectile->angle = 0;
}

void UpdateProjectile(Projectile *projectile) {
    projectile->position =
        Vector2Add(projectile->position, projectile->velocity);

    /* Lifetime */
    projectile->lifetime -= GetFrameTime();

    if (projectile->lifetime <= 0) {
        projectile->active = false;
    }
}

void DrawProjectile(Projectile *projectile) {
    DrawRectanglePro(
        (Rectangle){(int)projectile->position.x, (int)projectile->position.y,
                    projectile->size.x, projectile->size.y},
        (Vector2){projectile->size.x / 2.0f, projectile->size.y / 2.0f},
        projectile->angle, RED);
}

void SetProjectile(Projectile *projectile, Vector2 position,
                   Vector2 direction) {
    projectile->active = true;
    projectile->position = position;
    projectile->lifetime = projectileLifetime;

    projectile->velocity = Vector2DeltaVelocity(direction, projectileSpeed);
    projectile->angle = Vector2AngleValue(projectile->velocity);
}