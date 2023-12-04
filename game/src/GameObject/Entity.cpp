#include "Entity.h"
#include <iostream>
Entity::Entity(int height, int width) : GameObject(), height(height), width(width) {}

Entity::Entity() : GameObject() {}

void Entity::update() { std::cout << "Entity Update call" << std::endl; }
