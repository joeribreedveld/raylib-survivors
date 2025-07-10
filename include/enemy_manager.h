#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "enemy.h"

#define MAX_ENEMIES 200

static const float enemySpawnInterval = 0.35f;
static const int enemySpawnRadius = 400;

struct Game;

typedef struct EnemyManager {
    Enemy enemies[MAX_ENEMIES];
    float spawnTimer;
} EnemyManager;

EnemyManager *InitEnemyManager();

void UpdateEnemyManager(EnemyManager *enemyManager, Player *player);

void DrawEnemyManager(Game *game);

void UnloadEnemyManager(EnemyManager *enemyManager);

#endif