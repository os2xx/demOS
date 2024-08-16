/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV09: Thu 26 Oct 2023 20:00
 * REV08: Tue 28 Sep 2021 21:00
 * REV07: Fri 02 Apr 2021 07:00
 * REV05: Sun 23 Feb 2020 16:00
 * REV04: Tue 28 Aug 2018 18:00
 * START: Tue 20 Sep 2016 17:00
 */

#include <stdio.h>
#define HEAD1 "VARIABLE + VALUE +CHR+ ++++ ADDRESS  ++++\n"

void main(void) {
   /* Local Variables in Stack Segment */
   unsigned char varchr0='a';
   unsigned char varchr1='b';
   unsigned char varchr2='c';
   unsigned char varchr3='d';
   unsigned char varchr4='e';
   unsigned char varchr5='f';
   unsigned char varchr6='g';
   unsigned char varchr7='h';
   printf(HEAD1);
   printf("varchr0  =  %#4X = %c   %#16.16lX\n", varchr0, varchr0, &varchr0);
   printf("varchr1  =  %#4X = %c   %#16.16lX\n", varchr1, varchr1, &varchr1);
   printf("varchr2  =  %#4X = %c   %#16.16lX\n", varchr2, varchr2, &varchr2);
   printf("varchr3  =  %#4X = %c   %#16.16lX\n", varchr3, varchr3, &varchr3);
   printf("varchr4  =  %#4X = %c   %#16.16lX\n", varchr4, varchr4, &varchr4);
   printf("varchr5  =  %#4X = %c   %#16.16lX\n", varchr5, varchr5, &varchr5);
   printf("varchr6  =  %#4X = %c   %#16.16lX\n", varchr6, varchr6, &varchr6);
   printf("varchr7  =  %#4X = %c   %#16.16lX\n", varchr7, varchr7, &varchr7);
}

/*
varchr0  =  0X61 = a   0X00007FEEDDCCBBFF
varchr1  =  0X62 = b   0X00007FEEDDCCBBFE
varchr2  =  0X63 = c   0X00007FEEDDCCBBFD
varchr3  =  0X64 = d   0X00007FEEDDCCBBFC
varchr4  =  0X65 = e   0X00007FEEDDCCBBFB
varchr5  =  0X66 = f   0X00007FEEDDCCBBFA
varchr6  =  0X67 = g   0X00007FEEDDCCBBF9
varchr7  =  0X68 = h   0X00007FEEDDCCBBF8

                      0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
0000 7FEE DDCC BBF0   -  -  -  -  -  -  -  - 68 67 66 65 64 63 62 61
*/

