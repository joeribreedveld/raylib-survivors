#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "projectile_manager.h"
#include "raylib.h"

typedef struct Game {
    Camera2D camera;
    Player *player;
    ProjectileManager *projectileManager;
} Game;

Game *InitGame();

void UpdateGame(Game *game);

void DrawGame(Game *game);

void UnloadGame(Game *game);

#endif