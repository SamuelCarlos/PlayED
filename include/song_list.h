#ifndef SONG_LIST_H
#define SONG_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct SongList SongList;

#include "../include/song.h"
#include "../include/playlist_list.h"

SongList* initializeSongList(SongList* list);

void insertSongList(SongList* list, Song* song);

void freeSongList(SongList* list);

SongList* readEachPlaylistFile(SongList* list, char* fileName);

void printSongList(SongList* list);

void refactoredSongList(SongList* list,PlaylistList* playlistlist);

void printSongListinFile(SongList* list,FILE* file);

int songListComparator(SongList *personSongList, SongList *friendSongList);

SongList *sumSonglists(SongList *personSongList, SongList *friendSongList);

SongList *duplicateSongList(SongList *list);

#endif //SONG_LIST_H