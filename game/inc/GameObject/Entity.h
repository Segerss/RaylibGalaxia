#pragma once
#include "GameObject.h"
#include "raylib.h"
#include <string>

class Entity : public GameObject {
public:
    std::string name = "";

    Texture2D texture;
    int height = 0;
    int width = 0;

    Vector2 velocity = {0, 0};
    float speed = 0;
    float maxSpeed = 0;
    float drag = 0;

private:
    void movement();

public:
    Entity();
    Entity(int height, int width);

    virtual void update() override;
};
