#pragma once
#include "Entity.h"
class Player : public Entity {
public:
private:
    void movement();
    void shooting();

public:
    Player();

    void update() override;

    using Entity::Entity;
};
