/* ICCS227: Project 1: icsh
 * Name: Yossatorn Phithakjiraroj
 * StudentID: 6280942
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_CMD_BUFFER 255

void command(char *);
void check_rest(char *);

int main() {
    char buffer[MAX_CMD_BUFFER];
    while (1) {
        printf("icsh $ ");
        fgets(buffer, 255, stdin);
        command(buffer);
        // printf("%c", buffer[1]);
        // printf("you said: %s\n", buffer);
    }
}

void command(char *buffer) {
    if (strstr(buffer, "echo")){
        char *res;
        for (res = buffer ; *res && *res != ' ' ; res++)
            ;
        if (*res) res++;
        printf("%s", res);
    } 
    else if (strstr(buffer, "!!")){
        printf("Good");
    } 
    else if (strstr(buffer, "exit")) {
        printf("Bye");
    }
}

void check_rest(char *) {
    
}
