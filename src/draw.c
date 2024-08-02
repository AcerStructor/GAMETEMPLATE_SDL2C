/*
 * @file   draw.c
 * @brief  This is the source code for draw.h
 * #author Jerico G. Despe (aka @AcerStructor)
 */

#include "draw.h"

extern Game* game;

SDL_Texture* LoadTexture(const char* spritePath)
{
    SDL_Texture* temp = NULL;

    printf("LOG: Loading texture from %s : ", spritePath);

    temp = IMG_LoadTexture(game->renderer, spritePath);

    if (temp == NULL)
    {
        printf("LOADING FAILED! : %s\n", SDL_GetError());
        return NULL;
    }

    printf("LOADED SUCCESSFULLY! \n");

    return temp;
}

void DrawTexture(SDL_Texture* texture, Scale scale, Position pos, SDL_Rect* clipRect)
{
    if (texture == NULL) return;

    SDL_Rect destRect = {
        pos.x, pos.y,
        scale.x, scale.y
    };

    SDL_RenderCopy(game->renderer, texture, clipRect, &destRect);
}

void DestroyTexture(SDL_Texture* texture)
{
    if (texture == NULL)
    {
        fprintf(stderr, "ERROR: Texture is already NULL! No de-allocation is required... SKIPPING...\n");
        return;
    }

    SDL_DestroyTexture(texture);
}
