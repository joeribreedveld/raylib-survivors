#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "projectile.h"
#include "raylib.h"

#define MAX_PROJECTILES 50

static const float shootInterval = 0.5;

typedef struct Game {
    Projectile *projectiles[MAX_PROJECTILES];
    Camera2D camera;
    Player *player;
    float projectileShootTimer;
} Game;

Game *InitGame();

void UpdateGame(Game *game);

void DrawGame(Game *game);

void UnloadGame(Game *game);

#endif