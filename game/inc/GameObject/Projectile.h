#pragma once
#include "Entity.h"
class Projectile : public Entity {
public:
private:
    void movement();

public:
    Projectile();

    void update() override;

    using Entity::Entity;
};
