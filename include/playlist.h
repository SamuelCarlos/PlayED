#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Playlist Playlist;

#include "../include/song_list.h"

/**
 * @brief receives the playlist data and create a new playlist;
 * @param name: the playlist name;
 * @param songList: the song list;
 * @return the new playlist;
 */
Playlist* createPlaylist(Playlist* playlist, char* name, SongList* songList);

/**
 * @brief free the playlist struct pointer;
 * @param playlist: a playlist struct pointer;
 */
void freePlaylist(Playlist* playlist);

/**
 * @brief print the playlist name and call the function printSongList;
 * @param playlist: a playlist ;
 */
void printPlaylist(Playlist* playlist);

/**
 * @brief initializes and allocates space for playlist;
 * @param playlist: a new playlist ;
 * @return the allocated playlist struct ;
 */
Playlist* initializePlaylist(Playlist* playlist);

/**
 * @brief receives a playlist and get your song list;
 * @param playlist: a playlist;
 * @return the song list;
 */
SongList* getSongList(Playlist* playlist);

/**
 * @brief receives a playlist and get your name;
 * @param playlist: a playlist;
 * @return string with the playlist name;
 */
char* getPlaylistName(Playlist* playlist);

/**
 * @brief print the playlist data in a file;
 * @param plalyist: a playlist struct pointer;
 * @param file: the destination file;
 */
void printPlaylistinFile(Playlist* playlist,FILE* file);

/**
 * @brief call the function songListComparator;
 * @param personPlayList: the main playlist;
 * @param friendPlayList: the friend playlist;
 * @return the amount of songs equal;
 */
int musicsComparator(Playlist *personPlaylist, Playlist *friendPlaylist);

#endif //PLAYLIST_H