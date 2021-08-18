#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Includes to create/verify directories
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct Person Person;

#include "../include/friendship.h"
#include "../include/playlist_list.h"

Person* createPerson(char* name);

void freePerson(Person* person);

void printPerson(Person* person);

void createFriendship(Person* person, char* name);

int verifyPersonName(Person* person, char* name);

void createPlaylistList(Person* person, char* name, SongList* songList);

Person *organizePersonPlaylistByArtist(Person* person);

void fillRefactoredFile(FILE *file, Person* person);

char *getPersonName(Person *person);

int verifyFriendship(Person *person, char *friend);

int verifyEqualPlaylists(Person *person, Person *friend);

void organizeFilesPersonPlaylistByArtist(Person *person);

Person *mergePersonWithFriend(Person *person, Person *friend);

#endif //PERSON_H