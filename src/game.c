#include "game.h"

#include <stdlib.h>

#include "player.h"
#include "raymath.h"

Game *InitGame() {
    Game *game = malloc(sizeof(Game));

    game->player = InitPlayer();

    game->camera.zoom = 1.0f;
    game->projectileShootTimer = 0;

    game->camera.offset = (Vector2){(GetScreenWidth() - playerWidth) / 2.0f,
                                    (GetScreenHeight() - playerHeight) / 2.0f};

    game->camera.target =
        (Vector2){game->player->position.x, game->player->position.y};

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        game->projectiles[i] = InitProjectile();
    }

    return game;
}

void UpdateGame(Game *game) {
    UpdatePlayer(game->player);

    game->camera.target =
        (Vector2){(int)game->player->position.x, (int)game->player->position.y};

    /* Projectile */
    game->projectileShootTimer += GetFrameTime();

    if (game->projectileShootTimer >= shootInterval) {
        game->projectileShootTimer = 0;

        for (int i = 0; i < MAX_PROJECTILES; i++) {
            if (!game->projectiles[i]->active) {
                ShootProjectile(game->projectiles[i],
                                Vector2Add(game->player->position,
                                           (Vector2){game->player->size.x / 2,
                                                     game->player->size.y / 2}),
                                (Vector2){0, -1});

                break;
            }
        }
    }

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        UpdateProjectile(game->projectiles[i]);
    }
}

void DrawGame(Game *game) {
    BeginDrawing();

    ClearBackground(BLACK);

    BeginMode2D(game->camera);

    DrawRectangle(10, 10, 100, 100, YELLOW);

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        DrawProjectile(game->projectiles[i]);
    }

    DrawPlayer(game->player);

    EndMode2D();

    EndDrawing();
}

void UnloadGame(Game *game) {
    UnloadPlayer(game->player);

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        UnloadProjectile(game->projectiles[i]);
    }

    free(game);
}
