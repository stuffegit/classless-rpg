#include "include/cc.h"
#include "include/funct.h"
#include <cstdlib> // random numbers are fun
#include <ctime>   // time()
#include <iostream>
#include <string> // epic txt variables

// is this a good way to handle this?
int PressEnter;
int CombatResolution{0};
int Defeated{0};

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
