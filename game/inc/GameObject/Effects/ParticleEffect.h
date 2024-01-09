#pragma once
#include <iostream>

#include "Entity.h"
#include "Millis.h"

class ParticleEffect : public Entity {
public:
    std::vector<Texture2D> frames;
    bool continuesEffect = false;

    unsigned int currentFrame = 0;
    unsigned long long lastFrame = millis();
    unsigned long long millisecondsBetweenFrames = 10;

private:
public:
    ParticleEffect();

    ~ParticleEffect();

    void update() override;

    using Entity::Entity;
};
