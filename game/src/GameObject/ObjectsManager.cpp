#include "ObjectsManager.h"

ObjectsManager objectsManager;

ObjectsManager::ObjectsManager() {}
ObjectsManager::~ObjectsManager() {}

std::vector<GameObject*> ObjectsManager::getGameObjects() {
    // std::vector<GameObject*> returnVector;
    //
    // returnVector.resize(gameObjects.size());
    //
    // for (int i = 0; i < gameObjects.size(); i++) {
    //     returnVector[i] = gameObjects[i];
    // }

    return gameObjects;
}

void ObjectsManager::updateObjects() {
    for (unsigned int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->update();
    }
}

void ObjectsManager::addGameObject(GameObject* objectToInsert) {
    gameObjects.push_back(objectToInsert);
    return;
}

void ObjectsManager::removeGameObject(GameObject* objectToRemove) {
    for (unsigned int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i] == objectToRemove) {
            for (unsigned int j = i; j < gameObjects.size() - 1; j++) {
                gameObjects[j] = gameObjects[j + 1];
            }
            gameObjects.resize(gameObjects.size() - 1);
        }
    }
}

bool ObjectsManager::contains(GameObject* wantedObject) {
    for (unsigned int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i] == wantedObject) {
            return true;
        }
    }
    return false;
}
