/*
saves all the commands executes by the user
in /home/usr/shell_history.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>


void comm_save(char *buffer)
{
    FILE *fp;
    char home[100];
    strcpy(home,getenv("HOME"));
    strcat(home,"/shell_history.txt");

    if((fp=fopen(home,"a+b"))!=NULL){
        fputs(buffer,fp);
        fclose(fp);
        }
    else
    puts(strerror(errno));
}


void history()
{
    char buf[80];
    int counter=1;
    FILE *fp;
    char home[100];
    strcpy(home,getenv("HOME"));
    strcat(home,"/shell_history.txt");
    if((fp=fopen(home,"rb"))!=NULL){
        while(!feof(fp)){
            fgets(buf,80,fp);
            if(!feof(fp)){
                printf("%d. %s",counter,buf);
                counter++;
            }
        }
        fclose(fp);
    }
    else
    puts(strerror(errno));

}
