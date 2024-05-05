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
