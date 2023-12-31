#include "Entity.h"
#include "ObjectsManager.h"
#include "raylib.h"
#include <iostream>
Entity::Entity(int height, int width) : GameObject(), height(height), width(width) {}

Entity::Entity() : GameObject() {}

void Entity::movement() {
    if (position.x < -100 || position.y < -100 || position.y > GetScreenHeight() || position.x > GetScreenWidth()) {
        if (objectsManager.contains(dynamic_cast<GameObject*>(this))) {
            objectsManager.removeGameObject(dynamic_cast<GameObject*>(this));
            toBeDestroyed = true;
            return;
        }
    }

    position.x += velocity.x;
    position.y += velocity.y;

    if (drag != 0) {
        velocity.x = velocity.x / drag;
        velocity.y = velocity.y / drag;
    }

    if (maxSpeed != 0) {
        if (std::abs(velocity.x) > maxSpeed) {
            velocity.x = (velocity.x / std::abs(velocity.x) * maxSpeed);
        }
        if (std::abs(velocity.y) > maxSpeed) {
            velocity.y = (velocity.y / std::abs(velocity.y) * maxSpeed);
        }
    }
}

void Entity::update() { this->movement(); }

void Entity::colliderFromTexture() {
    if (IsTextureReady(texture)) {
        Rectangle rectangle;

        colliders.push_back(rectangle);
    }
}
