#ifndef SONG_H
#define SONG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song Song;

/**
 * @brief receives the song data and create a new song;
 * @param name: the song name;
 * @param artist: the artist;
 * @return the new song;
 */
Song* createSong(char* name, char* artist);

/**
 * @brief free the song struct pointer;
 * @param song: a song struct pointer;
 */
void freeSong(Song* song);

/**
 * @brief print the song data;
 * @param song: a song struct pointer;
 */
void printSong(Song* song);

/**
 * @brief receives a song and get the artist name;
 * @param song: a song struct pointer;
 * @return string with the artist name;
 */
char *getArtistName(Song *song);

/**
 * @brief receives a song and get the song name;
 * @param song: a song struct pointer;
 * @return string with the song name;
 */
char *getSongName(Song *song);

/**
 * @brief print the song data in a file;
 * @param song: a song struct pointer;
 * @param file: the destination file;
 */
void printSonginFile(Song* song,FILE* file);

#endif //SONG_H