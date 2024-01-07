#pragma once
#include "Projectile.h"
class Bullet : public Projectile {
public:
    // Texture2D texture = LoadTexture("resources/standardMissile.png");

private:
public:
    virtual void die() override;

    using Projectile::Projectile;
};
