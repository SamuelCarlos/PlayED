#ifndef PLAYLIST_LIST_H
#define PLAYLIST_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct PlaylistList PlaylistList;

#include "../include/playlist.h"

/**
 * @brief initializes and allocates space for playlist list;
 * @param list: the new playlist list ;
 * @return the allocated list ;
 */
PlaylistList* initializePlaylistList(PlaylistList* list);

/**
 * @brief creates a new cell with a new playlist and inserte the cell in list;
 * @param list: the playlist list;
 * @param playlistName;
 * @param songList the songs from the playlist ;
 * @return the playlist list with the new cell;
 */
PlaylistList* insertPlaylistList(PlaylistList* list, char* playlistName, SongList* songList);

/**
 * @brief free the playlist list struct pointer;
 * @param list: a playlist list;
 */
void freePlaylistList(PlaylistList* list);

/**
 * @brief go through the list and print your playlists;
 * @param list: a playlist list;
 */
void printPlaylistList(PlaylistList* list);

/**
 * @brief receives a playlist list and go through the list refactoring the playlists by calling the function refactoredSongList;
 * @param list: a playlist list to be refactored;
 */
PlaylistList *organizePlaylistByArtist(PlaylistList* list);

/**
 * @brief go through the list looking for a playlist;
 * @param list: a playlist list ;
 * @param playlistname: the name of the playlist being searched for;
 * @return if found, return the playlist;
 * @return if not found, return null;
 */
void* findPlaylist(PlaylistList* list,char* playlistname);

/**
 * @brief creates the files where the playlists will be printed;
 * @param list: the playlist list;
 * @param directory location where the file will be created;
 */
void createPlaylistsFiles(PlaylistList* list, char* directory);

/**
 * @brief check the number of playlists the user has;
 * @param list: the playlist list;
 * @return the number of playlists;
 */
int countPersonPlaylists(PlaylistList* list);

/**
 * @brief go through the list and print the names of your playlists to file;
 * @param file: the destination file;
 * @param list: a playlist list;
 */
void printPlaylistNameOnFile(FILE *file, PlaylistList* list);

/**
 * @brief go through two playlist lists and compare the same songs;
 * @param personSongList: the main playlist list;
 * @param friendSongList: the friend playlist list;
 * @return the amount of songs equal;
 */
int playlistsComparator(PlaylistList *personPlaylists, PlaylistList *friendPlaylists);


#endif //PLAYLIST_LIST_H