#include "../include/application.h"

/** 
 * 
 */
void startApplication() {
    PersonList* person_list = NULL;
    PlaylistList* playlists = NULL;
    // initialize and feed a person list with files data
    person_list = initializePersonList(person_list);
    // read friendship file and feed person list
    person_list = readFriendshipFile(person_list);
    // read playlists file and feed person list
    person_list = readPlaylistsFile(person_list);
    
    // printPersonList(person_list);
    
    person_list = organizePersonListPlaylistsByArtist(person_list);
    // printPersonList(person_list);

    createOutputFiles(person_list);

    createSimilarities(person_list);

    freePersonList(person_list);
}