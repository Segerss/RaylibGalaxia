#pragma once
#include <iostream>
#include <vector>

#include "Entity.h"
#include "GameObject.h"

class ObjectsManager {
public:
    ObjectsManager();
    ~ObjectsManager();

    void updateObjects();

    void addGameObject(GameObject* objectToInsert);
    void removeGameObject(GameObject* objectToRemove);

    void checkCollisions();

    std::vector<GameObject*> getGameObjects();
    bool contains(GameObject* wantedObject);

private:
    std::vector<GameObject*> gameObjects;
};

// Declaration of the external instance
extern ObjectsManager objectsManager;
