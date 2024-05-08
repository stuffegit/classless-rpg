#include "funct.hpp"
#include <iomanip> // for setw()
#include <iostream>

void char_creation() {
  char cc_choice;
  int cc_done{0};
  do {
    UpdateValues();
    ClearScreen();
    DisplayPlayerStats();
    std::cout << "\n1: Class\n";
    std::cout << "2: Race\n";
    if (Player.Class != "Civilian" && Player.Race != "Uncertain") {
      std::cout << "C: Continue\n";
    }
    std::cout << "Q: Quit\n";
    std::cout << "Choice: ";
    std::cin >> cc_choice;
    std::cout << "\n";

    switch (cc_choice) {
    case '1':
      class_select();
      break;
    case '2':
      race_select();
      break;
    case 'Q':
    case 'q':
      exit(0);
    case 'C':
    case 'c':
      if (Player.Class != "" && Player.Race != "") {
        cc_done = 1;
      } else {
        break;
      }
    }
  } while (cc_done != 1);
}

void class_select() {
  int class_choice{};
  ClearScreen();
  DisplayPlayerStats();

  std::cout << "\n1: Fighter - Str+2, Con+2, Dex+2, Int-2\n";
  std::cout << "2: Rogue   - Dex+2, Int+2, Cha+2, Wis-2\n";
  std::cout << "3: Wizard  - Int+2, Dex+2, Wis+2, Cha-2\n";
  std::cout << "4: Cleric  - Wis+2, Con+2, Str+2, Dex-2\n";
  std::cout << "Choice: ";
  std::cin >> class_choice;
  std::cout << "\n";

  if (class_choice == 1) {
    std::cout << "Fighter chosen.\n";
    Player.Class = "Fighter";
    Player.DamageDie = 8;
    Player.BaseHealth = 10;
    Player.ClassStats[0] = +2;
    Player.ClassStats[1] = +2;
    Player.ClassStats[2] = +2;
    Player.ClassStats[3] = -2;
    Player.ClassStats[4] = 0;
    Player.ClassStats[5] = 0;
  } else if (class_choice == 2) {
    std::cout << "Rogue chosen.\n";
    Player.Class = "Rogue";
    Player.DamageDie = 6;
    Player.BaseHealth = 8;
    Player.ClassStats[0] = 0;
    Player.ClassStats[1] = +2;
    Player.ClassStats[2] = 0;
    Player.ClassStats[3] = +2;
    Player.ClassStats[4] = -2;
    Player.ClassStats[5] = +2;
  } else if (class_choice == 3) {
    std::cout << "Wizard chosen.\n";
    Player.Class = "Wizard";
    Player.DamageDie = 4;
    Player.BaseHealth = 6;
    Player.ClassStats[0] = 0;
    Player.ClassStats[1] = +2;
    Player.ClassStats[2] = 0;
    Player.ClassStats[3] = +2;
    Player.ClassStats[4] = +2;
    Player.ClassStats[5] = -2;
  } else if (class_choice == 4) {
    std::cout << "Cleric chosen.\n";
    Player.Class = "Cleric";
    Player.DamageDie = 6;
    Player.BaseHealth = 8;
    Player.ClassStats[0] = +2;
    Player.ClassStats[1] = -2;
    Player.ClassStats[2] = +2;
    Player.ClassStats[3] = 0;
    Player.ClassStats[4] = +2;
    Player.ClassStats[5] = 0;
  } else {
    std::cout << "idk brother, gl\n";
  }
}

void race_select() {
  int race_choice{};
  ClearScreen();
  DisplayPlayerStats();

  std::cout << "\n1: Man       - Str+2, Con+2, Int-2\n";
  std::cout << "2: Hvit Alf  - Wis+2, Cha+2, Con-2\n";
  std::cout << "3: Svart Alf - Int+2, Dex+2, Cha-2\n";
  std::cout << "4: Tomte     - Int+2, Wis+2, Str-2\n";
  std::cout << "Choice: ";
  std::cin >> race_choice;

  if (race_choice == 1) {
    std::cout << "Man chosen.\n";
    Player.Race = "Man";
    Player.RaceStats[0] = +2;
    Player.RaceStats[1] = +0;
    Player.RaceStats[2] = +2;
    Player.RaceStats[3] = -2;
    Player.RaceStats[4] = +0;
    Player.RaceStats[5] = +0;
  } else if (race_choice == 2) {
    std::cout << "Hvit Alf choosen.\n";
    Player.Race = "Hvit Alf";
    Player.RaceStats[0] = +0;
    Player.RaceStats[1] = +0;
    Player.RaceStats[2] = -2;
    Player.RaceStats[3] = +0;
    Player.RaceStats[4] = +2;
    Player.RaceStats[5] = +2;
  } else if (race_choice == 3) {
    std::cout << "Svart Alf choosen.\n";
    Player.Race = "Svart Alf";
    Player.RaceStats[0] = +0;
    Player.RaceStats[1] = +2;
    Player.RaceStats[2] = +0;
    Player.RaceStats[3] = +2;
    Player.RaceStats[4] = +0;
    Player.RaceStats[5] = -2;
  } else if (race_choice == 4) {
    std::cout << "Tomte choosen.\n";
    Player.Race = "Tome";
    Player.RaceStats[0] = -2;
    Player.RaceStats[1] = +0;
    Player.RaceStats[2] = +0;
    Player.RaceStats[3] = +2;
    Player.RaceStats[4] = +2;
    Player.RaceStats[5] = +0;
  } else {
    std::cout << "idk brother, gl\n";
  }
}

void UpdateValues() {
  Player.DamageDice = Player.Level;
  if (Player.Class == "Fighter") {
    Player.BaseHealth = 10;
  }
  if (Player.Class == "Rogue") {
    Player.BaseHealth = 8;
  }
  if (Player.Class == "Cleric") {
    Player.BaseHealth = 8;
  }
  if (Player.Class == "Wizard") {
    Player.BaseHealth = 6;
  }
  Player.Str = 10 + Player.ClassStats[0] + Player.RaceStats[0];
  Player.Dex = 10 + Player.ClassStats[1] + Player.RaceStats[1];
  Player.Con = 10 + Player.ClassStats[2] + Player.RaceStats[2];
  Player.Int = 10 + Player.ClassStats[3] + Player.RaceStats[3];
  Player.Wis = 10 + Player.ClassStats[4] + Player.RaceStats[4];
  Player.Cha = 10 + Player.ClassStats[5] + Player.RaceStats[5];
  Player.DamageDice = (Player.Level + 1) / 2;
  Player.DamageBonus = (Player.Str - 10) / 2;
  Player.MaxHealth = Player.Level * Player.BaseHealth + ((Player.Con - 10) / 2);
  Player.CurHealth = Player.MaxHealth;
}
