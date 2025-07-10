#include "enemy.h"

#include <stdlib.h>

#include "game.h"
#include "raymath.h"

void InitEnemy(Enemy *enemy) {
    enemy->velocity = Vector2Zero();
    enemy->position = Vector2Zero();
    enemy->active = false;
    enemy->hp = enemyHP;
    enemy->size = (Vector2){enemyWidth, enemyHeight};
}

void UpdateEnemy(Enemy *enemy, Player *player) {
    /* Get angle between player and enemy */
    Vector2 playerToEnemy = Vector2Subtract(player->position, enemy->position);
    Vector2 enemyDirection = Vector2Normalize(playerToEnemy);

    /* Move enemy velocity towards player */
    enemy->velocity = Vector2Scale(enemyDirection, enemySpeed);

    /* Apply velocity */
    enemy->position = Vector2Add(enemy->position,
                                 Vector2Scale(enemy->velocity, GetFrameTime()));
}

void DrawEnemy(Enemy *enemy, Game *game) {
    Rectangle dest = {enemy->position.x, enemy->position.y,
                      enemy->size.x * gameScale, enemy->size.y * gameScale};

    Vector2 origin = {(dest.width / 2.0f), (dest.height / 2.0f)};

    float rotation = 0.0f;

    DrawTexturePro(game->tileset, game->enemyManager->sourceRect, dest, origin,
                   rotation, WHITE);
}

void SetEnemy(Enemy *enemy, Vector2 position) {
    enemy->active = true;
    enemy->position = position;
    enemy->hp = enemyHP;

    enemy->velocity = Vector2Scale((Vector2){1, 0}, enemySpeed);
}