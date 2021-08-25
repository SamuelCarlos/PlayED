#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Friendship Friendship;

/**
 * @brief initializes and allocates space for friends list;
 * @param newFriendship: a friends list ;
 * @return the allocated list ;
 */
Friendship* initializeFriendship(Friendship* newFriendship);

/**
 * @brief creates a new cell with the new friend and insert in frendship list;
 * @param list: the friendship list;
 * @param friendName: the name of the new friend;
 * @return the list with the new cell ;
 */
Friendship* insertFriendship(Friendship* list, char* friendName);

/**
 * @brief free the friendship list;
 * @param list: a friendship list ;
 */
void freeFriendship(Friendship* list);

/**
 * @brief print the friendship list;
 * @param list: a friendship list ;
 */
void printFriendship(Friendship* friendship);

/**
 * @brief receives the name of a user and searches a list of friends if that user is on the list;
 * @param friendship: a friendship list ;
 * @param friend: the name of the friend who is being looked for;
 * @return 1: if they are friends ;
 * @return 0: if not friends;
 */
int friendIterator(Friendship* friendship, char *friend);

#endif //FRIENDSHIP_H