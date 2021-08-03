#include "../include/playlist.h"

struct Playlist {
    char* name;
    SongList* songs;
};

Playlist* createPlaylist(Playlist* playlist, char* name, SongList* songList){
    playlist = (Playlist* ) calloc(1, sizeof(Playlist));
    
    playlist->name = strdup(name);
    if(songList) {
        playlist->songs = songList;
    } else {
        playlist->songs = NULL;
    }

    return playlist;
}

void freePlaylist(Playlist* playlist){
    if(playlist->name != NULL){
        free(playlist->name);
    }
    if(playlist->songs != NULL){
        freeSongList(playlist->songs);
    }
    free(playlist);
}

void printPlaylist(Playlist* playlist){
    if(playlist->name != NULL) {
        printf("    - %s;\n", playlist->name);
        if(playlist->songs != NULL) {
            printSongList(playlist->songs);
        }
    }
}