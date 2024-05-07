#ifndef PROGRESSION_HPP
#define PROGRESSION_HPP
#include "funct.hpp"
#include <iostream>

void CheckLvlUp() {
  if (Player.Exp >= 1000) {
    ClearScreen();
    int HPup = Player.MaxHealth;
    Player.Level++;
    UpdateValues();
    DisplayPlayerStats();
    std::cout << "\nLevel up!\n\n";
    HPup = Player.MaxHealth - HPup;
    std::cout << "HP increased by +" << HPup << " to " << Player.MaxHealth
              << "!\n";
    Player.Exp = Player.Exp - 1000;
    Press_Enter();
  }
}

#endif
