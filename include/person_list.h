#ifndef PERSON_LIST_H
#define PERSON_LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "../include/person.h"

typedef struct PersonList PersonList;

PersonList* readFriendshipFile(PersonList* person_list);

PersonList* readPlaylistsFile(PersonList* person_list);

PersonList* initializePersonList(PersonList* list);

void insertPersonListCell(PersonList* list, Person* person);

void freePersonList(PersonList* list);

void printPersonList(PersonList* list);

void addFriend(PersonList* list, char* personName, char* friendName);

void addPlaylist(PersonList* list, char* personName, char* playlistName);

PersonList *organizePersonListPlaylistsByArtist(PersonList *list);

#endif //PERSON_LIST_H