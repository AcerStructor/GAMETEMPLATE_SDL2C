#include "sprite.h"
#include "animation.h"

void InitAnimation(Animation* anim, CBYTE startFrame, CBYTE endFrame, float frameTime)
{
    anim->currentFrame = startFrame;
    anim->elapsedTime  = 0.0f;
    anim->startFrame   = startFrame;
    anim->endFrame     = endFrame;
    anim->frameTime    = frameTime;
}

void UpdateAnimation(Animation* anim, float deltaTime)
{
    anim->elapsedTime += deltaTime;

    if (anim->elapsedTime >= anim->frameTime)
    {
        anim->elapsedTime -= anim->frameTime;
        anim->currentFrame++;
        if (anim->currentFrame >= anim->endFrame)
            anim->currentFrame = anim->startFrame;
    }
}

void RenderAnimation(Sprite* sprite, const Animation anim)
{
    sprite->clip.spriteIndex = anim.currentFrame;
    DrawSprite(sprite);
}
