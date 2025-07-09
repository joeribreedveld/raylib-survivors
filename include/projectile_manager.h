#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H

#include "player.h"
#include "projectile.h"

#define MAX_PROJECTILES 50

static const float shootInterval = 0.5;

typedef struct ProjectileManager {
    Projectile projectiles[MAX_PROJECTILES];
    float shootTimer;
} ProjectileManager;

ProjectileManager *InitProjectileManager();

void UpdateProjectileManager(ProjectileManager *projectileManager,
                             Player *player);

void DrawProjectileManager(ProjectileManager *projectileManager);

void UnloadProjectileManager(ProjectileManager *projectileManager);

#endif