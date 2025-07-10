#include "game.h"

#include <stdlib.h>

#include "utils.h"

Game *InitGame() {
    Game *game = malloc(sizeof(Game));

    game->player = InitPlayer();

    game->projectileManager = InitProjectileManager();

    game->enemyManager = InitEnemyManager();

    game->camera.zoom = 1.0f;

    game->camera.offset =
        (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    game->camera.target =
        (Vector2){game->player->position.x, game->player->position.y};

    game->tileset = LoadTexture("assets/tileset.png");

    game->player->sourceRect = (Rectangle){112, 112, 16, 16};

    game->enemyManager->sourceRect = (Rectangle){48, 112, 16, 16};

    game->projectileManager->sourceRect = (Rectangle){64, 112, 16, 16};

    game->flagSourceRect = (Rectangle){32, 80, 16, 16};

    return game;
}

void UpdateGame(Game *game) {
    UpdatePlayer(game->player);

    UpdateProjectileManager(game->projectileManager, game->player,
                            game->enemyManager);

    UpdateEnemyManager(game->enemyManager, game->player);

    game->camera.target =
        (Vector2){(int)game->player->position.x, (int)game->player->position.y};

    /* Collisions */
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!game->enemyManager->enemies[i].active) continue;

        for (int j = 0; j < MAX_PROJECTILES; j++) {
            if (!game->projectileManager->projectiles[j].active) continue;

            if (CheckCollisionRecs(
                    RectangleFromCenter(game->enemyManager->enemies[i].position,
                                        game->enemyManager->enemies[i].size),
                    RectangleFromCenter(
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

    /* Draw a flag on origin */
    Rectangle dest = {0, 0, 16 * gameScale, 16 * gameScale};

    Vector2 origin = {(dest.width / 2.0f), (dest.height / 2.0f)};

    float rotation = 0.0f;

    DrawTexturePro(game->tileset, game->flagSourceRect, dest, origin, rotation,
                   WHITE);

    DrawProjectileManager(game);

    DrawEnemyManager(game);

    DrawPlayer(game);

    EndMode2D();

    EndDrawing();
}

void UnloadGame(Game *game) {
    UnloadPlayer(game->player);

    UnloadProjectileManager(game->projectileManager);

    UnloadEnemyManager(game->enemyManager);

    UnloadTexture(game->tileset);

    free(game);
}
