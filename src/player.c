#include "player.h"

#include <stdlib.h>

#include "raymath.h"

Player *InitPlayer() {
    Player *player = malloc(sizeof(Player));

    player->position = Vector2Zero();

    player->velocity = Vector2Zero();

    player->size = (Vector2){playerWidth, playerHeight};

    return player;
}

void UpdatePlayer(Player *player) {
    Vector2 direction = Vector2Zero();

    if (IsKeyDown(KEY_W)) direction.y -= 1;
    if (IsKeyDown(KEY_A)) direction.x -= 1;
    if (IsKeyDown(KEY_S)) direction.y += 1;
    if (IsKeyDown(KEY_D)) direction.x += 1;

    if (direction.x != 0 && direction.y != 0) {
        direction = Vector2Normalize(direction);
    }

    player->position =
        Vector2Add(player->position,
                   Vector2Scale(direction, playerSpeed * GetFrameTime()));
}

void DrawPlayer(Player *player) {
    Rectangle rect = {(int)player->position.x, (int)player->position.y,
                      player->size.x, player->size.y};
    Vector2 origin = {player->size.x / 2.0f, player->size.y / 2.0f};
    DrawRectanglePro(rect, origin, 0.0f, WHITE);
}

void UnloadPlayer(Player *player) { free(player); }