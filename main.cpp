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
  // DebugDataFull();
  RollStats();
  // DebugData();

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

void DebugData() {

  std::cout << "Debug stats:\n";
  std::cout << Player.MaxHealth << "\t Player.MaxHealth\n";
  std::cout << Player.CurHealth << "\t Player.CurHealth\n";
  std::cout << Player.MaxMana << "\t Player.MaxMana\n";
  std::cout << Player.CurMana << "\t Player.CurMana\n";
  std::cout << "1d" << Player.DamageDie << "\t Player.DamageDie\n";
}

void DebugDataFull() {

  std::cout << "Debug stats:\n";
  std::cout << Player.CCMaxHealth << "\t Player.CCMaxHealth\n";
  std::cout << Player.CurHealth << "\t Player.CurHealth\n";
  std::cout << Player.MaxHealth << "\t Player.MaxHealth\n";
  std::cout << Player.BaseHealth << "\t Player.BaseHealth\n";
  std::cout << Player.ClassHealthBonus << "\t Player.ClassHealthBonus\n";
  std::cout << Player.RaceHealthBonus << "\t Player.RaceHealthBonus\n";
  std::cout << Player.ProfessionHealthBonus
            << "\t Player.ProfessionHealthBonus\n";
  std::cout << Player.BirthplaceHealthBonus
            << "\t Player.BirthplaceHealthBonus\n";
  std::cout << Player.CCMaxMana << "\t Player.CCMaxMana\n";
  std::cout << Player.CurMana << "\t Player.CurMana\n";
  std::cout << Player.MaxMana << "\t Player.MaxMana\n";
  std::cout << Player.BaseMana << "\t Player.BaseMana\n";
  std::cout << Player.ClassManaBonus << "\t Player.ClassManaBonus\n";
  std::cout << Player.RaceManaBonus << "\t Player.RaceManaBonus\n";
  std::cout << Player.ProfessionManaBonus << "\t Player.ProfessionManaBonus\n";
  std::cout << Player.BirthplaceManaBonus << "\t Player.BirthplaceManaBonus\n";
  std::cout << Player.DamageDie << "\t Player.DamageDie\n";
  std::cout << Player.BaseDamageDie << "\t Player.BaseDamageDie\n";
  std::cout << Player.ClassDamageDieBonus << "\t Player.ClassDamageDieBonus\n";
  std::cout << Player.RaceDamageDieBonus << "\t Player.RaceDamageDieBonus\n";
  std::cout << Player.ProfessionDamageDieBonus
            << "\t Player.ProfessionDamageDieBonus\n";
  std::cout << Player.BirthplaceDamageDieBonus
            << "\t Player.BirthplaceDamageDieBonus\n";
}

void ClearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  std::system("clear");
#endif
}

void Press_Enter() {
  std::cin.ignore(10, '\n');
  std::cin.get();
}
