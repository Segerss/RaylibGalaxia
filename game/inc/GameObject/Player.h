#pragma once
#include "Entity.h"
class Player : public Entity {
public:
    int speed = 5;

private:
public:
    Player();

    void update() override;

    using Entity::Entity;
};
