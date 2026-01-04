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

/**
 * @brief receives the person name and create a new person;
 * @param name: the person name;
 * @return the new struct person;
 */
Person* createPerson(char* name);

/**
 * @brief free the person struct pointer;
 * @param person: a person struct pointer;
 */
void freePerson(Person* person);

/**
 * @brief print the person data calling others functions;
 * @param person: a person struct pointer;
 */
void printPerson(Person* person);

/**
 * @brief creates a friendship between the main person and another persons;
 * @param person: a person struct pointer;
 * @param name: the friend name;
 */
void createFriendship(Person* person, char* name);

/**
 * @brief checks if the name passed is the same that is in the person struct passed;
 * @param person: a person struct pointer;
 * @param name: the name for verify;
 */
int verifyPersonName(Person* person, char* name);

/**
 * @brief creates a playlist list for the person ;
 * @param person: a person struct pointer;
 * @param name: the playlists names;
 * @param songList: the playlists songs;
 */
void createPlaylistList(Person* person, char* name, SongList* songList);

/**
 * @brief receives the person and refactors their playlists by calling the function organizePlaylistByArtist;
 * @param person: a person struct pointer;
 * @return the person with the refactored playlists;
 */
Person *organizePersonPlaylistByArtist(Person* person);

/**
 * @brief prints the data from the "played-refactored.txt" file to the file;
 * @param file the destination file;
 * @param person: a person struct pointer;
 */
void fillRefactoredFile(FILE *file, Person* person);

/**
 * @brief receives a person and get their name;
 * @param person: a person struct pointer;
 * @return string with the name;
 */
char *getPersonName(Person *person);

/**
 * @brief receives a person and a friend's name, checks if they are really friends;
 * @param person: a person struct pointer;
 * @param friend: tha friend name;
 * @return 1 if they are;
 * @return 0 if not;
 */
int verifyFriendship(Person *person, char *friend);

/**
 * @brief receives a main person and a friend person, checks the amount of equal playlists;
 * @param person: a main person struct;
 * @param friend: friend person struct;
 * @return amount of equal playlists;
 */
int verifyEqualPlaylists(Person *person, Person *friend);

/**
 * @brief creates the new files where the refactored playlists will be printed;
 * @param person: a person struct pointer;
 */
void organizeFilesPersonPlaylistByArtist(Person *person);


#endif //PERSON_H