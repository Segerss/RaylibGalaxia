#pragma once
#include "ParticleEffect.h"

class BulletHit : public ParticleEffect {
public:
private:
    std::vector<Texture2D> frames = {LoadTexture("resources/BulletExplosion/Explosion1.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion2.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion3.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion4.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion5.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion6.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion7.png")};

public:
    BulletHit();

    ~BulletHit();

    virtual void update() override;

    using ParticleEffect::ParticleEffect;
};
