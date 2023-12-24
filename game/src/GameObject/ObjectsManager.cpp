#include "ObjectsManager.h"

ObjectsManager objectsManager;

ObjectsManager::ObjectsManager() {}
ObjectsManager::~ObjectsManager() {}

std::vector<GameObject*> ObjectsManager::getGameObjects() { return gameObjects; }

void ObjectsManager::updateObjects() {
    for (auto gameObject : gameObjects) {
        gameObject->update();
    }
}

void ObjectsManager::addGameObject(GameObject* objectToInsert) {
    gameObjects.push_back(objectToInsert);
    return;
}

void ObjectsManager::removeGameObject(GameObject* objectToRemove) {
    for (unsigned int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i] == objectToRemove) {
            gameObjects.erase(gameObjects.begin() + i);
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
