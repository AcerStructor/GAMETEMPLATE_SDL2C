#include <SDL_rect.h>
#include "utils.h"
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
    collider->box.x = Get_RectMidPoint(collider->midPos.x, collider->box.w);
    collider->box.y = Get_RectMidPoint(collider->midPos.y, collider->box.h);
}


