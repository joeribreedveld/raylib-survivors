

#include "projectile_manager.h"

#include <stdlib.h>

#include "enemy_manager.h"
#include "raymath.h"

ProjectileManager *InitProjectileManager() {
    ProjectileManager *projectileManager = malloc(sizeof(ProjectileManager));

    projectileManager->fireTimer = 0.0f;

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        InitProjectile(&projectileManager->projectiles[i]);
    }

    return projectileManager;
}

void UpdateProjectileManager(ProjectileManager *projectileManager,
                             Player *player, EnemyManager *enemyManager) {
    projectileManager->fireTimer += GetFrameTime();

    /* Trigger fire */
    if (projectileManager->fireTimer >= fireInterval) {
        projectileManager->fireTimer = 0.0f;

        /* Find nearest enemy */
        Enemy *enemy = NULL;
        float closestDistance = enemySpawnRadius * enemySpawnRadius;

        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (!enemyManager->enemies[i].active) continue;

            float distance = Vector2DistanceSqr(
                player->position, enemyManager->enemies[i].position);

            if (distance < closestDistance) {
                closestDistance = distance;
                enemy = &enemyManager->enemies[i];
            }
        }

        if (enemy) {
            Vector2 direction = Vector2Normalize(
                Vector2Subtract(enemy->position, player->position));

            for (int i = 0; i < MAX_PROJECTILES; i++) {
                if (!projectileManager->projectiles[i].active) {
                    Vector2 playerCenter = Vector2Add(
                        player->position, (Vector2){player->size.x / 2.0f,
                                                    player->size.y / 2.0f});

                    SetProjectile(&projectileManager->projectiles[i],
                                  playerCenter, direction);

                    break;
                }
            }
        }
    }

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (projectileManager->projectiles[i].active) {
            UpdateProjectile(&projectileManager->projectiles[i]);
        }
    }
}

void DrawProjectileManager(ProjectileManager *projectileManager) {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (projectileManager->projectiles[i].active) {
            DrawProjectile(&projectileManager->projectiles[i]);
        }
    }
}

void UnloadProjectileManager(ProjectileManager *projectileManager) {
    free(projectileManager);
}
