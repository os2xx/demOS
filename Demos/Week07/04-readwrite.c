/*
 * Copyright (C) 2011-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV09: Sat 28 Oct 2023 10:00
 * REV08: Tue 24 Mar 2020 17:00
 * REV07: Wed 29 Aug 2018 18:00
 * REV06: Tue 17 Apr 2018 09:00
 * START: Wed 30 Mar 2011 02:00
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"

sem_t           sync_er, sync_re, sync_ew, sync_we;

#define R_REHAT 1500
#define R_READ  1500
#define R_JUMLAH  2

#define W_REHAT 1500
#define W_WRITE 1500
#define W_JUMLAH  2

#define aReader 0
#define aWriter 1

void* Extra (void* a) {
   int ii;
   while (TRUE) {
      for (ii=0; ii<W_JUMLAH; ii++)
         sem_wait (&sync_we);
      for (ii=0; ii<R_JUMLAH; ii++)
         sem_post (&sync_er);
      for (ii=0; ii<R_JUMLAH; ii++)
         sem_wait (&sync_re);
      for (ii=0; ii<W_JUMLAH; ii++)
         sem_post (&sync_ew);
   }
}

void* Reader (void* a) {
   int  my_ID;

   my_ID = getADDglobalID(aReader);
   printf   ("                        READER %d: SIAP  ******\n", my_ID);
   while (TRUE) {
      sem_wait (&sync_er);
      printf("                        READER %d: REHAT ******\n", my_ID);
      rehat_acak(R_REHAT);
      printf("                        READER %d: MAU  MEMBACA\n", my_ID);
      printf("                        ***** JUMLAH PEMBACA %d\n", startRead());
      printf("                        READER %d:=SEDANG==BACA\n", my_ID);
      rehat_acak(R_READ);
      printf("                        READER %d: SELESAI BACA\n", my_ID);
      printf("                        ***** SISA PEMBACA %d\n", endRead());
      sem_post (&sync_re);
   }
}

void* Writer (void* a) {
   int  my_ID;

   my_ID = getADDglobalID(aWriter);

   printf   ("WRITER %d: SIAP  *******\n", my_ID);
   while (TRUE) {
      printf("WRITER %d: REHAT *******\n", my_ID);
      rehat_acak(W_REHAT);
      printf("WRITER %d: MAU   MENULIS\n", my_ID);
      startWrite();
      printf("WRITER %d:=SEDANG==NULIS\n", my_ID);
      rehat_acak(W_WRITE);
      endWrite();
      printf("WRITER %d: SELESAI NULIS\n", my_ID);
      sem_post (&sync_we);
      sem_wait (&sync_ew);
   }
}

int main(int argc, char * argv[])
{
   int ii;
   init_rw();
   init_globalID ();
   sem_init   (&sync_er, 0, 0);
   sem_init   (&sync_re, 0, 0);
   sem_init   (&sync_ew, 0, 0);
   sem_init   (&sync_we, 0, 0);
   daftar_trit(Extra);
   for (ii = 0 ; ii < R_JUMLAH; ii++)
      daftar_trit(Reader);
   for (ii = 0 ; ii < W_JUMLAH; ii++)
      daftar_trit(Writer);
   jalankan_trit();
   beberes_trit("Selese...");
}

/*
# INFO: Readers - Writers with PTHREAD.
# INFO:                   Reader():        a Reader.
# INFO:                      startRead():  the Reader starts   reading.
# INFO:                      endRead():    the Reader finishes reading.
# INFO:                   Write():         a Writer.
# INFO:                      startWrite(): the Writer starts   writing.
# INFO:                      endWrite():   the Writer finishes writing.
# INFO:                   rehat_acak():    random stop.
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
 */

