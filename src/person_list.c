#include "../include/person_list.h"

typedef struct Cell Cell;

struct Cell {
    Person* person;
    Cell* next;
    Cell* prev;
};

struct PersonList {
    Cell* head;
    Cell* tail;
};


PersonList* readFriendshipFile(PersonList* person_list) {
    int row_parser;
    char *pointer = NULL, *pointer2 = NULL, *token = NULL, *token2 = NULL;
    FILE *file;
    size_t bufsize;
    size_t characters;
    Person* newPerson = NULL;

    file = fopen("data/entrada/amizade.txt", "r");
    if(file == NULL)
    {
        return NULL;
    }

    row_parser = 0;
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

        token = strtok_r(pointer, ";", &pointer);
        if(token == NULL){
            free(pointer);
            break;
        }

        while(token != NULL){
            if(row_parser == 0){
                newPerson = createPerson(token);
                insertPersonListCell(person_list, newPerson);
                token = strtok_r(NULL, ";", &pointer);
            }else{
                token2 = strdup(token);
                token = strtok_r(NULL, ";", &pointer);

                addFriend(person_list, token2, token);
                addFriend(person_list, token, token2);
                
                free(token2);
                token = strtok_r(NULL, ";", &pointer);
            }
        }
       
        free(pointer2);
        row_parser++;

    }while(1);

    fclose(file);

    return person_list;
}

PersonList* readPlaylistsFile(PersonList* person_list){
    int playlist_counter, i;
    char *pointer = NULL, *pointer2 = NULL, *token = NULL, *personName = NULL;
    FILE *file;
    size_t bufsize;
    size_t characters;
    Person *newPerson = NULL;

    file = fopen("data/entrada/playlists.txt", "r");
    if(file == NULL)
    {
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

        token = strtok_r(pointer, ";", &pointer);
        if(token == NULL){
            free(pointer);
            break;
        }
        personName = strdup(token);

        token = strtok_r(NULL, ";", &pointer);
        playlist_counter = atoi(token);

        for(i = 0; i < playlist_counter; i++) {
            token = strtok_r(NULL, ";", &pointer);
            addPlaylist(person_list, personName, token);
        }

        free(personName);
        free(pointer2);

    }while(1);

    fclose(file);

    return person_list;
}

PersonList* initializePersonList(PersonList* list) {
    list = (PersonList* ) calloc(1, sizeof(PersonList));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

void insertPersonListCell(PersonList* list, Person* person) {
    Cell* newPosition = NULL;

    newPosition = (Cell* ) calloc(1, sizeof(Cell));
    newPosition->person = person;
    newPosition->next = NULL;

    if(list->head == NULL) {
        list->head = newPosition;
        newPosition->prev = NULL;
    } else {
        newPosition->prev = list->tail;
        list->tail->next = newPosition;
    }

    list->tail = newPosition;
}

void freePersonList(PersonList* list) {
    Cell* current = list->head;
    Cell* aux = NULL;

    while(current != NULL) {
        if(current->person != NULL){
            freePerson(current->person);
        }
        aux = current;
        current = current->next;
        free(aux);
    }

    free(list);
}

void printPersonList(PersonList* list){
    Cell* aux = list->head;

    while(aux != NULL) {
        printPerson(aux->person);
        aux = aux->next;
    }
}

void addFriend(PersonList* list, char* personName, char* friendName){
    Cell* aux = list->head;

    while(aux != NULL) {
        if(verifyPersonName(aux->person, personName)) {
            createFriendship(aux->person, friendName);
            break;
        }
        aux = aux->next;
    }
}

void addPlaylist(PersonList* list, char* personName, char* playlistName){
    Cell* aux = list->head;
    SongList *songList = NULL;

    while(aux != NULL) {
        if(verifyPersonName(aux->person, personName)) {
            songList = initializeSongList(songList);
            songList = readEachPlaylistFile(songList, playlistName);
            createPlaylistList(aux->person, playlistName, songList);
            break;
        }
        aux = aux->next;
    }
}

PersonList *organizePersonListPlaylistsByArtist(PersonList *list) {
    Cell *aux = list->head;
    FILE *refactored = NULL;

    refactored = fopen("data/saida/played-refatorada.txt", "w");

    while(aux != NULL) {    
        if(aux->person){
            aux->person = organizePersonPlaylistByArtist(aux->person);     
            fillRefactoredFile(refactored, aux->person);       
            if(aux->next != NULL) fprintf(refactored, "\n"); 
        }

        aux = aux->next;
    }

    fclose(refactored);
    return list;
}

void createOutputFiles(PersonList *list) {
    Cell *aux = list->head;

    
    while(aux != NULL) {    
        if(aux->person){
            organizeFilesPersonPlaylistByArtist(aux->person);     
        }

        aux = aux->next;
    }
}

void createSimilarities(PersonList *list) {
    Cell *aux = list->head;
    Cell *iteratorAux = NULL;
    FILE *similarities = NULL;
    int equalPlaylists = 0;

    similarities = fopen("data/saida/similaridades.txt", "w");

    while(aux != NULL) {    
        iteratorAux = aux->next;

        while(iteratorAux != NULL) {
            if(verifyFriendship(aux->person, getPersonName(iteratorAux->person))) {
                equalPlaylists = verifyEqualPlaylists(aux->person, iteratorAux->person);
                fprintf(similarities, "%s;%s;%d\n", getPersonName(aux->person), getPersonName(iteratorAux->person), equalPlaylists);
            }
            iteratorAux = iteratorAux->next;
        }

        aux = aux->next;
    }

    fclose(similarities);
}

PersonList *merge(PersonList *list) {
    Cell *aux = list->head;
    Cell *iteratorAux = NULL;

    while(aux != NULL) {
        iteratorAux = list->head;
        
        while (iteratorAux != NULL) {
            if(aux->person && iteratorAux->person) {
                 if(verifyFriendship(aux->person, getPersonName(iteratorAux->person))) {
                    aux->person = mergePersonWithFriend(aux->person,iteratorAux->person);
                }
            }

            iteratorAux = iteratorAux->next;
        }
        aux = aux->next;
    }

    aux = list->tail;
    while(aux != NULL) {
        iteratorAux = list->tail;
         while (iteratorAux != NULL) {
            if(aux->person && iteratorAux->person) {
                 if(verifyFriendship(aux->person, getPersonName(iteratorAux->person))) {
                    aux->person = mergePersonWithFriend(aux->person,iteratorAux->person);
                }
            }

            iteratorAux = iteratorAux->prev;
        }
        aux = aux->prev;
    }

    return list;
}