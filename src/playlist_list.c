#include "../include/playlist_list.h"

typedef struct Cell Cell;

struct Cell {
    Playlist* playlist;
    Cell* next;
};

struct PlaylistList {
    Cell* head;
    Cell* tail;
};

PlaylistList* initializePlaylistList(PlaylistList* list){
    list = (PlaylistList* ) calloc(1, sizeof(PlaylistList));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

PlaylistList* insertPlaylistList(PlaylistList* list, char* playlistName, SongList* songList){
    Cell* newPosition = NULL;

    newPosition = (Cell* ) calloc(1, sizeof(Cell));
    newPosition->playlist = createPlaylist(newPosition->playlist, playlistName, songList);
    newPosition->next = NULL;

    if(list->head == NULL) {
        list->head = newPosition;
    } else {
        list->tail->next = newPosition;
    }

    list->tail = newPosition;

    return list;
}

void freePlaylistList(PlaylistList* list){
    Cell* current = list->head;
    Cell* aux = NULL;

    while(current != NULL){
        if(current->playlist != NULL){
            freePlaylist(current->playlist);
        }
        aux = current;
        current = current->next;
        free(aux);
    }

    free(list);
}

void printPlaylistList(PlaylistList* list){
    Cell *aux = list->head;

    while(aux != NULL) {
        if(aux->playlist != NULL){
            printPlaylist(aux->playlist);
        }
        aux = aux->next;
    }
}

PlaylistList *organizePlaylistByArtist(PlaylistList* list){
    Cell *aux = list->head;
    PlaylistList *newPlaylistList = NULL;
    char *newPlaylistName = NULL;

    newPlaylistList = initializePlaylistList(newPlaylistList);

    while(aux != NULL) {
        newPlaylistList = createNewPlaylistByArtistName(newPlaylistList, aux->playlist);
        aux = aux->next;
    }

    return newPlaylistList;
}

PlaylistList *createNewPlaylistByArtistName(PlaylistList *newPlaylistList, Playlist *playlist) {
    Playlist *newPlaylist = NULL;

    newPlaylist = initializePlaylist(newPlaylist);

    
}