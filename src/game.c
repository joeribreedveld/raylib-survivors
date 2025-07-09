#include "game.h"

#include <stdlib.h>

#include "player.h"
#include "projectile_manager.h"

Game *InitGame() {
    Game *game = malloc(sizeof(Game));

    game->player = InitPlayer();

    game->projectileManager = InitProjectileManager();

    game->camera.zoom = 1;

    game->camera.offset = (Vector2){(GetScreenWidth() - playerWidth) / 2.0f,
                                    (GetScreenHeight() - playerHeight) / 2.0f};

    game->camera.target =
        (Vector2){game->player->position.x, game->player->position.y};

    return game;
}

void UpdateGame(Game *game) {
    game->camera.target =
        (Vector2){(int)game->player->position.x, (int)game->player->position.y};

    UpdatePlayer(game->player);

    UpdateProjectileManager(game->projectileManager, game->player);
}

void DrawGame(Game *game) {
    BeginDrawing();

    ClearBackground(BLACK);

    BeginMode2D(game->camera);

    DrawRectangle(10, 10, 100, 100, YELLOW);

    DrawProjectileManager(game->projectileManager);

    DrawPlayer(game->player);

    EndMode2D();

    EndDrawing();
}

void UnloadGame(Game *game) {
    UnloadPlayer(game->player);

    UnloadProjectileManager(game->projectileManager);

    free(game);
}
