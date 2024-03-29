#include "../include/person.h"

struct Person {
    char* name;
    Friendship* friends;
    PlaylistList* playlists;
};

struct stat dir = {0};

Person* createPerson(char* name) {
    Person* newPerson = (Person* ) calloc(1, sizeof(Person));
    
    newPerson->name = strdup(name);
    newPerson->friends = NULL;
    newPerson->playlists = NULL;

    return newPerson;
}

void freePerson(Person* person){
    if(person->name != NULL)
        free(person->name);
    if(person->friends != NULL)
        freeFriendship(person->friends);
    if(person->playlists != NULL)
        freePlaylistList(person->playlists);
    if(person != NULL)
        free(person);
}

void printPerson(Person* person){
    printf("Name: %s\n", person->name);
    printf("Friends: ");
    if(person->friends != NULL) {
        printFriendship(person->friends);
    }
    printf("\n");
    printf("Playlists:\n");
    if(person->playlists != NULL){
        printPlaylistList(person->playlists);
    }
    printf("\n");
}

void createFriendship(Person* person, char* name){
    if(person->friends == NULL){
        person->friends = initializeFriendship(person->friends);
    }
    person->friends = insertFriendship(person->friends, name);
}

int verifyPersonName(Person* person, char* name) {
    if(strcmp(person->name, name) == 0) return 1;

    return 0;
}

void createPlaylistList(Person* person, char* name, SongList* songList) {
    if(person->playlists == NULL) {
        person->playlists = initializePlaylistList(person->playlists);
    }
    person->playlists = insertPlaylistList(person->playlists, name, songList);
}

Person *organizePersonPlaylistByArtist(Person* person) {
    char *directory = NULL;
    
    if(person->playlists && person->name){
        directory = (char *) calloc((int) strlen("data/saida/") + (int) strlen(person->name) + 1, sizeof(char));
        sprintf(directory, "data/saida/%s", person->name);
        if(stat(directory, &dir) == -1) {
            mkdir(directory, 0755);
        }
        free(directory);

        

        person->playlists = organizePlaylistByArtist(person->playlists);
    }

    return person;
}