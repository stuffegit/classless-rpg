#include "funct.hpp"
#include <iostream>

int CombatResolution{0};

void Combat() {
  CombatResolution = 0;
  ClearScreen();
  DisplayPlayerStats();
  RandomEnemy();
  std::cout << "A " << Enemy.Name << " approach.\n";
  Press_Enter();
  ClearScreen();
  int PlayerTurnDamage{0};
  int EnemyTurnDamage{0};

  DisplayPlayerStats();
  DisplayEnemyStats();

  do {
    char combat_choice;
    std::cout << "1: Attack\n";
    std::cout << "2: Spell[WIP]\n";
    std::cout << "3: Heal - 2 MP\n";
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
      if (Enemy.Health <= 0) {
        CombatResolution = 1;
        ClearScreen();
        Player.Exp = Player.Exp + Enemy.Exp;
        Player.Silver = Player.Silver + Enemy.Silver;
        DisplayPlayerStats();
        DisplayEnemyStats();
        std::cout << "You delivered " << PlayerTurnDamage << " damage("
                  << Player.DamageDice << "d" << Player.DamageDie << ") to "
                  << Enemy.Name << ", killing it.\n\n";
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
        Press_Enter();
        ClearScreen();
      }
      break;

    case '4':
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
                  << Player.DamageDice << "d" << Player.DamageDie << ") to "
                  << Enemy.Name << ".\n\n";
      }
    }
    if (EnemyTurnDamage > 0) {
      std::cout << "Enemy " << Enemy.Name << " delivered " << EnemyTurnDamage
                << " damage to You.\n\n";
    }
  } while (CombatResolution < 1);

  if (CombatResolution == 1) {
    std::cout << "You won.\n";
    std::cout << "Experience gained: " << Enemy.Exp << "\n";
    std::cout << "Silver gained: " << Enemy.Silver << "\n";
    Press_Enter();
  } else if (CombatResolution == 2) {
    ClearScreen();
    DisplayPlayerStats();
    DisplayEnemyStats();
    std::cout << "You lost.\n";
    Press_Enter();
    Player.Defeated = 1;
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
    Enemy.Silver = 0;
    break;
  case 2:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 6;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 2;
    Enemy.Exp = 400;
    Enemy.Silver = 0;
    break;
  case 3:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 6;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 2;
    Enemy.Exp = 400;
    Enemy.Silver = 0;
    break;
  case 4:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 6;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 2;
    Enemy.Exp = 400;
    Enemy.Silver = 0;
    break;
  case 5:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 6;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 2;
    Enemy.Exp = 400;
    Enemy.Silver = 0;
    break;
  case 6:
    Enemy.Name = "Young Wolf";
    Enemy.Health = 6;
    Enemy.AC = 6;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 2;
    Enemy.Exp = 400;
    Enemy.Silver = 0;
    break;
  case 7:
    Enemy.Name = "Wolf";
    Enemy.Health = 8;
    Enemy.AC = 8;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 4;
    Enemy.Exp = 500;
    Enemy.Silver = 0;
    break;
  case 8:
    Enemy.Name = "Wolf";
    Enemy.Health = 8;
    Enemy.AC = 8;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 4;
    Enemy.Exp = 500;
    Enemy.Silver = 0;
    break;
  case 9:
    Enemy.Name = "Bandit";
    Enemy.Health = 10;
    Enemy.AC = 8;
    Enemy.DamageDice = 1;
    Enemy.DamageDie = 3;
    Enemy.Exp = 400;
    Enemy.Silver = rand() % 50 + 50;
    break;
  case 10:
    Enemy.Name = "Bräver";
    Enemy.Health = 18;
    Enemy.AC = 8;
    Enemy.DamageDice = 2;
    Enemy.DamageDie = 3;
    Enemy.Exp = 1000;
    Enemy.Silver = 0;
    break;
  }
}

void DisplayPlayerStats() {
  std::cout << "Level " << Player.Level << " " << Player.Class << "\n";
  std::cout << "HP " << Player.CurHealth << "/" << Player.MaxHealth << "\n";
  std::cout << "MP " << Player.CurMana << "/" << Player.MaxMana << "\n";
  std::cout << "XP " << Player.Exp << "/1000\n\n";
}

void DisplayEnemyStats() {
  std::cout << "Enemy: " << Enemy.Name << "\nHP: ";
  for (int i = 0; i < Enemy.Health; i++) {
    std::cout << "-";
  }
  std::cout << "\n\n";
}
