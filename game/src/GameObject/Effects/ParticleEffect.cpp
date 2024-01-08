#include "ParticleEffect.h"
#include "raylib.h"

ParticleEffect::ParticleEffect() {}

ParticleEffect::~ParticleEffect() {
    for (unsigned int i = 0; i < frames.size(); i++) {
        std::cout << "Unloading Frame" << std::endl;
        UnloadTexture(frames[i]);
    }
}

void ParticleEffect::update() {
    std::cout << "particle effect update" << std::endl;
    // this->texture = LoadTexture("resources/BulletExplosion/Explosion1.png");
    this->texture = frames[currentFrame];
    if (this->lastFrame + this->millisecondsBetweenFrames < millis()) {
        lastFrame = millis();
        currentFrame++;

        if (currentFrame == frames.size()) {
            // toBeDestroyed = true;
            currentFrame = 0;
        }
    }
}
