#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define SIZE 512
void whoami(){

}

void ls(){
    char adress[SIZE];
    scanf("%s", &adress);
    DIR *dir = opendir(adress);
    struct dirent *enter;
    if (dir != NULL) {
        while((enter = readdir (dir)) != NULL) {
            printf ("%s\n", enter->d_name);
        }

        closedir (dir);
    } else {
        printf("CANT OPEN DIRECTORY\n");
    }
}
void exit_new(){
    printf("NA RAZIE :)");
    exit(0);
}
void help(){

}
void cp(char *adress_from, char *adress_to){

}
void touch(char *adress){

}
void pwd()
{
    char tmp[124];
    printf("%s ", getcwd(tmp, 124));
}
void cd(){
    char text[256] = {};
    scanf("%s", &text);
    int res = chdir(text);
    if(res != 0){
        chdir(getenv("HOME"));
    }

}


int main(int argc, char  *argv[]) {
    char line[SIZE];
    pwd();
    while(strcmp (line , "exit") != 0 ){
       char buff[256];
       getcwd(buff, 256);
       scanf("%s ", &line);
       if(strcmp(line, "cd") == 0){
             cd();
             pwd();
       }
       if (strcmp(line, "ls") == 0){
            printf("ls . - pliki w catalogu domowym\n");
            ls();
            pwd();
            //printf("\n");
       }
       if (strcmp(line, "pwd") == 0){
           pwd();
       }
    }
    exit_new();

    return 0;
}