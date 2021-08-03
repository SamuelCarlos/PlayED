#ifndef SONG_LIST_H
#define SONG_LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "../include/song.h"

typedef struct SongList SongList;

SongList* initializeSongList(SongList* list);

void insertSongList(SongList* list, Song* song);

void freeSongList(SongList* list);

SongList* readEachPlaylistFile(SongList* list, char* fileName);

void printSongList(SongList* list);

#endif //SONG_LIST_H