#ifndef COMBAT_H
#define COMBAT_H
#include "funct.h"
#include <iostream>

int CombatResolution{0};
int Defeated{0};

void Combat() {
  CombatResolution = 0;
  ClearScreen();
  RandomEnemy();
  std::cout << "A " << Enemy.Name << " approach.";
  // do not blame me for this, its chatgpt
  if (Enemy.Name == "Bräver") {
    std::cout << "\n             _,---,_\n";
    std::cout << "      _,,-          \n";
    std::cout << "  ,-e                \n";
    std::cout << " (*                  |\n";
    std::cout << "   o     __,-´  )    |\n";
    std::cout << "   `,_   (((__,-     L___,,--,,__\n";
    std::cout << "      ) ,---  /    / -- '' -'-' )\n";
    std::cout << "    _/ /     )_||   /---,,___  __/\n";
  }

  Press_Enter();
  ClearScreen();
  int PlayerTurnDamage{0};
  int EnemyTurnDamage{0};

  do {
    char combat_choice;
    // std::cout << "Health: " << Enemy.Health << "\n";
    // std::cout << "AC: " << Enemy.AC << "\n";
    // std::cout << "DamageDice: " << Enemy.DamageDice << "\n";
    // std::cout << "DamageDie: " << Enemy.DamageDie << "\n\n";
    // DebugData();
    DisplayCombatStats();
    std::cout << "1: Attack\n";
    std::cout << "2: Spell\n";
    std::cout << "3: Heal\n";
    std::cout << "4: End Turn\n";
    std::cin >> combat_choice;
    switch (combat_choice) {
    case '1':
      ClearScreen();
      PlayerTurnDamage = 0;
      for (int i = 0; i < Player.DamageDice; i++) {
        PlayerTurnDamage = PlayerTurnDamage + rand() % Player.DamageDie + 1;
      }
      Enemy.Health = Enemy.Health - PlayerTurnDamage;
      std::cout << "You delivered " << PlayerTurnDamage << " damage to "
                << Enemy.Name << ".\n\n";
      if (Enemy.Health <= 0) {
        CombatResolution = 1;
        break;
      }

      combat_choice = '0';
      break;
    case '2':
      std::cout << "case2";
      break;

    case '3':
      ClearScreen();
      if (Player.CurMana > 1) {
        std::cout << "Casting Heal!\n";
        std::cout << Player.CurHealth;
        Player.CurHealth = Player.CurHealth + rand() % Player.CCMaxHealth + 1;
        if (Player.CurHealth > Player.MaxHealth) {
          Player.CurHealth = Player.MaxHealth;
        }
        std::cout << " -> " << Player.CurHealth << "!\n";
        Player.CurMana = Player.CurMana - 2;
        Press_Enter();
      } else {
        std::cout << "You attempt to cast Heal... but you're out of mana.";
      }
      break;

    case '4':
      ClearScreen();
      std::cout << "You brace yourself for the incoming blow.\n";
      if (Enemy.Health > 0) {
        EnemyTurnDamage = 0;
        for (int i = 0; i < Enemy.DamageDice; i++) {
          EnemyTurnDamage = EnemyTurnDamage + rand() % Enemy.DamageDie + 1;
        }
        Player.CurHealth = Player.CurHealth - EnemyTurnDamage;
        std::cout << "Enemy " << Enemy.Name << " delivered " << EnemyTurnDamage
                  << " damage to You.\n\n";
        if (Player.CurHealth <= 0) {
          CombatResolution = 2;
        }
      }

      combat_choice = '0';
      break;

    default:
      break;
    }
    if (Enemy.Health > 0) {
      ClearScreen();
      EnemyTurnDamage = 0;
      for (int i = 0; i < Enemy.DamageDice; i++) {
        EnemyTurnDamage = EnemyTurnDamage + rand() % Enemy.DamageDie + 1;
      }
      Player.CurHealth = Player.CurHealth - EnemyTurnDamage;
      std::cout << "Enemy " << Enemy.Name << " delivered " << EnemyTurnDamage
                << " damage to You.\n\n";
      if (Player.CurHealth <= 0) {
        CombatResolution = 2;
      }
    }
  } while (CombatResolution < 1);

  if (CombatResolution == 1) {
    std::cout << "You won.\n";
    std::cout << "Experience gained: " << Enemy.Exp;
    Player.Exp = Player.Exp + Enemy.Exp;
    Press_Enter();
  } else if (CombatResolution == 2) {
    std::cout << "You lost.\n";
    Press_Enter();
    Defeated = 1;
  }
}

void RandomEnemy() {
  int x = rand() % 10 + 1;
  switch (x) {
  case 1:
    Enemy.Name = "Rabbit";
    Enemy.Health = 2;
    Enemy.AC = 8;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 1;
    Enemy.Exp = 100;
    break;
  case 2:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 6;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 2;
    Enemy.Exp = 400;
    break;
  case 3:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 6;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 2;
    Enemy.Exp = 400;
    break;
  case 4:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 6;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 2;
    Enemy.Exp = 400;
    break;
  case 5:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 6;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 2;
    Enemy.Exp = 400;
    break;
  case 6:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 6;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 2;
    Enemy.Exp = 400;
    break;
  case 7:
    Enemy.Name = "Wolf";
    Enemy.Health = 8;
    Enemy.AC = 8;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 4;
    Enemy.Exp = 500;
    break;
  case 8:
    Enemy.Name = "Wolf";
    Enemy.Health = 8;
    Enemy.AC = 8;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 4;
    Enemy.Exp = 500;
    break;
  case 9:
    Enemy.Name = "Wolf";
    Enemy.Health = 8;
    Enemy.AC = 8;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 4;
    Enemy.Exp = 500;
    break;
  case 10:
    Enemy.Name = "Bräver";
    Enemy.Health = 18;
    Enemy.AC = 8;
    Enemy.DamageDice = 2;
    Enemy.DamageDie = 4;
    Enemy.Exp = 1000;
    break;
  }
}

void DisplayCombatStats() {
  std::cout << "Enemy: " << Enemy.Name << "\nHP: ";
  for (int i = 0; i < Enemy.Health; i++) {
    std::cout << "-";
  }
  std::cout << "\n\n";

  std::cout << "Player:\n";
  std::cout << "HP: " << Player.CurHealth << "\n";
  std::cout << "MP: " << Player.CurMana << "\n\n";
}

#endif
