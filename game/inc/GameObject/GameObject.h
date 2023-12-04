#pragma once
#include "raylib.h"

// Base class
class GameObject {
private:
public:
    Vector2 position = {0, 0};

public:
    GameObject();
    virtual ~GameObject();

    virtual void update();
};
