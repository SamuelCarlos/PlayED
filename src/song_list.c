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

        song = createSong(pointer, token);
        insertSongList(list, song);

        free(pointer2);

    }while(1);

    fclose(file);
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