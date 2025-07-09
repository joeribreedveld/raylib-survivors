#include "player.h"
#include "projectile.h"
#include "raylib.h"

#define MAX_PROJECTILES 50

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

    Projectile *projectiles[MAX_PROJECTILES];

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        projectiles[i] = InitProjectile();
    }

    while (!WindowShouldClose()) {
        /* Update */
        UpdatePlayer(player);

        camera.target =
            (Vector2){(int)player->position.x, (int)player->position.y};

        /* Projectile */
        if (IsKeyPressed(KEY_SPACE)) {
            for (int i = 0; i < MAX_PROJECTILES; i++) {
                if (!projectiles[i]->active) {
                    ShootProjectile(projectiles[i], player->position,
                                    (Vector2){0, -1});

                    break;
                }
            }
        }

        for (int i = 0; i < MAX_PROJECTILES; i++) {
            UpdateProjectile(projectiles[i]);
        }

        /* Draw */
        BeginDrawing();

        ClearBackground(BLACK);

        /* Camera draw */
        BeginMode2D(camera);

        DrawPlayer(player);

        DrawRectangle(10, 10, 100, 100, YELLOW);

        for (int i = 0; i < MAX_PROJECTILES; i++) {
            DrawProjectile(projectiles[i]);
        }

        EndMode2D();

        EndDrawing();
    }

    /* DeInit */
    UnloadPlayer(player);

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        UnloadProjectile(projectiles[i]);
    }

    CloseWindow();

    return 0;
}