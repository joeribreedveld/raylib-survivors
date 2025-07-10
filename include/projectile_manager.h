#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H

#include "enemy_manager.h"
#include "player.h"
#include "projectile.h"

#define MAX_PROJECTILES 50

static const float fireInterval = 0.5;

typedef struct ProjectileManager {
    Projectile projectiles[MAX_PROJECTILES];
    float fireTimer;
} ProjectileManager;

ProjectileManager *InitProjectileManager();

void UpdateProjectileManager(ProjectileManager *projectileManager,
                             Player *player, EnemyManager *enemyManager);

void DrawProjectileManager(ProjectileManager *projectileManager);

void UnloadProjectileManager(ProjectileManager *projectileManager);

#endif