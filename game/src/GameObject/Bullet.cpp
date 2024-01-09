#include "Bullet.h"

void Bullet::die() {
    this->toBeDestroyed = true;
    BulletHit* hit = new BulletHit();
    hit->position = this->position;
    hit->width = this->width;
    hit->height = this->height;
    hit->name = "bullet hit effect";
    objectsManager.addGameObject(hit);
}
