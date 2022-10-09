/* ICCS227: Project 1: icsh
 * Name: Yossatorn Phithakjiraroj
 * StudentID: 6280942
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define MAX_CMD_BUFFER 255

char *res;
char last_command[MAX_CMD_BUFFER];
void command(char *);
void my_history(char *);

int main() {
	char buffer[MAX_CMD_BUFFER];
	while(1) {
		printf("icsh $ ");
        fgets(buffer, 255, stdin);
        command(buffer);
	}
}

void command(char *buffer) {
    if (strstr(buffer, "echo")){
		my_history(buffer);
        for (res = buffer ; *res && *res != ' ' ; res++)
            ;
        if (*res) res++;
        printf("%s", res);
    } 
    else if (strstr(buffer, "!!")){
		strcpy(buffer, last_command);
		printf("%s", buffer);
		command(buffer);
    } 
    else if (strstr(buffer, "exit")) {
        for (res = buffer ; *res && *res != ' ' ; res++)
            ;
        if (*res) res++;
        if (atoi(res) && atoi(res) >= 1) {
            printf("bye\n");
            exit(atoi(res));
        } else {
            printf("bad command\n");
        }
    } else {
		printf("bad command\n");
	}
}

void my_history(char *buffer){
	strcpy(last_command, buffer);
}

void my_read(char *filename) {
	FILE * fp;
	fp = fopen(filename, "r");

	fclose(fp);
}