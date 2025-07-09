#include "game.h"
#include "raylib.h"

int main() {
    /* Init */
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Survivors");

    SetTargetFPS(60);

    Game *game = InitGame();

    while (!WindowShouldClose()) {
        UpdateGame(game);

        DrawGame(game);
    }

    UnloadGame(game);

    CloseWindow();

    return 0;
}