

#include "enemy_manager.h"

#include <stdlib.h>

#include "raymath.h"
#include "utils.h"

EnemyManager *InitEnemyManager() {
    EnemyManager *enemyManager = malloc(sizeof(EnemyManager));

    enemyManager->spawnTimer = 0.0f;

    for (int i = 0; i < MAX_ENEMIES; i++) {
        InitEnemy(&enemyManager->enemies[i]);
    }

    return enemyManager;
}

void UpdateEnemyManager(EnemyManager *enemyManager, Player *player) {
    enemyManager->spawnTimer += GetFrameTime();

    if (enemyManager->spawnTimer >= enemySpawnInterval) {
        enemyManager->spawnTimer = 0.0f;

        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (!enemyManager->enemies[i].active) {
                /* Enemy origin middle of player */
                Vector2 playerCenter = Vector2Add(
                    player->position,
                    (Vector2){player->size.x / 2.0f, player->size.y / 2.0f});

                /* Random position on spawn radius */
                /* TODO: Enemy direction still same 16 as projectile movement */
                Vector2 enemyOffset = Vector2Scale(
                    Vector2Rotate((Vector2){1, 0}, GetRandomDirection()),
                    enemySpawnRadius);

                SetEnemy(&enemyManager->enemies[i],
                         Vector2Add(playerCenter, enemyOffset));

                break;
            }
        }
    }

    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemyManager->enemies[i].hp <= 0)
            enemyManager->enemies[i].active = false;

        if (enemyManager->enemies[i].active) {
            UpdateEnemy(&enemyManager->enemies[i], player);
        }
    }
}

void DrawEnemyManager(EnemyManager *enemyManager) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemyManager->enemies[i].active) {
            DrawEnemy(&enemyManager->enemies[i]);
        }
    }
}

void UnloadEnemyManager(EnemyManager *enemyManager) { free(enemyManager); }
