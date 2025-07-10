#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Game Game;

static const int playerWidth = 16;
static const int playerHeight = 16;
static const int playerSpeed = 150;

typedef struct Player {
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
} Player;

Player *InitPlayer();

void UpdatePlayer(Player *player);

void DrawPlayer(Player *player);

void UnloadPlayer(Player *player);

#endif