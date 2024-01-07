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
//
// bool areRectanglesIntersecting(const Rectangle rect1, const Rectangle rect2) {
//     std::cout << "Rectangle1 " << rect1.x << ", " << rect1.y << std::endl;
//     std::cout << "Rectangle2 " << rect2.x << ", " << rect2.y << std::endl;
//     // Check for intersection along x-axis
//     bool xOverlap = (rect1.x < rect2.x + rect2.width) && (rect1.x + rect1.width > rect2.x);
//
//     // Check for intersection along y-axis
//     bool yOverlap = (rect1.y < rect2.y + rect2.height) && (rect1.y + rect1.height > rect2.y);
//
//     // If both x and y overlap, rectangles intersect
//     return xOverlap && yOverlap;
// }

bool ObjectsManager::collidingWith(Entity* entity1, Entity* entity2) {
    for (unsigned int i = 0; i < gameObjects.size(); i++) {
        for (unsigned int colliders1 = 0; colliders1 < entity1->colliders.size(); colliders1++) {
            for (unsigned int colliders2 = 0; colliders2 < entity2->colliders.size(); colliders2++) {

                Rectangle rect1 = entity1->getColliderInPosition(colliders1);
                Rectangle rect2 = entity2->getColliderInPosition(colliders2);

                bool xOverlap = (rect1.x < rect2.x + rect2.width) && (rect1.x + rect1.width > rect2.x);
                bool yOverlap = (rect1.y < rect2.y + rect2.height) && (rect1.y + rect1.height > rect2.y);

                if (xOverlap && yOverlap) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool ObjectsManager::alreadyFoundCollision(Collision collision) {
    for (const auto& existingCollision : this->alreadyFoundCollisions) {
        // Compare the entity pointers or any other relevant information
        if ((existingCollision.entity1 == collision.entity1 && existingCollision.entity2 == collision.entity2) ||
            (existingCollision.entity1 == collision.entity2 && existingCollision.entity2 == collision.entity1)) {
            return true; // Collision with the same values is already present
        }
    }
    return false; // Collision not found in the vector
}

void ObjectsManager::checkCollisions() {
    for (unsigned int i = 0; i < gameObjects.size(); i++) {
        GameObject* gameObject = gameObjects[i];

        if (dynamic_cast<Entity*>(gameObject) != nullptr) {
            Entity* entityToCheck = dynamic_cast<Entity*>(gameObject);

            for (unsigned int j = 0; j < gameObjects.size(); j++) {
                GameObject* gameObject2 = gameObjects[j];

                if (dynamic_cast<Entity*>(gameObject2) != nullptr) {
                    Entity* entityPtr = dynamic_cast<Entity*>(gameObject2);

                    if (entityPtr == entityToCheck) {
                        continue;
                    }

                    if (entityPtr->isCollidable && collidingWith(entityToCheck, entityPtr)) {
                        Collision collision = {entityToCheck, entityPtr};
                        if (!alreadyFoundCollision(collision)) {
                            std::cout << "Entity: " << entityToCheck->name << " with: " << entityPtr->name << std::endl;
                            this->alreadyFoundCollisions.push_back(collision);
                        }
                    }
                }
            }
            // std::cout << entityPtr->name << std::endl;
        }
    }

    this->handleCollisions();

    this->alreadyFoundCollisions.resize(0);
    return;
}

void ObjectsManager::handleCollisions() {
    for (unsigned int i = 0; i < alreadyFoundCollisions.size(); i++) {
        alreadyFoundCollisions[i].entity1->collided(alreadyFoundCollisions[i].entity2);
    }
    return;
}
