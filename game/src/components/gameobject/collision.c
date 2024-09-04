#include <SDL_rect.h>
#include "utils.h"
#include "collision.h"

void InitCollisionBox(Collider* collider, Point initialPos, Scale scale)
{
    collider->box.x = 0;
    collider->box.y = 0;
    collider->box.w = scale.x;
    collider->box.h = scale.y;

    SetCollisionBoxPosition(collider, initialPos.x, initialPos.y);

}

CBOOL HasCollisionIntersection(Collider colliderOne, Collider colliderTwo)
{
    return SDL_HasIntersection(&colliderOne.box, &colliderTwo.box);
}

void SetCollisionBoxPosition(Collider* collider, float x, float y)
{
    collider->midPos.x = x;
    collider->midPos.y = y;

    /* CALCULATE CENTER */
    collider->box.x = Get_RectMidPoint(collider->midPos.x, collider->box.w);
    collider->box.y = Get_RectMidPoint(collider->midPos.y, collider->box.h);
}

