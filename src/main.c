#include <stdlib.h>

#include "player.h"
#include "projectile.h"
#include "raylib.h"

int main() {
    /* Init */
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Survivors");

    SetTargetFPS(60);

    Player *player = InitPlayer();

    /* Camera */
    Camera2D camera = {0};
    camera.target = (Vector2){player->position.x, player->position.y};
    camera.zoom = 1.0f;

    camera.offset = (Vector2){(GetScreenWidth() - playerWidth) / 2.0f,
                              (GetScreenHeight() - playerHeight) / 2.0f};

    Projectile *projectile = InitProjectile(player->position);

    while (!WindowShouldClose()) {
        /* Update */
        UpdatePlayer(player);

        camera.target =
            (Vector2){(int)player->position.x, (int)player->position.y};

        /* Projectile */
        if (IsKeyPressed(KEY_SPACE)) {
            free(projectile);
            projectile = InitProjectile(player->position);
        }

        UpdateProjectile(projectile);

        /* Draw */
        BeginDrawing();

        ClearBackground(BLACK);

        /* Camera draw */
        BeginMode2D(camera);

        DrawPlayer(player);

        DrawRectangle(10, 10, 100, 100, YELLOW);

        DrawProjectile(projectile);

        EndMode2D();

        EndDrawing();
    }

    /* DeInit */
    UnloadPlayer(player);

    UnloadProjectile(projectile);

    CloseWindow();

    return 0;
}