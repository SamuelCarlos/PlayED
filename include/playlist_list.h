#ifndef PLAYLIST_LIST_H
#define PLAYLIST_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct PlaylistList PlaylistList;

#include "../include/playlist.h"

PlaylistList* initializePlaylistList(PlaylistList* list);

PlaylistList* insertPlaylistList(PlaylistList* list, char* playlistName, SongList* songList);

void freePlaylistList(PlaylistList* list);

void printPlaylistList(PlaylistList* list);

PlaylistList *organizePlaylistByArtist(PlaylistList* list);

void* findPlaylist(PlaylistList* list,char* playlistname);

void createPlaylistsFiles(PlaylistList* list, char* directory);

int countPersonPlaylists(PlaylistList* list);

void printPlaylistNameOnFile(FILE *file, PlaylistList* list);

int playlistsComparator(PlaylistList *personPlaylists, PlaylistList *friendPlaylists);


#endif //PLAYLIST_LIST_H