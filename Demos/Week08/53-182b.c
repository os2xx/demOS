/*
 Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 You are free to SHARE (copy and 
 redistribute the material in any medium
 or format) and to ADAPT (remix, 
 transform, and build upon the material 
 for any purpose, even commercially).
 This program is distributed in the hope 
 that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied 
 warranty of MERCHANTABILITY or FITNESS 
 FOR A PARTICULAR PURPOSE.

 * REV07: Sat 28 Oct 2023 12:00
 * REV06: Wed 25 Mar 2020 12:00
 * REV05: Tue 07 May 2019 20:00
 * REV04: Tue 11 Dec 2018 10:00
 * START: Wed 14 Nov 2018 20:00

# INFO: UAS 2018-2 (final term)
# INFO:                   Run from: ./51-182 

 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MYFLAGS     O_CREAT | O_RDWR
#define MYPROTECT PROT_READ | PROT_WRITE
#define MYVISIBILITY          MAP_SHARED 
#define SFILE             "demo-file.bin"

typedef  struct {
   sem_t  sync[3];
   int    share;
   int    loop;
   pid_t  relative;
} myshare;

myshare* mymap;

void flushprintf(char* tag1, char* tag2){
   printf("%s[%s] loop%d relative(%d)\n", 
      tag1, tag2, mymap->loop, 
      getpid()  + mymap->relative);
   fflush(NULL);
}

void main(int argc, char* argv[]) {
   int fd  =open(SFILE,MYFLAGS,S_IRWXU);
   int ssize=sizeof(myshare);
   mymap=mmap(NULL, ssize, MYPROTECT, 
              MYVISIBILITY, fd, 0);
   sem_post (&(mymap->sync[1]));
   sem_wait (&(mymap->sync[2]));
   mymap->share=2000;
   flushprintf(argv[0], "PASS");
   sem_post (&(mymap->sync[1]));
   while (mymap->loop) {
      for(int ii=0; ii<1000000; ii++);
      mymap->share--;
   }
   sem_post (&(mymap->sync[1]));
   sem_wait (&(mymap->sync[2]));
   sem_wait (&(mymap->sync[2]));
   flushprintf(argv[0], "EXIT");
   sem_post (&(mymap->sync[0]));
   close(fd);
}

