#include "player.h"
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
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera.offset =
        (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    while (!WindowShouldClose()) {
        /* Update */
        UpdatePlayer(player);

        camera.target =
            (Vector2){(int)player->position.x, (int)player->position.y};

        /* Draw */
        BeginDrawing();

        ClearBackground(BLACK);

        /* Camera draw */
        BeginMode2D(camera);

        DrawPlayer(player);

        DrawRectangle(10, 10, 100, 100, YELLOW);

        EndMode2D();

        EndDrawing();
    }

    /* DeInit */
    UnloadPlayer(player);

    CloseWindow();

    return 0;
}