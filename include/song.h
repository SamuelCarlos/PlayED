#ifndef SONG_H
#define SONG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song Song;

Song* createSong(char* name, char* artist);

void freeSong(Song* song);

void printSong(Song* song);

char *getArtistName(Song *song);

#endif //SONG_H