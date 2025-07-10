#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H

#include "enemy_manager.h"
#include "player.h"
#include "projectile.h"

#define MAX_PROJECTILES 50

static const float fireInterval = 0.3;
static const float projectileViewRadius = 300;

typedef struct ProjectileManager {
    Projectile projectiles[MAX_PROJECTILES];
    Rectangle sourceRect;
    float fireTimer;
} ProjectileManager;

ProjectileManager *InitProjectileManager();

void UpdateProjectileManager(ProjectileManager *projectileManager,
                             Player *player, EnemyManager *enemyManager);

void DrawProjectileManager(Game *game);

void UnloadProjectileManager(ProjectileManager *projectileManager);

#endif