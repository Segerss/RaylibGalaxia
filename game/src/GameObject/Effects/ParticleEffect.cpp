#include "ParticleEffect.h"
#include "raylib.h"

ParticleEffect::ParticleEffect() {}

ParticleEffect::~ParticleEffect() {
    for (unsigned int i = 0; i < frames.size(); i++) {
        UnloadTexture(frames[i]);
    }
}

void ParticleEffect::update() {
    if (frames.size() == 0) {
        std::cout << "No frames detected in frames list" << std::endl;
        return;
    }
    this->texture = frames[currentFrame];
    if (this->lastFrame + this->millisecondsBetweenFrames < millis()) {
        lastFrame = millis();
        currentFrame++;

        if (currentFrame == frames.size()) {
            if (!this->continuesEffect)
                toBeDestroyed = true;
            // toBeDestroyed = true;
            currentFrame = 0;
        }
    }
}
