#include "../include/song.h"

struct Song {
    char* name;
    char* artist;
};

Song* createSong(char* name, char* artist){
    Song* newSong = (Song* ) calloc(1, sizeof(Song));

    newSong->name = strdup(name);
    newSong->artist = strdup(artist);

    return newSong;
}

void freeSong(Song* song){
    if(song->name != NULL){
        free(song->name);
    }
    if(song->artist != NULL){
        free(song->artist);
    }
    free(song);
}

void printSong(Song* song) {
    if(song->name && song->artist) {
        printf("        .%s -%s\n", song->artist, song->name);
    }
}

char *getArtistName(Song *song) {
    return song->artist;
}

char *getSongName(Song *song) {
    return song->name;
}

void printSonginFile(Song* song, FILE* file) {
    if(song->name && song->artist) {
        fprintf(file,"%s -%s\n", song->artist, song->name);
    }
}
