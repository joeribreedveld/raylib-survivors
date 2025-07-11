#include "enemy.h"

#include <stdlib.h>

#include "raymath.h"

void InitEnemy(Enemy *enemy)
{
    enemy->velocity = Vector2Zero();
    enemy->position = Vector2Zero();
    enemy->active = false;
    enemy->hp = enemyHP;
    enemy->size = (Vector2){enemyWidth, enemyHeight};
}

void UpdateEnemy(Enemy *enemy, Player *player)
{
    /* Get angle between player and enemy */
    Vector2 playerToEnemy = Vector2Subtract(player->position, enemy->position);
    Vector2 enemyDirection = Vector2Normalize(playerToEnemy);

    /* Move enemy velocity towards player */
    enemy->velocity = Vector2Scale(enemyDirection, enemySpeed);

    /* Apply velocity */
    enemy->position = Vector2Add(enemy->position,
                                 Vector2Scale(enemy->velocity, GetFrameTime()));
}

void DrawEnemy(Enemy *enemy)
{
    Rectangle rectangle = {enemy->position.x, enemy->position.y, enemy->size.x,
                           enemy->size.y};

    Vector2 origin = {enemy->size.x / 2.0f, enemy->size.y / 2.0f};

    DrawRectanglePro(rectangle, origin, 0.0f, GREEN);
}

void SetEnemy(Enemy *enemy, Vector2 position)
{
    enemy->active = true;
    enemy->position = position;
    enemy->hp = enemyHP;

    enemy->velocity = Vector2Scale((Vector2){1, 0}, enemySpeed);
}