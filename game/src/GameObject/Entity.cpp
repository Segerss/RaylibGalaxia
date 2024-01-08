#include "Entity.h"
#include "Bullet.h"
#include "Enemy.h"

#include "ObjectsManager.h"
#include "raylib.h"
#include <iostream>
Entity::Entity(int height, int width) : GameObject(), height(height), width(width) {}

Entity::Entity() : GameObject() {}

Entity::~Entity() {
    std::cout << "Unload Texture" << std::endl;

    UnloadTexture(texture);
}

void Entity::movement() {
    if (position.x < -100 || position.y < -100 || position.y > GetScreenHeight() || position.x > GetScreenWidth()) {
        if (objectsManager.contains(dynamic_cast<GameObject*>(this))) {
            // objectsManager.removeGameObject(dynamic_cast<GameObject*>(this));
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
        Rectangle rectangle = {0, 0, 0, 0};

        rectangle.x = 0;
        rectangle.y = 0;
        rectangle.width = this->width;
        rectangle.height = this->height;

        colliders.push_back(rectangle);
    }
}
Rectangle Entity::getColliderInPosition(unsigned int index) {
    if (index > this->colliders.size() - 1)
        return Rectangle();
    Rectangle actualColliderPosition = {0, 0, 0, 0};

    actualColliderPosition.x = this->colliders[index].x + this->position.x;
    actualColliderPosition.y = this->colliders[index].y + this->position.y;
    actualColliderPosition.height = this->colliders[index].height;
    actualColliderPosition.width = this->colliders[index].width;

    return actualColliderPosition;
}
void Entity::die() {

    toBeDestroyed = true;

    std::cout << "die on entity called" << std::endl;
}

void Entity::collided(GameObject* collidedObject) {
    if (dynamic_cast<Enemy*>(this) != nullptr) {
        if (dynamic_cast<Bullet*>(collidedObject) != nullptr) {
            Bullet* bullet = dynamic_cast<Bullet*>(collidedObject);
            this->health -= bullet->damage;

            if (this->health <= 0) {
                this->toBeDestroyed = true;
            }

            bullet->toBeDestroyed = true;
        }
    }

    if (dynamic_cast<Bullet*>(this) != nullptr) {
        if (dynamic_cast<Enemy*>(collidedObject) != nullptr) {
            Enemy* enemy = dynamic_cast<Enemy*>(collidedObject);
            enemy->health -= this->damage;

            if (enemy->health <= 0) {
                enemy->toBeDestroyed = true;
            }

            this->toBeDestroyed = true;
        }
    }
}
