#include "projectile.h"

#include <stdlib.h>

#include "raymath.h"
#include "utils.h"

void InitProjectile(Projectile *projectile) {
    projectile->velocity = Vector2Zero();
    projectile->position = Vector2Zero();
    projectile->active = false;
    projectile->size = (Vector2){projectileWidth, projectileHeight};
}

void UpdateProjectile(Projectile *projectile) {
    if (!projectile->active) return;

    projectile->position =
        Vector2Add(projectile->position, projectile->velocity);

    /* Lifetime */
    projectile->lifetime -= GetFrameTime();

    if (projectile->lifetime <= 0) {
        projectile->active = false;
    }
}

void DrawProjectile(Projectile *projectile) {
    if (!projectile->active) return;

    DrawRectangle(projectile->position.x - projectile->size.x / 2,
                  projectile->position.y - projectile->size.y / 2,
                  projectile->size.x, projectile->size.y, RED);
}

void SetProjectile(Projectile *projectile, Vector2 position,
                   Vector2 direction) {
    projectile->active = true;
    projectile->position = position;
    projectile->lifetime = projectileLifetime;

    projectile->velocity = GetDeltaVelocity(direction, projectileSpeed);
}