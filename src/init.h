/**********************************************************************
 *
 * @file    draw.h
 * @brief   This file provides functions to initialize game data
 *          and SDL2 libraries and its SDL2 addons.
 *
 * @author  Jerico G. Despe (aka @AcerStructor)
 *
 * @note
 * Ensure that the appropriate header file (defs.h) is included in
 * this header file and also common.h and struct.h in its source file
 *
 * @dependencies
 * SDL2 SDL2_Image libraries
 *
 **********************************************************************/

#ifndef _INIT_H_
#define _INIT_H_
#include "defs.h"

CBOOL   InitGame();
void    QuitGame();

#endif // _INIT_H_
