#include "Player.h"
#include "Bullet.h"
#include "ObjectsManager.h"
#include "Projectile.h"
#include "raylib.h"
#include <iostream>

Player::Player() : Entity() {}

void Player::movement() {
    if (toBeDestroyed)
        return;
    if (position.x < -100 || position.y < -100 || position.y > GetScreenHeight() || position.x > GetScreenWidth()) {
        if (objectsManager.contains(dynamic_cast<GameObject*>(this))) {
            objectsManager.removeGameObject(dynamic_cast<GameObject*>(this));
            toBeDestroyed = true;
            return;
        }
    }
    if (IsKeyDown(KEY_W)) {
        velocity.y -= speed;
    }
    if (IsKeyDown(KEY_A)) {
        velocity.x -= speed;
    }
    if (IsKeyDown(KEY_S)) {
        velocity.y += speed;
    }
    if (IsKeyDown(KEY_D)) {
        velocity.x += speed;
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

void Player::shooting() {
    if (toBeDestroyed)
        return;
    bool shootBullet = false;

    if (IsKeyDown(KEY_SPACE)) {
        shootBullet = true;
    }

    if (shootBullet == true) {
        Bullet* bullet = new Bullet(30, 30);

        bullet->texture = LoadTexture("resources/standardMissile.png");
        bullet->colliderFromTexture();
        bullet->isCollidable = true;
        bullet->position = {this->position.x, (this->position.y + (float)(this->texture.height / 2.0))};
        bullet->velocity.y = -5;
        bullet->name = "Bullet";

        objectsManager.addGameObject(bullet);
    }
}

void Player::update() {
    this->movement();

    this->shooting();
}
