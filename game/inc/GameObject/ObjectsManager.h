#pragma once
#include "GameObject.h"
#include <vector>

class ObjectsManager {
public:
    ObjectsManager();
    ~ObjectsManager();

    void updateObjects();

    void addGameObject(GameObject* objectToInsert);
    void removeGameObject(GameObject* objectToRemove);

    std::vector<GameObject*> getGameObjects();

private:
    std::vector<GameObject*> gameObjects;
};

// Declaration of the external instance
extern ObjectsManager objectsManager;
