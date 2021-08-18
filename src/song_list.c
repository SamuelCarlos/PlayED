#include "../include/song_list.h"

typedef struct Cell Cell;

struct Cell {
    Song* song;
    Cell* next;
};

struct SongList {
    Cell* head;
    Cell* tail;
};

SongList* initializeSongList(SongList* list){
    list = (SongList* ) calloc(1, sizeof(SongList));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

void insertSongList(SongList* list, Song* song){
    Cell* newPosition = NULL;

    newPosition = (Cell* ) calloc(1, sizeof(Cell));
    newPosition->song = song;
    newPosition->next = NULL;

    if(list->head == NULL) {
        list->head = newPosition;
    } else {
        list->tail->next = newPosition;
    }

    list->tail = newPosition;
}

void freeSongList(SongList* list){
    Cell* current = list->head;
    Cell* aux = NULL;

    while(current != NULL){
        if(current->song != NULL){
            freeSong(current->song);
        }
        aux = current;
        current = current->next;
        free(aux);
    }

    free(list);
}

SongList* readEachPlaylistFile(SongList* list, char* fileName){
    char *pointer = NULL, *pointer2 = NULL, *token = NULL;
    FILE *file;
    size_t bufsize;
    size_t characters;
    Song *song = NULL;

    char *fileDir = (char* ) calloc(strlen("data/entrada/") + strlen(fileName) + 1, sizeof(char));
    sprintf(fileDir, "data/entrada/%s", fileName);

    file = fopen(fileDir, "r");
    if(file == NULL)
    {
        free(fileDir);
        return NULL;
    }
    do{
        bufsize = 32;

        pointer = (char* ) calloc(bufsize, sizeof(char));

        characters = getline(&pointer, &bufsize, file);
        if(characters == -1)
        {
            free(pointer);
            break;
        }
        if(pointer[(int)characters - 1] == '\n'){
            pointer[(int)characters - 1] = '\0';
        }
        pointer2 = pointer;

        token = strtok_r(pointer, "-", &pointer);
        if(token == NULL){
            free(pointer);
            break;
        }
        token[strlen(token) - 1] = '\0';

        song = createSong(pointer, token);
        insertSongList(list, song);

        free(pointer2);

    }while(1);

    fclose(file);
    // remove(fileDir);
    free(fileDir);

    return list;
}

void printSongList(SongList* list){
    Cell* aux = list->head;

    while(aux != NULL) {
        if(aux->song) {
            printSong(aux->song);
        }
        aux = aux->next;
    }
}

void refactoredSongList(SongList* list, PlaylistList* playlistlist){
    Cell* aux = list->head;
    Playlist* playlistaux;
    
    while(aux != NULL){
        playlistaux = findPlaylist(playlistlist, getArtistName(aux->song));

        if(playlistaux == NULL){
            Song* newsong = createSong(getSongName(aux->song), getArtistName(aux->song));
            SongList* newsonglist = initializeSongList(newsonglist);
            insertSongList(newsonglist, newsong);
            insertPlaylistList(playlistlist,getArtistName(aux->song), newsonglist);
        }
        else{
            Song* newsong = createSong(getSongName(aux->song), getArtistName(aux->song));
            insertSongList(getSongList(playlistaux), newsong);
        }
    
        aux = aux->next;
   }
}

void printSongListinFile(SongList* list,FILE* file){
    Cell* aux = list->head;

    while(aux != NULL) {
        if(aux->song) {
            printSonginFile(aux->song,file);
        }
        aux = aux->next;
    }
}

int songListComparator(SongList *personSongList, SongList *friendSongList) {
    Cell *aux = personSongList->head;
    Cell *iteratorAux = NULL;
    int equalSongs = 0;

    while(aux != NULL) {
        iteratorAux = friendSongList->head;

        while(iteratorAux != NULL) {
            if(aux->song && iteratorAux->song) {
                if(strcmp(getSongName(aux->song), getSongName(iteratorAux->song)) == 0) {
                    equalSongs++;
                }
            }

            iteratorAux = iteratorAux->next;
        }

        aux = aux->next;
    }

    return equalSongs;
}

SongList *sumSonglists(SongList *personSongList, SongList *friendSongList) {
    Cell *aux = personSongList->head;
    Cell *iteratorAux = NULL;
    Cell *newSongListIterator = NULL;
    SongList *newSongList = NULL;
    int hasEqualSong = 0;

    newSongList = initializeSongList(newSongList);

    aux = personSongList->head;
    while (aux != NULL) {
        hasEqualSong = 0;
        newSongListIterator = newSongList->head;

        while(newSongListIterator != NULL) {
            if(strcmp(getSongName(newSongListIterator->song), getSongName(aux->song)) == 0) {
                hasEqualSong = 1;
                break;
            }
            
            newSongListIterator = newSongListIterator->next;
        }
        if(!hasEqualSong) {
            Song* newSong = createSong(getSongName(aux->song), getArtistName(aux->song));
            insertSongList(newSongList, newSong);
        }
        aux = aux->next;
    }

    iteratorAux = friendSongList->head;
    while (iteratorAux != NULL) {
        hasEqualSong = 0;
        newSongListIterator = newSongList->head;

        while(newSongListIterator != NULL) {    
            if(strcmp(getSongName(newSongListIterator->song), getSongName(iteratorAux->song)) == 0) {
                hasEqualSong = 1;
            }
    
            newSongListIterator = newSongListIterator->next;
        }
        if(!hasEqualSong) {
            Song* newSong = createSong(getSongName(iteratorAux->song), getArtistName(iteratorAux->song));
            insertSongList(newSongList, newSong);
        }
        
        iteratorAux = iteratorAux->next;
    }

   
    return newSongList;
}

SongList *duplicateSongList(SongList *list) {
    Cell *aux = list->head;

    SongList *newSongList = NULL;
    newSongList = initializeSongList(newSongList);

    while(aux != NULL) {
        if(aux->song) {
            Song* newSong = createSong(getSongName(aux->song), getArtistName(aux->song));
            insertSongList(newSongList, newSong);
        }

        aux = aux->next;
    }

    return newSongList;
}