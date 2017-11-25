#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "video.h"
#include "HeapAPI.h"

/**
 * printMenu - prints the options to add/remove/watch a video.
 */
void printMenu();

/**
 * getVName - menu system interaction to retrieve the video name.
 * @return [description]
 */
char* getVName();

/**
 * getVideo - encapsulated process to retrieve video from user.
 * @return [description]
 */
Video* getVideo(); 
/**
 * addVideo - Add a video to the heap. Video must already be collected but may be NULL.
 * @param  heap [description]
 * @param  v    [description]
 * @return      [description]
 */
int addVideo(Heap * heap, Video* v);

/**
 * watchVideo - Menu system to request a video name and increment view count.
 * @param  heap [description]
 * @return      [description]
 */
int watchVideo(Heap * heap);

#endif
