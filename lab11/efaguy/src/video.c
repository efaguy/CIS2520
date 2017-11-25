#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "video.h"

Video* createVideo(char* name)
{
	Video* v = malloc(sizeof(Video));
	setTimesViewed(v,0);
	setVideoName(v,name);
	return v;
}

int getTimesViewed(Video* v)
{
	return v->timesViewed;
}

char* getVideoName(Video* v)
{
	return v->name;
}

void setTimesViewed(Video* v, int value)
{
	v->timesViewed = value;
}

void modifyTimesViewed(Video *v, int modValue)
{
	setTimesViewed(v, getTimesViewed(v) + modValue );
}

void setVideoName(Video* v, char* name)
{
	if( v->name )
	{
	 	free(v->name);	
	}
	if(name != NULL)
	{ 
		v->name = malloc(sizeof(char)*strlen(name));
	 	strncpy(v->name,name,strlen(name));
	}
}

void printVideo( void* data)
{
	Video* v = (Video*)data;
	char* name = getVideoName(v);
	if( name != NULL)
		printf("%s %d\n", name, getTimesViewed(v));
	else
		printf("A video has no name\n");
}

void deleteVideo( void* data)
{
	if( data )
	{
		Video* v = (Video*)data;
		free(v);
		v =NULL;
	}
}

int compareVideo( const void* first, const void* second)
{
	Video* f = (Video*)first;
	Video* s = (Video*)second;
	return strcmp(getVideoName(f),getVideoName(s));
}
