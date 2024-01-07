#pragma once
#include <string>
#include <vector>

#include "GameObject.h"
#include "raylib.h"

class Entity : public GameObject {
public:
    std::string name = "";

    Texture2D texture;
    int height = 0;
    int width = 0;
    std::vector<Rectangle> colliders;
    bool isCollidable = false;

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
    virtual void colliderFromTexture();
};
