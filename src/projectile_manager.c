

#include "projectile_manager.h"

#include <stdlib.h>

#include "enemy_manager.h"
#include "game.h"
#include "projectile.h"
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
        float closestDistance = projectileViewRadius * projectileViewRadius;

        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (!enemyManager->enemies[i].active) continue;

            float distance = Vector2DistanceSqr(
                player->position, enemyManager->enemies[i].position);

            if (distance < closestDistance &&
                distance <= projectileViewRadius * projectileViewRadius) {
                closestDistance = distance;
                enemy = &enemyManager->enemies[i];
            }
        }

        if (enemy) {
            Vector2 direction = Vector2Normalize(
                Vector2Subtract(enemy->position, player->position));

            for (int i = 0; i < MAX_PROJECTILES; i++) {
                if (!projectileManager->projectiles[i].active) {
                    SetProjectile(&projectileManager->projectiles[i],
                                  player->position, direction);

                    break;
                }
            }
        }
    }

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (projectileManager->projectiles[i].piercing <= 0) {
            projectileManager->projectiles[i].active = false;
            projectileManager->projectiles[i].piercing = projectilePiercing;
        }

        if (projectileManager->projectiles[i].active) {
            UpdateProjectile(&projectileManager->projectiles[i]);
        }
    }
}

void DrawProjectileManager(Game *game) {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (game->projectileManager->projectiles[i].active) {
            DrawProjectile(&game->projectileManager->projectiles[i], game);
        }
    }
}

void UnloadProjectileManager(ProjectileManager *projectileManager) {
    free(projectileManager);
}
