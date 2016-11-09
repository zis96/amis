#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "input_playlist.h"
#include "playlist_validation.h"
#include <stdbool.h>

P_INFO* input_playlist() {
    P_INFO* user_playlist=malloc(sizeof(P_INFO));
    char* temp_input=NULL;
    int name_length=0;
    bool input_finish=false;
    user_playlist->path=malloc(sizeof(char)*(sizeof(".playlist")+1));
    //start input from keyboard
    while (input_finish==false) {
        *temp_input=getch();
        switch (*temp_input) {
        case 27:
            if (name_length==0)
                printf("\a");
            else
                input_finish=true;
            break;
        case '"':
        case '|':
        case '\\':
        case '/':
        case '*':
        case ':':
        case '?':
        case '>':
        case '<':
            printf("\a");
            break;
        default:
            name_length++;
            user_playlist->path=realloc(user_playlist->path,sizeof(char)*(sizeof(".playlist"+name_length+1)));
            strcat(user_playlist->path,temp_input);
            printf("%s\r", user_playlist->path);
        }
    };
    strcat(user_playlist->path,".playlist");
    //validating input
    user_playlist->songs_counter = validate_playlist(user_playlist->path);
    if (user_playlist->songs_counter==0) {
        printf("\nPlaylist is empty or does not exist! \n");
        return NULL;
    }
    else
        return user_playlist;
}
