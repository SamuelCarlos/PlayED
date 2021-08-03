#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Friendship Friendship;

Friendship* initializeFriendship(Friendship* newFriendship);

Friendship* insertFriendship(Friendship* list, char* friendName);

void freeFriendship(Friendship* list);

void printFriendship(Friendship* friendship);

#endif //FRIENDSHIP_H