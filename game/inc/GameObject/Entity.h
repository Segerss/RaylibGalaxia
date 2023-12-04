#pragma once
#include "GameObject.h"
#include "raylib.h"

class Entity : public GameObject {
public:
    Texture2D texture;
    int height = 0;
    int width = 0;
    int speed = 0;

private:
public:
    Entity();
    Entity(int height, int width);

    void update() override;
};
