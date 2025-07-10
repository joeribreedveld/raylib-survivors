#include "player.h"

#include <stdlib.h>

#include "game.h"
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

void DrawPlayer(Game *game) {
    Rectangle dest = {
        (int)game->player->position.x, (int)game->player->position.y,
        game->player->size.x * gameScale, game->player->size.y * gameScale};

    Vector2 origin = {(dest.width / 2.0f), (dest.height / 2.0f)};

    float rotation = 0.0f;

    DrawTexturePro(game->tileset, game->player->sourceRect, dest, origin,
                   rotation, WHITE);
}

void UnloadPlayer(Player *player) { free(player); }