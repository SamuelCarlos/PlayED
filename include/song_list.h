#ifndef SONG_LIST_H
#define SONG_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct SongList SongList;

#include "../include/song.h"
#include "../include/playlist_list.h"

/**
 * @brief initializes and allocates space for song list;
 * @param list: the new song list ;
 * @return the allocated list ;
 */
SongList* initializeSongList(SongList* list);

/**
 * @brief creates a new cell with the new song and insert in song list;
 * @param list: the song list;
 * @param song the music to be inserted ;
 */
void insertSongList(SongList* list, Song* song);

/**
 * @brief free the song list;
 * @param list: a song list ;
 */
void freeSongList(SongList* list);

/**
 * @brief receives a playlist file read the file and save the songs in a song list;
 * @param list: the song list ;
 * @param fileName: the file directory ;
 * @return the song list filled with songs from the file ;
 */
SongList* readEachPlaylistFile(SongList* list, char* fileName);

/**
 * @brief print the songs of the song list;
 * @param list: a song list;
 */
void printSongList(SongList* list);

/**
 * @brief receives a song list and refactors it by artist names. After refactoring inserts the new lists into a playlist list;
 * @param list: a song list to be refactored;
 * @param playlistlist: a playlist list where the new lists will be inserted;
 */
void refactoredSongList(SongList* list,PlaylistList* playlistlist);

/**
 * @brief print the songs of the song list in a file;
 * @param list: a song list;
 * @param file: the destination file;
 */
void printSongListinFile(SongList* list,FILE* file);

/**
 * @brief go through two song lists and compare the same songs;
 * @param personSongList: the main song list;
 * @param friendSongList: the friend song list;
 * @return the amount of songs equal;
 */
int songListComparator(SongList *personSongList, SongList *friendSongList);


#endif //SONG_LIST_H