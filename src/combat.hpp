#ifndef COMBAT_HPP
#define COMBAT_HPP
#include "funct.hpp"
#include <iostream>

int CombatResolution{0};

void Combat() {
  DisplayPlayerStats();
  std::cout << "\nRegion Select: \n";
  std::cout << "1. Forest\n";
  std::cout << "2. WIP\n";
  std::cout << "3. WIP\n";
  std::cout << "Choice: ";
  std::cin >> Player.Region;
  CombatResolution = 0;
  ClearScreen();
  DisplayPlayerStats();
  if (Player.Region == 1) {
    RandomEnemyForest();
  } else if (Player.Region == 2) {
  } else if (Player.Region == 3) {
  } else {
    std::cout << "Ping Stuffe, Player.Region variable broke";
  }

  std::cout << "\nA " << Enemy.Name << " approach.\n";
  Press_Enter();
  ClearScreen();
  int PlayerTurnDamage{0};
  int EnemyTurnDamage{0};

  DisplayPlayerStats();
  DisplayEnemyStats();

  do {
    char combat_choice;
    std::cout << "1: Strike\n";
    std::cout << "2: Spell[WIP]\n";
    std::cout << "3: End Turn\n";
    std::cout << "Choice: ";
    std::cin >> combat_choice;
    switch (combat_choice) {
    case '1':
      ClearScreen();
      PlayerTurnDamage = 0;
      for (int i = 0; i < Player.DamageDice; i++) {
        PlayerTurnDamage = PlayerTurnDamage + (rand() % Player.DamageDie + 1) +
                           (Player.DamageBonus);
      }
      Enemy.Health = Enemy.Health - PlayerTurnDamage;
      if (Enemy.Health <= 0) {
        CombatResolution = 1;
        ClearScreen();
        Player.Exp = Player.Exp + (Enemy.Level / Player.Level) * 80;
        Player.Silver = Player.Silver + Enemy.Silver;
        DisplayPlayerStats();
        DisplayEnemyStats();
        std::cout << "You delivered " << PlayerTurnDamage << " damage("
                  << Player.DamageDice << "d" << Player.DamageDie << "+"
                  << Player.DamageBonus << ") to " << Enemy.Name
                  << ", killing it.\n";
        break;
      }

      combat_choice = '0';
      break;
    case '2':
      std::cout << "case2";
      break;

    case '3':
      ClearScreen();
      DisplayPlayerStats();
      DisplayEnemyStats();
      std::cout << "You brace yourself for the incoming blow.\n";
      Press_Enter();
      ClearScreen();
      if (Enemy.Health > 0) {
        EnemyTurnDamage = 0;
        for (int i = 0; i < Enemy.DamageDice; i++) {
          EnemyTurnDamage = EnemyTurnDamage + rand() % Enemy.DamageDie + 1;
        }
        Player.CurHealth = Player.CurHealth - EnemyTurnDamage;
        if (Player.CurHealth <= 0) {
          CombatResolution = 2;
        }
      }

      combat_choice = '0';
      break;

    default:
      break;
    }
    EnemyTurnDamage = 0;
    if (Enemy.Health > 0) {
      for (int i = 0; i < Enemy.DamageDice; i++) {
        EnemyTurnDamage = EnemyTurnDamage + rand() % Enemy.DamageDie + 1;
      }
      Player.CurHealth = Player.CurHealth - EnemyTurnDamage;
      if (Player.CurHealth <= 0) {
        CombatResolution = 2;
      }
    }

    if (Enemy.Health > 0) {
      DisplayPlayerStats();
      DisplayEnemyStats();
      if (PlayerTurnDamage > 0) {
        std::cout << "You delivered " << PlayerTurnDamage << " damage("
                  << Player.DamageDice << "d" << Player.DamageDie << "+"
                  << Player.DamageBonus << ") to " << Enemy.Name << ".\n";
      }
    }
    if (EnemyTurnDamage > 0) {
      std::cout << "Enemy " << EnemyTurnDamage << " damage(" << Enemy.DamageDice
                << "d" << Enemy.DamageDie << "+" << Enemy.DamageBonus
                << ") to You.\n";
    }
  } while (CombatResolution < 1);

  if (CombatResolution == 1) {
    std::cout << "You won.\n";
    std::cout << "Experience gained: " << (Enemy.Level / Player.Level) * 80
              << "\n";
    std::cout << "Silver gained: " << Enemy.Silver << "\n";
    Press_Enter();
  } else if (CombatResolution == 2) {
    std::cout << "\nYou lost.\n";
    Press_Enter();
    Player.Defeated = 1;
  }
}

void RandomEnemyForest() {
  int x = rand() % 10 + 1;
  switch (x) {
  case 1:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 11;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 3;
    Enemy.DamageBonus = 0;
    Enemy.Level = 1;
    Enemy.Silver = 0;
    break;
  case 2:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 11;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 3;
    Enemy.DamageBonus = 0;
    Enemy.Level = 1;
    Enemy.Silver = 0;
    break;
  case 3:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 11;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 3;
    Enemy.DamageBonus = 0;
    Enemy.Level = 1;
    Enemy.Silver = 0;
    break;
  case 4:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 11;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 3;
    Enemy.DamageBonus = 0;
    Enemy.Level = 1;
    Enemy.Silver = 0;
    break;
  case 5:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 11;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 3;
    Enemy.DamageBonus = 0;
    Enemy.Level = 1;
    Enemy.Silver = 0;
    break;
  case 6:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 11;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 3;
    Enemy.DamageBonus = 0;
    Enemy.Level = 1;
    Enemy.Silver = 0;
    break;
  case 7:
    Enemy.Name = "Wolf";
    Enemy.Health = 12;
    Enemy.AC = 8;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 4;
    Enemy.DamageBonus = 1;
    Enemy.Level = 2;
    Enemy.Silver = 0;
    break;
  case 8:
    Enemy.Name = "Wolf";
    Enemy.Health = 12;
    Enemy.AC = 8;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 4;
    Enemy.DamageBonus = 1;
    Enemy.Level = 2;
    Enemy.Silver = 0;
    break;
  case 9:
    Enemy.Name = "Bandit";
    Enemy.Health = 10;
    Enemy.AC = 8;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 3;
    Enemy.DamageBonus = 2;
    Enemy.Level = 3;
    Enemy.Silver = rand() % 50 + 50;
    break;
  case 10:
    Enemy.Name = "Bräver";
    Enemy.Health = 18;
    Enemy.AC = 8;
    Enemy.DamageDice = 2;
    Enemy.DamageDie = 3;
    Enemy.DamageBonus = 4;
    Enemy.Level = 4;
    Enemy.Silver = 0;
    break;
  }
}

void DisplayPlayerStats() {
  std::cout << "Level " << Player.Level << " " << Player.Race << " "
            << Player.Class << "\n";
  std::cout << "XP " << Player.Exp << "/1000\n\n";
  std::cout << "HP " << Player.CurHealth << "/" << Player.MaxHealth << "\n";
  std::cout << "Str:" << Player.Str << "   Dex:" << Player.Dex << "\n";
  std::cout << "Con:" << Player.Con << "   Int:" << Player.Int << "\n";
  std::cout << "Wis:" << Player.Wis << "   Cha:" << Player.Cha << "\n";
}

void DisplayEnemyStats() {
  std::cout << "\nEnemy: " << Enemy.Name << "\nHP: ";
  for (int i = 0; i < Enemy.Health; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
}

#endif
