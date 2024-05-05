#include "include/cc.h"
#include "include/combat.h"
#include "include/funct.h"
#include "include/progression.h"
#include <cstdlib> // random numbers are fun
#include <ctime>   // time()
#include <iostream>
#include <string> // epic txt variables

// is this a good way to handle this?
int PressEnter;

int main() {
  // start random seed
  srand(static_cast<unsigned int>(time(0)));
  // this should loop around til its done(or ppl break out with c or q)
  char_creation();
  // player finished/exited cc and we need to roll the stats
  ClearScreen();
  RollStats();

  // gameplay loop ( is this a good way to do it? )
  do {

    ClearScreen();
    CheckLvlUp();
    Resting();
    Combat();
    // Town();

  } while (Defeated == 0);
  std::cout << "Game Over.\n";
  Press_Enter();
  DebugDataFull();
  return 0;
}
