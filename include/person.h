#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Includes to create/verify directories
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/friendship.h"
#include "../include/playlist_list.h"

typedef struct Person Person;

Person* createPerson(char* name);

void freePerson(Person* person);

void printPerson(Person* person);

void createFriendship(Person* person, char* name);

int verifyPersonName(Person* person, char* name);

void createPlaylistList(Person* person, char* name, SongList* songList);

Person *organizePersonPlaylistByArtist(Person* person);

#endif //PERSON_H