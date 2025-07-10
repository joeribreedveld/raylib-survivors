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
    Rectangle dest = {projectile->position.x, projectile->position.y,
                      projectile->size.x * gameScale,
                      projectile->size.y * gameScale};

    Vector2 origin = {(dest.width / 2.0f), (dest.height / 2.0f)};

    float rotation = Vector2AngleValue(projectile->velocity) * RAD2DEG + 90.0f;

    DrawTexturePro(game->tileset, game->projectileManager->sourceRect, dest,
                   origin, rotation, WHITE);
}

void SetProjectile(Projectile *projectile, Vector2 position,
                   Vector2 direction) {
    projectile->active = true;
    projectile->position = position;
    projectile->lifetime = projectileLifetime;

    projectile->velocity = Vector2Scale(direction, projectileSpeed);
}