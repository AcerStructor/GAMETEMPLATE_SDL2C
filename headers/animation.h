#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "struct.h"

void InitAnimation(Animation* anim, CBYTE startFrame, CBYTE endFrame, float frameTime);

void UpdateAnimation(Animation* anim, float deltaTime);

void RenderAnimation(Sprite* sprite, const Animation anim);

#endif // _ANIMATION_H_
