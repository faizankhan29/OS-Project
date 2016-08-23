#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>


int main(int argc,char *argv[],char *envp[]){

    FILE *fp;
    fp=fopen("/proc/net/dev","r");
    if(fp==NULL){
        fprintf(stderr,"Cannot open %s\n",argv[1]);
        exit(1);
    }

    char c;
    c=getc(fp);
    while(c!=EOF){
        putchar(c);
        c=getc(fp);
    }
    fclose(fp);

    return 0;
}
