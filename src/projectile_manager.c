

#include "projectile_manager.h"

#include <stdlib.h>

#include "raymath.h"

ProjectileManager *InitProjectileManager() {
    ProjectileManager *projectileManager = malloc(sizeof(ProjectileManager));

    projectileManager->shootTimer = 0;

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        InitProjectile(&projectileManager->projectiles[i]);
    }

    return projectileManager;
}

void UpdateProjectileManager(ProjectileManager *projectileManager,
                             Player *player) {
    projectileManager->shootTimer += GetFrameTime();

    if (projectileManager->shootTimer >= shootInterval) {
        projectileManager->shootTimer = 0;

        for (int i = 0; i < MAX_PROJECTILES; i++) {
            if (!projectileManager->projectiles[i].active) {
                SetProjectile(
                    &projectileManager->projectiles[i],
                    Vector2Add(player->position, (Vector2){player->size.x / 2,
                                                           player->size.y / 2}),
                    (Vector2){0, -1});

                break;
            }
        }
    }

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        UpdateProjectile(&projectileManager->projectiles[i]);
    }
}

void DrawProjectileManager(ProjectileManager *projectileManager) {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        DrawProjectile(&projectileManager->projectiles[i]);
    }
}

void UnloadProjectileManager(ProjectileManager *projectileManager) {
    free(projectileManager);
}
