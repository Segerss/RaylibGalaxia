#include "ObjectsManager.h"

ObjectsManager objectsManager;

ObjectsManager::ObjectsManager() {}
ObjectsManager::~ObjectsManager() {}

std::vector<GameObject*> ObjectsManager::getGameObjects() { return gameObjects; }

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

void ObjectsManager::checkCollisions() {
    // std::cout << "from collisions" << std::endl;
    // for (unsigned int i = 0; i < gameObjects.size(); i++) {
    //     GameObject* gameObject = gameObjects[i];
    //     if (dynamic_cast<Entity*>(gameObject) != nullptr) {
    //         Entity* entityPtr = dynamic_cast<Entity*>(gameObject);
    //         std::cout << entityPtr->name << std::endl;
    //     }
    // }
    return;
}
