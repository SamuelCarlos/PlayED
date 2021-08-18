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

Playlist* initializePlaylist(Playlist* newplaylist){
    newplaylist = (Playlist*) calloc(1,sizeof(Playlist));
    newplaylist->name = NULL;
    newplaylist->songs = NULL;
    return newplaylist;
}

Playlist* refactoredPlaylist(Playlist* playlist){
    return playlist;
}

SongList* getSongList(Playlist* playlist){
    return playlist->songs;
}

char* getPlaylistName(Playlist* playlist){
    return playlist->name;
}

void printPlaylistinFile(Playlist* playlist, FILE* file){
        if(playlist->songs != NULL) {
            printSongListinFile(playlist->songs,file);
        }
}

int musicsComparator(Playlist *personPlaylist, Playlist *friendPlaylist) {
    return songListComparator(personPlaylist->songs, friendPlaylist->songs);
}

Playlist* joinPlaylistSongs(Playlist *personPlaylist, Playlist *friendPlaylist) {
    SongList *aux;

    aux = sumSonglists(personPlaylist->songs, friendPlaylist->songs);

    freeSongList(personPlaylist->songs);
    freeSongList(friendPlaylist->songs);
    
    personPlaylist->songs = duplicateSongList(aux);
    friendPlaylist->songs = duplicateSongList(aux);

    freeSongList(aux);

    return personPlaylist;
}