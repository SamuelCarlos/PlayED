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

PlaylistList* organizePlaylistByArtist(PlaylistList* list){
    Cell* aux = list->head;
    PlaylistList *newPlaylistList = NULL;

    newPlaylistList = initializePlaylistList(newPlaylistList);

    while(aux != NULL) {
        refactoredSongList(getSongList(aux->playlist),newPlaylistList);
        aux = aux->next;
    }
    freePlaylistList(list);
    return newPlaylistList;
}

void* findPlaylist(PlaylistList* list,char* playlistname){
    Cell* aux = list->head;
    while(aux != NULL){
        if(strcmp(playlistname,getPlaylistName(aux->playlist)) == 0){
            return aux->playlist;
        }
        aux = aux->next;
    }
    return NULL;
}

void createPlaylistsFiles(PlaylistList* list, char* directory){
    Cell* aux = list->head;
    FILE* file;
    char merge1[100];
    char merge2[200];
    sprintf(merge1, "data/saida/%s", directory);
    while(aux != NULL){
        sprintf(merge2, "%s/%s.txt", merge1,getPlaylistName(aux->playlist));
        file = fopen(merge2,"w");
        printPlaylistinFile(aux->playlist,file);
        fclose(file);
        aux = aux->next;
    }
}

