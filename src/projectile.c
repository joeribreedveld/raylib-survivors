#include "projectile.h"

#include <stdlib.h>

#include "raymath.h"
#include "utils.h"

Projectile *InitProjectile(Vector2 position) {
    Projectile *projectile = malloc(sizeof(Projectile));

    projectile->position = position;

    projectile->velocity = GetDeltaVelocity((Vector2){0, -1}, projectileSpeed);

    return projectile;
}

void UpdateProjectile(Projectile *projectile) {
    projectile->position =
        Vector2Add(projectile->position, projectile->velocity);
}

void DrawProjectile(Projectile *projectile) {
    DrawRectangle(projectile->position.x, projectile->position.y,
                  projectileWidth, projectileHeight, RED);
}

void UnloadProjectile(Projectile *projectile) { free(projectile); }
