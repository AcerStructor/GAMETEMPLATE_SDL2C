/*
 * @file   sprite.c
 * @brief  This is the source code for sprite.c
 * #author Jerico G. Despe (aka @AcerStructor)
 */

#include "utils.h"
#include "draw.h"
#include "sprite.h"

Sprite* InitSprite(const char* spritePath, SpriteClip* clip)
{
    Sprite* temp = NULL;

    temp = (Sprite*)malloc(sizeof(Sprite));

    if (temp == NULL)
    {
        fprintf(stderr, "ERROR: Couldn't allocate sprite data\n");
        return NULL;
    }

    if (!(temp->texture = LoadTexture(spritePath)))
    {
        free(temp);
        return NULL;
    }

    if (clip != NULL)
    {
        /* INITIALIZE WITH PROVIDED CLIPPING INFO */
        temp->clip = *clip;

        temp->scale.x = (float) temp->clip.spriteWidth;
        temp->scale.y = (float) temp->clip.spriteHeight;
    }
    else // IF NO CLIPPING INFO PROVIDED
    {
        int width, height;

        if (SDL_QueryTexture(temp->texture, NULL, NULL, &width, &height) != 0)
        {
            fprintf(stderr, "ERROR: Couldn't query texture: %s\n", SDL_GetError());
            DestroySprite(temp);
            return NULL;
        }

        /* INITIALIZE WITH QUARIED TEXTURE */
        temp->clip.spriteIndex   = 0;
        temp->clip.spritesPerRow = 1;
        temp->clip.spriteWidth   = (short) width;
        temp->clip.spriteHeight  = (short) height;

        /* SET SPRITE SCALE */
        temp->scale.x = (float) temp->clip.spriteWidth;
        temp->scale.y = (float) temp->clip.spriteHeight;
    }

    return temp;
}

void DrawSprite(Sprite* sprite)
{
    if (sprite == NULL) return;

    SDL_Rect clipRect = GetSpriteRect(sprite->clip);
    DrawTexture(sprite->texture, sprite->scale, sprite->cursorPos, &clipRect);
}

void DestroySprite(Sprite* sprite)
{
    if (sprite == NULL)
    {
        fprintf(stderr, "ERROR: Sprite is already NULL. No de-allocation is required... SKIPPNG...\n");
        return;
    }

    DestroyTexture(sprite->texture);
    free(sprite);
}

void SetSpritePosition(Sprite* sprite, float x, float y)
{
    /* INITIALIZE MIDPOS */
    sprite->midPos.x = x;
    sprite->midPos.y = y;

    /* CALCULATE CENTER */
    sprite->cursorPos.x = Get_RectMidPoint(sprite->midPos.x, sprite->scale.x);
    sprite->cursorPos.y = Get_RectMidPoint(sprite->midPos.y, sprite->scale.y);
}
