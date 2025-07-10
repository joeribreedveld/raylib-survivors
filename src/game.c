#include "game.h"

#include <stdlib.h>

#include "enemy_manager.h"
#include "player.h"
#include "projectile_manager.h"
#include "utils.h"

Game *InitGame() {
    Game *game = malloc(sizeof(Game));

    game->player = InitPlayer();

    game->projectileManager = InitProjectileManager();

    game->enemyManager = InitEnemyManager();

    game->camera.zoom = 1.0f;

    game->camera.offset = (Vector2){(GetScreenWidth() - playerWidth) / 2.0f,
                                    (GetScreenHeight() - playerHeight) / 2.0f};

    game->camera.target =
        (Vector2){game->player->position.x, game->player->position.y};

    return game;
}

void UpdateGame(Game *game) {
    UpdatePlayer(game->player);

    UpdateProjectileManager(game->projectileManager, game->player);

    UpdateEnemyManager(game->enemyManager, game->player);

    game->camera.target =
        (Vector2){(int)game->player->position.x, (int)game->player->position.y};

    /* Collisions */
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!game->enemyManager->enemies[i].active) continue;

        for (int j = 0; j < MAX_PROJECTILES; j++) {
            if (!game->projectileManager->projectiles[j].active) continue;

            if (CheckCollisionRecs(
                    RectangleFromTopLeft(
                        game->enemyManager->enemies[i].position,
                        game->enemyManager->enemies[i].size),
                    RectangleFromTopLeft(
                        game->projectileManager->projectiles[j].position,
                        game->projectileManager->projectiles[j].size))) {
                game->enemyManager->enemies[i].hp -= 1;
                game->projectileManager->projectiles[j].active = false;
            }
        }
    }
}

void DrawGame(Game *game) {
    BeginDrawing();

    ClearBackground(BLACK);

    BeginMode2D(game->camera);

    DrawRectangle(10, 10, 100, 100, YELLOW);

    DrawProjectileManager(game->projectileManager);

    DrawEnemyManager(game->enemyManager);

    DrawPlayer(game->player);

    EndMode2D();

    EndDrawing();
}

void UnloadGame(Game *game) {
    UnloadPlayer(game->player);

    UnloadProjectileManager(game->projectileManager);

    UnloadEnemyManager(game->enemyManager);

    free(game);
}
