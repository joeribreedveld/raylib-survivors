#include "game.h"

#include <stdlib.h>

#include "utils.h"

Game *InitGame()
{
    Game *game = malloc(sizeof(Game));

    game->player = InitPlayer();

    game->projectileManager = InitProjectileManager();

    game->enemyManager = InitEnemyManager();

    game->camera.zoom = 1.0f;

    game->camera.offset =
        (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    game->camera.target =
        (Vector2){game->player->position.x, game->player->position.y};

    return game;
}

void UpdateGame(Game *game)
{
    UpdatePlayer(game->player);

    UpdateProjectileManager(game->projectileManager, game->player,
                            game->enemyManager);

    UpdateEnemyManager(game->enemyManager, game->player);

    game->camera.target =
        (Vector2){(int)game->player->position.x, (int)game->player->position.y};

    /* Collisions */
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (!game->enemyManager->enemies[i].active)
            continue;

        for (int j = 0; j < MAX_PROJECTILES; j++)
        {
            if (!game->projectileManager->projectiles[j].active)
                continue;

            if (CheckCollisionRecs(
                    RectangleFromCenter(game->enemyManager->enemies[i].position,
                                        game->enemyManager->enemies[i].size),
                    RectangleFromCenter(
                        game->projectileManager->projectiles[j].position,
                        game->projectileManager->projectiles[j].size)))
            {
                game->enemyManager->enemies[i].hp -= 1;

                game->projectileManager->projectiles[j].piercing -= 1;
            }
        }
    }
}

void DrawGame(Game *game)
{
    BeginDrawing();

    ClearBackground(BLACK);

    BeginMode2D(game->camera);

    DrawRectangle(0, 0, 100, 100, PINK);

    DrawProjectileManager(game);

    DrawEnemyManager(game);

    DrawPlayer(game->player);

    EndMode2D();

    EndDrawing();
}

void UnloadGame(Game *game)
{
    UnloadPlayer(game->player);

    UnloadProjectileManager(game->projectileManager);

    UnloadEnemyManager(game->enemyManager);

    free(game);
}
