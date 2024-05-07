#ifndef RESTING_HPP
#define RESTING_HPP
#include "funct.hpp"
#include <iostream>

void Resting() {
  if (Player.CurHealth < Player.MaxHealth) {
    ClearScreen();
    DisplayPlayerStats();
    std::cout << "\nWould you like to rest?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n";
    char restconfirm;
    std::cin >> restconfirm;
    if (restconfirm == '1') {
      int HPRecover = rand() % Player.MaxHealth + 1;
      int MPRecover;
      Player.CurHealth = Player.CurHealth + HPRecover;
      if (Player.CurHealth > Player.MaxHealth) {
        Player.CurHealth = Player.MaxHealth;
      }
      ClearScreen();
      DisplayPlayerStats();
      std::cout << "\nYou rest and recover:\n" << HPRecover << " hit points.\n";
      Press_Enter();
    } else {
      ClearScreen();
      std::cout << "\nThen let's carry on.\n";
      Press_Enter();
    }
  } else {
    ClearScreen();
    std::cout << "\nI don't need rest.\n";
    Press_Enter();
  }
}
#endif
