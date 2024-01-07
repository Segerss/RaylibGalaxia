#pragma once
#include <iostream>
#include <vector>

#include "Entity.h"
#include "GameObject.h"

struct Collision {
    Entity* entity1;
    Entity* entity2;
};

class ObjectsManager {
public:
    ObjectsManager();
    ~ObjectsManager();

    void updateObjects();

    void addGameObject(GameObject* objectToInsert);
    void removeGameObject(GameObject* objectToRemove);

    bool collidingWith(Entity* entity1, Entity* entity2);
    void checkCollisions();
    void handleCollisions();

    std::vector<GameObject*> getGameObjects();
    bool contains(GameObject* wantedObject);

private:
    std::vector<GameObject*> gameObjects;
    std::vector<Collision> alreadyFoundCollisions;
    bool alreadyFoundCollision(Collision collision);
};

// Declaration of the external instance
extern ObjectsManager objectsManager;
