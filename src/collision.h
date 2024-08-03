#ifndef _COLLISION_H_
#define _COLLISION_H_
#include "struct.h"

CBOOL HasCollisionIntersection(CollisionBox colliderOne, CollisionBox colliderTwo);

void  SetCollisionBoxPosition(CollisionBox* collider, float x, float y);

#endif // _COLLISION_H_
