#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/song_list.h"

typedef struct Playlist Playlist;

Playlist* createPlaylist(Playlist* playlist, char* name, SongList* songList);

void freePlaylist(Playlist* playlist);

void printPlaylist(Playlist* playlist);

#endif //PLAYLIST_H