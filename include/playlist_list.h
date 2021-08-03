#ifndef PLAYLIST_LIST_H
#define PLAYLIST_LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "../include/playlist.h"

typedef struct PlaylistList PlaylistList;

PlaylistList* initializePlaylistList(PlaylistList* list);

PlaylistList* insertPlaylistList(PlaylistList* list, char* playlistName, SongList* songList);

void freePlaylistList(PlaylistList* list);

void printPlaylistList(PlaylistList* list);

PlaylistList *organizePlaylistByArtist(PlaylistList* list);

PlaylistList *createNewPlaylistByArtistName(PlaylistList *newPlaylistList, Playlist *playlist);

#endif //PLAYLIST_LIST_H