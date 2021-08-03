#include "../include/application.h"

/** 
 * 
 */
int startApplication() {
    PersonList* person_list = NULL;
    PlaylistList* playlists = NULL;

    // initialize and feed a person list with files data
    person_list = initializePersonList(person_list);
    person_list = readFriendshipFile(person_list);
    person_list = readPlaylistsFile(person_list);
    
    printPersonList(person_list);

    person_list = organizePersonListPlaylistsByArtist(person_list);

    freePersonList(person_list);
    return 1;
}