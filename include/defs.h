/**********************************************************************
 *
 * @file    defs.h
 * @brief   This header file holds all written definitions and
 *          and constants that are used for this program
 *
 * @author  Jerico G. Despe (aka @AcerStructor)
 *
 * @details
 * This header file includes constants and definitions such as the
 * program's window width, height, frame target time and more.
 *
 **********************************************************************/

#ifndef _DEFS_H_
#define _DEFS_H_

/* GAME CONFIGURATION */
#define GAME_WINDOW_TITLE    "SDL2_CTemplate"
#define GAME_WINDOW_WIDTH    1280
#define GAME_WINDOW_HEIGHT   800

/* GAME FRAMERATE CAPPING */
#define FPS                  60
#define FRAME_TARGET_TIME   (1000 / FPS)

/* CUSTOM DATA TYPES */
typedef char  CBYTE;
typedef CBYTE CBOOL;

/* BOOLEAN */
#define TRUE  1
#define FALSE 0

#endif // _DEFS_h_
