#ifndef _COLLISION_H_
#define _COLLISION_H_
#include "struct.h"

void   InitCollisionBox(Collider* collider, Point initialPos, Scale scale);

CBOOL  HasCollisionIntersection(Collider colliderOne, Collider colliderTwo);

void   SetCollisionBoxPosition(Collider* collider, float x, float y);

#endif // _COLLISION_H_
