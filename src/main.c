#include "player.h"
#include "raylib.h"

int main() {
    /* Init */
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Survivors");

    SetTargetFPS(60);

    Player *player = InitPlayer();

    while (!WindowShouldClose()) {
        /* Update */
        UpdatePlayer(player);

        /* Draw */
        BeginDrawing();

        ClearBackground(BLACK);

        DrawPlayer(player);

        EndDrawing();
    }

    /* DeInit */
    UnloadPlayer(player);

    CloseWindow();

    return 0;
}