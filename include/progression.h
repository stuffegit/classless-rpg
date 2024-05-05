#ifndef PROGRESSION_H
#define PROGRESSION_H
#include "funct.h"
#include <iostream>

void CheckLvlUp() {
  if (Player.Exp >= 1000) {
    ClearScreen();
    std::cout << "Level up!\n\n";
    int HPup = rand() % Player.CCMaxHealth + 1;
    Player.MaxHealth = Player.MaxHealth + HPup;
    Player.CurHealth = Player.MaxHealth;
    std::cout << "HP increased by +" << HPup << " to " << Player.MaxHealth
              << "\n";
    Player.Exp = Player.Exp - 1000;
    Player.Level++;
    Press_Enter();
  }
}

#endif
