/*
 * Copyright (C) 2017-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV05: Sat 28 Oct 2023 13:00
 * REV04: Wed 25 Mar 2020 16:00
 * REV03: Tue 26 Nov 2019 11:00
 * REV01: Fri 18 May 2018 13:00
 * START: Thu 30 Mar 2017 16:00

# INFO: UAS 2017-1 (final term)
# INFO:                   To run:   ./71-171

 * fd2=dup(fd1)  duplicates fd1 to fd2
 * O_RDWR	Open the file so that it can be read from and written to.
 * O_TRUNC	Initially clear all data from the file.
 * O_CREAT	If the file does not exist, create it. 
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define FILE "71-os171-demo.txt"

static char* str1 = "AABB\n";
static char* str2 = "CCDD\n";
static char* str3 = "EEFF\n";

void main(void) {
   int fd1, fd2, fd3;
   printf("See also file %s\n", FILE);
   /* STDIN=0, STDOUT=1, STDERR=2, therefore 
      fd1, fd2, fd3  will be 3, 4, and 5 */
   fd1 = open (FILE, O_TRUNC | O_RDWR | O_CREAT, 0644);
   fd2 = open (FILE, O_TRUNC | O_RDWR | O_CREAT, 0644);
   fd3 = dup(fd2);
   printf("fd1 = %d, fd2 = %d, fd3 = %d\n", fd1, fd2, fd3);
   write(fd1, str1, strlen(str1));
   write(fd2, str2, strlen(str2));
   write(fd3, str3, strlen(str3));
   close(fd1);
   close(fd2);
   close(fd3);
}
