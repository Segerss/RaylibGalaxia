#include <iostream>
#include <string>
#include <vector>

#include "raylib.h"

#include "Entity.h"
#include "GameObject.h"
#include "ObjectsManager.h"
#include "Player.h"

void drawBackground() {
    ClearBackground(YELLOW);
    static Texture2D texture = LoadTexture("resources/background.png");

    Rectangle recSource;
    recSource.x = 0;
    recSource.y = 0;
    recSource.width = texture.width;
    recSource.height = texture.height;

    Rectangle recDest;
    recDest.x = 0;
    recDest.y = 0;
    recDest.width = GetScreenWidth();
    recDest.height = GetScreenHeight();

    DrawTexturePro(texture, recSource, recDest, {0, 0}, 0, WHITE);

    return;
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 1000;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Galaxia");
    SetTargetFPS(60);
    bool pause = 0;

    Player* player = new Player(80, 80);
    player->texture = LoadTexture("resources/spaceship.png");
    objectsManager.addGameObject(player);

    while (!WindowShouldClose()) {
        objectsManager.updateObjects();

        BeginDrawing();
        drawBackground();

        for (const auto& gameObject : objectsManager.getGameObjects()) {
            if (dynamic_cast<Entity*>(gameObject) != nullptr) {
                Entity* entityPtr = dynamic_cast<Entity*>(gameObject);

                Rectangle recSource;
                recSource.x = 0;
                recSource.y = 0;
                recSource.width = entityPtr->texture.width;
                recSource.height = entityPtr->texture.height;

                Rectangle recDest;
                recDest.x = entityPtr->position.x;
                recDest.y = entityPtr->position.y;
                recDest.width = entityPtr->width;
                recDest.height = entityPtr->height;

                DrawTexturePro(entityPtr->texture, recSource, recDest, {0, 0}, 0, WHITE);

                // DrawTexture(entityPtr->texture, entityPtr->position.x, entityPtr->position.y, WHITE);
            }
        }

        if (pause)
            DrawText("PAUSED", 350, 200, 30, GRAY);
        DrawFPS(10, 10);
        EndDrawing();
    }

    for (const auto& gameObject : objectsManager.getGameObjects()) {
        if (dynamic_cast<Entity*>(gameObject) != nullptr) {
            Entity* entityPtr = dynamic_cast<Entity*>(gameObject);

            std::cout << "Unloading texture" << std::endl;
            UnloadTexture(entityPtr->texture);
        }

        objectsManager.removeGameObject(gameObject);
        delete gameObject;
    }

    CloseWindow();

    return 0;
}
