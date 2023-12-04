#include "Player.h"
#include "raylib.h"
#include <iostream>

Player::Player() : Entity() {}

void Player::update() {
    if (IsKeyDown(KEY_W)) {
        position.y -= speed;
    }
    if (IsKeyDown(KEY_A)) {
        position.x -= speed;
    }
    if (IsKeyDown(KEY_S)) {
        position.y += speed;
    }
    if (IsKeyDown(KEY_D)) {
        position.x += speed;
    }
}
