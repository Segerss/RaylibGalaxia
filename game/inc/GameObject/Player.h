#pragma once
#include "Entity.h"
class Player : public Entity {
public:
    int damage = 0;

private:
    void movement();
    void shooting();

public:
    Player();

    void update() override;

    using Entity::Entity;
};
