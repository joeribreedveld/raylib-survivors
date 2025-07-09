#include "projectile.h"

#include <stdlib.h>

#include "raymath.h"
#include "utils.h"

Projectile *InitProjectile() {
    Projectile *projectile = malloc(sizeof(Projectile));

    projectile->velocity = Vector2Zero();
    projectile->position = Vector2Zero();
    projectile->active = false;

    return projectile;
}

void UpdateProjectile(Projectile *projectile) {
    if (!projectile->active) return;

    projectile->position =
        Vector2Add(projectile->position, projectile->velocity);
}

void DrawProjectile(Projectile *projectile) {
    if (!projectile->active) return;

    DrawRectangle(projectile->position.x, projectile->position.y,
                  projectileWidth, projectileHeight, RED);
}

void ShootProjectile(Projectile *projectile, Vector2 position,
                     Vector2 direction) {
    projectile->active = true;
    projectile->position = position;
    projectile->velocity = GetDeltaVelocity(direction, projectileSpeed);
}

void UnloadProjectile(Projectile *projectile) { free(projectile); }
