#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "raylib.h"

static const int enemyWidth = 20;
static const int enemyHeight = 20;
static const int enemySpeed = 50;
static const int enemyHP = 2;

typedef struct Enemy {
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
    float hp;
    bool active;
} Enemy;

void InitEnemy(Enemy *enemy);

void UpdateEnemy(Enemy *enemy, Player *player);

void DrawEnemy(Enemy *enemy, Game *game);

void SetEnemy(Enemy *enemy, Vector2 position);

#endif