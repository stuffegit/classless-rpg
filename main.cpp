#include "include/cc.h"          // char creation stuff
#include "include/combat.h"      // duh
#include "include/funct.h"       // structs, initial declarations
#include "include/progression.h" // lvlup, Resting
#include "include/town.h"
// #include <cstdlib>               // random numbers are fun
// #include <ctime>                 // time()
#include <iostream>

int SkipFirstTown{1};

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
    if (SkipFirstTown == 0) {
      Town();
    }
    SkipFirstTown = 0;
    Combat();

  } while (Defeated == 0);
  std::cout << "Game Over.\n";
  Press_Enter();
  DebugDataFull();
  return 0;
}
