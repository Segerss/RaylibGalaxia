#pragma once
#include "Entity.h"
class Projectile : public Entity {
public:
private:
    void movement();

public:
    Projectile();

    // virtual void update();

    using Entity::Entity;
};
