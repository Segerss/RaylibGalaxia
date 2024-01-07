#include <iostream>
#include <string>
#include <vector>

#include "raylib.h"

#include "Millis.h"

#include "Enemy.h"
#include "Entity.h"
#include "GameObject.h"
#include "ObjectsManager.h"
#include "Player.h"

#include "Bullet.h"

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
    // LOG_ALL: 0
    // LOG_TRACE: 1
    // LOG_DEBUG: 2
    // LOG_INFO: 3
    // LOG_WARNING: 4
    // LOG_ERROR: 5
    // LOG_FATAL: 6
    // LOG_NONE: 7
    SetTraceLogLevel(LOG_WARNING);
    const int screenWidth = 800;
    const int screenHeight = 1000;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Galaxia");
    SetTargetFPS(60);
    bool pause = 0;

    Player* player = new Player(80, 80);
    player->texture = LoadTexture("resources/spaceship.png");
    player->colliderFromTexture();
    player->isCollidable = true;
    player->speed = 1.3;
    player->maxSpeed = 10;
    player->drag = 1.12;
    player->name = "Player";
    objectsManager.addGameObject(player);

    Enemy* enemy = new Enemy(80, 80);
    enemy->texture = LoadTexture("resources/enemyBlue.png");
    enemy->colliderFromTexture();
    enemy->position = {200, 200};
    enemy->isCollidable = true;
    enemy->name = "test enemy";
    objectsManager.addGameObject(enemy);
    // {
    //     Player* player = new Player(80, 80);
    //     player->texture = LoadTexture("resources/spaceship.png");
    //     player->colliderFromTexture();
    //     player->isCollidable = true;
    //     player->position = {200, 200};
    //     player->speed = 1.3;
    //     player->maxSpeed = 10;
    //     player->drag = 1.12;
    //     player->name = "Player";
    //     objectsManager.addGameObject(player);
    // }
    while (!WindowShouldClose()) {
        std::cout << "Millis(): " << millis() << std::endl;
        objectsManager.updateObjects();

        objectsManager.checkCollisions();

        BeginDrawing();
        drawBackground();

        std::vector<GameObject*> gameObjects = objectsManager.getGameObjects();

        for (unsigned int i = 0; i < gameObjects.size(); i++) {
            // std::cout << "Amount of Objects: " << objectsManager.getGameObjects().size() << ", " << i << std::endl;
            GameObject* gameObject = gameObjects[i];
            if (gameObject->toBeDestroyed == true) {
                if (dynamic_cast<Entity*>(gameObject) != nullptr) {
                    Entity* entityPtr = dynamic_cast<Entity*>(gameObject);
                    entityPtr->die();
                    UnloadTexture(entityPtr->texture);
                }

                objectsManager.removeGameObject(gameObject);
                delete gameObject;
                continue;
            }

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
                for (unsigned int i = 0; i < entityPtr->colliders.size(); i++) {
                    Rectangle collider = entityPtr->getColliderInPosition(i);
                    DrawRectangleLines(collider.x, collider.y, collider.width, collider.height, GREEN);
                }
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
