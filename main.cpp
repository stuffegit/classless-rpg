#include "include/cc.hpp"          // char creation stuff
#include "include/combat.hpp"      // duh
#include "include/funct.hpp"       // structs, initial declarations
#include "include/progression.hpp" // lvlup, Resting
#include "include/town.hpp"
// #include <cstdlib>               // random numbers are fun
// #include <ctime>                 // time()
#include <iostream>

int SkipFirstTown{1};
char newgame;

int main() {
  // start random seed
  srand(static_cast<unsigned int>(time(0)));
  // this should loop around til its done(or ppl break out with c or q)
  do {
    ClearStats();
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
    Press_Enter();
    std::cout << "Do you want to restart? Y/N\n";
    std::cin >> newgame;
  } while (newgame == 'Y' or newgame == 'y');
  return 0;
}
