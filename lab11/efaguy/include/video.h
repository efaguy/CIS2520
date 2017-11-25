#ifndef VIDEO_H
#define VIDEO_H

typedef struct video
{
    int timesViewed;
    char*name; 
} Video;


/**
 * CreateVideo - set up the name and timesView = 0
 * @param  name 
 * @return      return the object
 */
Video* createVideo(char* name);

/**
 * getTimesViewed - accessor method for Video Property
 * @param  v [description]
 * @return   [description]
 */
int getTimesViewed(Video* v);

/**
 * getVideoName - accessor method for Video Property
 * @param  v [description]
 * @return   [description]
 */
char* getVideoName(Video* v);

/**
 * setTimesViewed mutator for the Video Property
 * @param v     [description]
 * @param value [description]
 */
void setTimesViewed(Video* v, int value);

/**
 * setVideoName  mutator for the Video Property
 * @param v    [description]
 * @param name [description]
 */
void setVideoName(Video* v, char* name);

/**
 * modifyTimesViewed - adjusts the times viewed value by a set amount.
 *                     useful for incrementing and decrementing value.
 * @param v        [description]
 * @param modValue [description]
 */
void modifyTimesViewed(Video *v, int modValue);

/**
 * printVideo - print video data to screen 
 * @param data [description]
 */
void printVideo( void* data);

/**
 * deleteVideo - delete (free) memory for the video
 * @param data [description]
 */
void deleteVideo( void* data);

/**
 * compareVideo - compares two videos usually done by name.
 * @param  first  [description]
 * @param  second [description]
 * @return        [description]
 */
int compareVideo( const void* first, const void* second);

#endif
