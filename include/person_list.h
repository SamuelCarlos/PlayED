#ifndef PERSON_LIST_H
#define PERSON_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct PersonList PersonList;

#include "../include/person.h"

/**
 * @brief read the friendship file and create the necessary structures saving it in the person list passed;
 * @param person_list: the person list;
 * @return the person list filled with the friendship relationships;
 */
PersonList* readFriendshipFile(PersonList* person_list);

/**
 * @brief read the playlists file and create the necessary structures saving it in the person list passed;
 * @param person_list: the person list;
 * @return the person list filled with the playlists;
 */
PersonList* readPlaylistsFile(PersonList* person_list);

/**
 * @brief initializes and allocates space for person list;
 * @param list: a person list ;
 * @return the allocated list ;
 */
PersonList* initializePersonList(PersonList* list);

/**
 * @brief creates a new cell with the new person and insert in person list;
 * @param list: the person list;
 * @param person: the new person;
 * @return the list with the new cell ;
 */
void insertPersonListCell(PersonList* list, Person* person);

/**
 * @brief free the person list;
 * @param list: a person list ;
 */
void freePersonList(PersonList* list);

/**
 * @brief print the person list ;
 * @param list: a person list ;
 */
void printPersonList(PersonList* list);

/**
 * @brief takes the main person name for to search the list and the friend name that will be added to your list and generates this friendship;
 * @param list: the person list;
 * @param personName: the main person name for to search the list;
 * @param friendName: the new friend name;
 */
void addFriend(PersonList* list, char* personName, char* friendName);

/**
 * @brief takes the main person name for to search the list and the new playlist name that will be added to your list and generates this friendship;
 * @param list: the person list;
 * @param personName: the main person for to search the list;
 * @param playlistName: the new playlist name;
 */
void addPlaylist(PersonList* list, char* personName, char* playlistName);

/**
 * @brief receives the person list and refactors their playlists by calling the function organizePersonPlaylistByArtist;
 * @param list: a person list;
 * @return the person list with the refactored playlists;
 */
PersonList *organizePersonListPlaylistsByArtist(PersonList *list);

/**
 * @brief receives the person list and create the similarities file;
 * @param list: a person list;
 */
void createSimilarities(PersonList *list);

/**
 * @brief receives the person list and create the all output files;
 * @param list: a person list;
 */
void createOutputFiles(PersonList *list);


#endif //PERSON_LIST_H