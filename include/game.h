#ifndef GAME_H
#define GAME_H

#include "enemy_manager.h"
#include "player.h"
#include "projectile_manager.h"
#include "raylib.h"

static const float gameScale = 2.0f;

typedef struct Game {
    Camera2D camera;
    Player *player;
    ProjectileManager *projectileManager;
    EnemyManager *enemyManager;
    Texture2D tileset;
    Rectangle flagSourceRect;
} Game;

Game *InitGame();

void UpdateGame(Game *game);

void DrawGame(Game *game);

void UnloadGame(Game *game);

#endif