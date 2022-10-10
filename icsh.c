/* ICCS227: Project 1: icsh
 * Name: Yossatorn Phithakjiraroj
 * StudentID: 6280942
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_BUFFER 255

int i, status, pid;
char *res, last_command[MAX_CMD_BUFFER], *argv[3];
void command(char *), my_history(char *), my_read(char *);

int main(int argc, char * argv []) {
	char buffer[MAX_CMD_BUFFER];
	if (argc > 1) {
		my_read(argv[1]);
	}
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
		// printf("%s", buffer);
		command(buffer);
    } 
    else if (strstr(buffer, "exit")) {
        for (res = buffer ; *res && *res != ' ' ; res++)
            ;
        if (*res) res++;
        if (atoi(res) && atoi(res) >= 1) {
            // printf("bye\n");
            exit(atoi(res));
        } 
		// else { printf("bad command\n"); }
    } else {
		pid = fork();
		if (!pid) {
			system(buffer);
		}
		if (pid) {
			waitpid(pid, NULL, 0);
		}
	}
}

void my_history(char *buffer){
	strcpy(last_command, buffer);
}

void my_read(char *filename) {
	FILE* ptr;
    ptr = fopen(filename, "r");
	char line[500];
	while (fgets(line, sizeof(line), ptr)) {
		command(line);
	}
    fclose(ptr);
}