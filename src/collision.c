#include <SDL_rect.h>
#include "collision.h"

CBOOL HasCollisionIntersection(CollisionBox colliderOne, CollisionBox colliderTwo)
{
    return SDL_HasIntersection(&colliderOne.box, &colliderTwo.box);
}

void  SetCollisionBoxPosition(CollisionBox* collider, float x, float y)
{
    collider->midPos.x = x;
    collider->midPos.y = y;

    /* CALCULATE CENTER */
    float midScaleX = (collider->box.x / 2);
    float midScaleY = (collider->box.y / 2);

    collider->box.x = (collider->midPos.x - midScaleX);
    collider->box.y = (collider->midPos.y - midScaleY);
}


