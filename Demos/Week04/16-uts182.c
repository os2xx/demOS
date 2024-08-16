/*
 * Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2018-2 (midterm)
 * REV03: Thu 26 Oct 2023 20:00
 * REV02: Sun 23 Feb 2020 16:00
 * REV01: Thu 17 Jan 2019 15:00
 * START: Mon 01 Jan 2018 00:00
 *
 * long int = 64 bits
 */

#include <stdio.h>

unsigned char  string[]="0123456789ABCDE";
unsigned long  longst=(unsigned long) string;
unsigned char* achar;

void main(void) {
   achar=(unsigned char*) &longst;
   printf("(0) %p\n",  string);
   printf("(1) %p\n", &longst);
   printf("(2) %p\n",  &achar);
   printf("(3) %p\n",   achar);
   printf("(4) %#X\n", *achar);
   printf("(5) %#16.16lx\n",longst);
}

