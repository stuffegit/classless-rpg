#ifndef RESTING_H
#define RESTING_H
#include "funct.h"
#include <iostream>

void Resting() {
  if (Player.CurHealth < Player.MaxHealth or Player.CurMana < Player.MaxMana) {
    ClearScreen();
    std::cout << "Level " << Player.Level << " " << Player.Class << "\n";
    std::cout << "HP " << Player.CurHealth << "/" << Player.MaxHealth << "\n";
    std::cout << "MP " << Player.CurMana << "/" << Player.MaxMana << "\n";
    std::cout << "XP " << Player.Exp << "/1000\n";
    std::cout << "Would you like to rest? Y/N.\n";
    char restconfirm;
    std::cin >> restconfirm;
    if (restconfirm == 'Y' or restconfirm == 'y') {
      int HPRecover = rand() % Player.MaxHealth + 1;
      int MPRecover = rand() % Player.MaxMana + 1;
      Player.CurHealth = Player.CurHealth + HPRecover;
      if (Player.CurHealth > Player.MaxHealth) {
        Player.CurHealth = Player.MaxHealth;
      }
      if (Player.CurMana < Player.MaxMana && Player.MaxMana != 0) {
        Player.CurMana = Player.CurMana + MPRecover;
        Player.CurMana = Player.MaxMana;
      }
      ClearScreen();
      std::cout << "Level " << Player.Level << " " << Player.Class << "\n";
      std::cout << "HP " << Player.CurHealth << "/" << Player.MaxHealth << "\n";
      std::cout << "MP " << Player.CurMana << "/" << Player.MaxMana << "\n";
      std::cout << "XP " << Player.Exp << "/1000\n";
      std::cout << "You rest and recover:\n"
                << HPRecover << " hit points.\n"
                << MPRecover << " mana points.\n";
      Press_Enter();
    } else {
      ClearScreen();
      std::cout << "Then let's carry on.\n";
      Press_Enter();
    }
  }
}
#endif
