#pragma once
#include <iostream>

#include "Entity.h"
#include "Millis.h"

class ParticleEffect : public Entity {
public:
private:
    std::vector<Texture2D> frames = {LoadTexture("resources/BulletExplosion/Explosion1.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion2.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion3.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion4.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion5.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion6.png"),
                                     LoadTexture("resources/BulletExplosion/Explosion7.png")};
    unsigned int currentFrame = 0;

    bool continuesEffect = false;

    unsigned long long lastFrame = millis();

    unsigned long long millisecondsBetweenFrames = 10;

public:
    ParticleEffect();

    ~ParticleEffect();

    virtual void update() override;

    using Entity::Entity;
};
