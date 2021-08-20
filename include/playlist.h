#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Playlist Playlist;

#include "../include/song_list.h"

Playlist* createPlaylist(Playlist* playlist, char* name, SongList* songList);

void freePlaylist(Playlist* playlist);

void printPlaylist(Playlist* playlist);

Playlist* initializePlaylist(Playlist* playlist);

Playlist* refactoredPlaylist(Playlist* playlist);

SongList* getSongList(Playlist* playlist);

char* getPlaylistName(Playlist* playlist);

void printPlaylistinFile(Playlist* playlist,FILE* file);

int musicsComparator(Playlist *personPlaylist, Playlist *friendPlaylist);

#endif //PLAYLIST_H