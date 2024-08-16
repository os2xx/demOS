/*
 * Copyright (C) 2014-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV07: Sat 28 Oct 2023 10:00
 * REV06: Wed 25 Mar 2020 08:00
 * REV05: Wed 27 Feb 2019 19:00
 * REV03: Tue 17 Apr 2018 09:00
 * REV01: Wed 02 Nov 2016 11:00
 * START: Sun 19 Oct 2014 00:00
 */


/*
# INFO: Rolling the Dics PTHREAD. 
# INFO:                   Player():        one pthread for each player.
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
# INFO:                   sem_init():      init a semaphore.
# INFO:                   sem_wait():      wait a semaphore.
# INFO:                   sem_post():      signal a semaphore.
# INFO:                   *Rock*Paper*Scissors*Lizard*Spock*
# INFO:                   Invented by Sam Kass and Karen Bryla
# INFO:                   Rock crushes Scissors
# INFO:                   Rock crushes Lizard
# INFO:                   Paper covers Rock
# INFO:                   Paper disproves Spock
# INFO:                   Scissors cut Paper
# INFO:                   Scissors decapitate Lizard
# INFO:                   Lizard eats Paper
# INFO:                   Lizard poisons Spock
# INFO:                   Spock vaporizes Rock
# INFO:                   Spock smashes Scissors
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "99-myutils.h"

#define nPlayers 2
#define nWeapons 5
int     playerSEQ=1;
int     myWeapon[nPlayers+1];
sem_t   sync1, sync2;

// (0=Rock)   (1=Paper) (2=Scissors) 
// (3=Lizard) (4=Spock)
char *weaponName[nWeapons]= {
   "Rock", "Paper", "Scissors", 
   "Lizard", "Spock"
};

// '-' = draw  'v' = win  'x' = lose
char weaponTable[nWeapons][nWeapons] = {
   {'-','x','v','v','x'},
   {'v','-','x','x','v'},
   {'x','v','-','v','x'},
   {'x','v','x','-','v'},
   {'v','x','v','x','-'}
};

void waitPlayers() {
   for (int ii=0; ii < nPlayers; ii++)
      sem_wait(&sync1);
}

void postPlayers() {
   for (int ii=0; ii < nPlayers; ii++)
      sem_post(&sync2);
}

void* playerThread (void* a) {
   int      playerID;
   sem_wait (&mutex);
   playerID=playerSEQ++;
   sem_post (&mutex);
   printf("Player[%d]: READY\n",playerID);
   sem_post (&sync1);
   sem_wait (&sync2);
   myWeapon[playerID] = rand() % nWeapons;
   printf("Player[%d]: %s\n", 
      playerID, weaponName[myWeapon[playerID]]);
   sem_post (&sync1);
}

void* refereeThread (void* a) {
   waitPlayers();
   printf("Referee:   ALL READY!\n");
   postPlayers();
   waitPlayers();
   char result = 
      weaponTable[myWeapon[1]][myWeapon[2]];
   if (result == '-') 
      printf("Referee:   DRAW!\n");
   else if (result == 'v')
      printf("Referee:   Player[1] WINS!\n");
   else
      printf("Referee:   Player[2] WINS!\n");
}

void main(void) {
   // randomize with a time seed
   srand(time(NULL));          
   sleep(1);
   // init semaphore mutex = 1 syncx = 0
   sem_init (&mutex, 0, 1);    
   sem_init (&sync1, 0, 0);
   sem_init (&sync2, 0, 0);
   // register and execute threads
   daftar_trit (refereeThread);
   for (int ii=0; ii<nPlayers; ii++)
      daftar_trit (playerThread);
   jalankan_trit ();
   beberes_trit  ("Goodbye...");
}

