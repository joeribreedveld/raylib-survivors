#include "player.h"

#include <stdlib.h>

#include "raymath.h"
#include "utils.h"

Player *InitPlayer() {
    Player *player = malloc(sizeof(Player));

    player->position = Vector2Zero();

    player->velocity = Vector2Zero();

    return player;
}

void UpdatePlayer(Player *player) {
    Vector2 direction = Vector2Zero();

    if (IsKeyDown(KEY_W)) direction.y -= 1;
    if (IsKeyDown(KEY_A)) direction.x -= 1;
    if (IsKeyDown(KEY_S)) direction.y += 1;
    if (IsKeyDown(KEY_D)) direction.x += 1;

    player->position =
        Vector2Add(player->position, GetDeltaVelocity(direction, playerSpeed));
}

void DrawPlayer(Player *player) {
    DrawRectangle((int)player->position.x, (int)player->position.y, playerWidth,
                  playerHeight, WHITE);
}

void UnloadPlayer(Player *player) { free(player); }