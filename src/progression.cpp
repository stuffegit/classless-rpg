#include "funct.hpp"
#include <iostream>

void CheckLvlUp() {
  if (Player.Exp >= 1000) {
    ClearScreen();
    std::cout << "Level up!\n\n";
    int HPup = rand() % Player.CCMaxHealth + 1;
    Player.MaxHealth = Player.MaxHealth + HPup;
    Player.CurHealth = Player.MaxHealth;
    std::cout << "HP increased by +" << HPup << " to " << Player.MaxHealth
              << "!\n";
    Player.Exp = Player.Exp - 1000;
    Player.Level++;
    int dicediff{Player.DamageDice};
    // increase damage dice by half-level rounded up on level up
    Player.DamageDice = (Player.Level + 1) / 2;
    if (Player.DamageDice != dicediff) {
      std::cout << "Your Damage Dice increased by +"
                << Player.DamageDice - dicediff << " to " << Player.DamageDice
                << "!\n";
    }
    Press_Enter();
  }
}
