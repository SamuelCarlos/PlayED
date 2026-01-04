#include "../include/friendship.h"

typedef struct Cell Cell;

struct Cell {
    char* friendName;
    Cell* next;
};

struct Friendship {
    Cell* head;
    Cell* tail;
};

Friendship* initializeFriendship(Friendship* newFriendship){
    newFriendship = (Friendship* ) calloc(1, sizeof(Friendship));
    newFriendship->head = NULL;
    newFriendship->tail = NULL;

    return newFriendship;
}

Friendship* insertFriendship(Friendship* list, char* friendName) {
    Cell* newPosition = NULL;

    newPosition = (Cell* ) calloc(1, sizeof(Cell));
    newPosition->friendName = strdup(friendName);
    newPosition->next = NULL;

    if(list->head == NULL) {
        list->head = newPosition;
    } else {
        list->tail->next = newPosition;
    }

    list->tail = newPosition;

    return list;
}

void freeFriendship(Friendship* list) {
    Cell* current = list->head;
    Cell* aux = NULL;

    while(current != NULL) {
        if(current->friendName){
            free(current->friendName);
        }
        aux = current;
        current = current->next;
        free(aux);
    }

    free(list);
}

void printFriendship(Friendship* friendship) {
    Cell* aux = friendship->head;

    while(aux != NULL){
        printf("%s; ", aux->friendName);
        aux = aux->next;
    }
}

int friendIterator(Friendship* friendship, char *friend) {
    Cell *aux = friendship->head;

    while(aux != NULL){
        if(strcmp(aux->friendName, friend) == 0) return 1;

        aux = aux->next;
    }
    return 0;
}