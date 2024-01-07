#pragma once
#include "Entity.h"
class Enemy : public Entity {
public:
private:
    void movement();
    void shooting();

public:
    Enemy();

    void update() override;

    using Entity::Entity;
};
