#ifndef CC_H
#define CC_H
#include "funct.h"
#include <iomanip> // for setw()
#include <iostream>

void char_creation() {
  char cc_choice;
  int cc_done{0};
  do {
    UpdateValues();
    ClearScreen();
    std::cout << std::setw(20) << std::left;
    std::cout << "Stats: ";
    std::cout << "Class: " << Player.Class << "\n";

    std::cout << "HP: 1d" << std::setw(14) << std::left << Player.CCMaxHealth;
    std::cout << std::setw(9) << "Race: " << Player.Race << "\n";

    if (Player.CCMaxMana > 0) {
      std::cout << "MP: 1d" << std::setw(14) << std::left << Player.CCMaxMana;
      std::cout << std::setw(12) << "Profession: " << Player.Profession << "\n";
    } else {
      std::cout << "MP: " << std::setw(16) << std::left << Player.CCMaxMana;
      std::cout << std::setw(12) << "Profession: " << Player.Profession << "\n";
    }

    std::cout << "DmgDie: 1d" << std::setw(10) << std::left << Player.DamageDie;
    std::cout << std::setw(9) << "Birthplace: " << Player.Birthplace << "\n\n";

    std::cout << "1: Class\n";
    std::cout << "2: Race\n";
    std::cout << "3: Profession\n";
    std::cout << "4: Birthplace\n";
    if (Player.Class != "" && Player.Race != "" && Player.Birthplace != "" &&
        Player.Profession != "") {
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
    case '3':
      profession_select();
      break;
    case '4':
      birthplace_select();
      break;
    case 'Q':
    case 'q':
      exit(0);
    case 'C':
    case 'c':
      if (Player.Class != "" && Player.Race != "" && Player.Birthplace != "" &&
          Player.Profession != "") {
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
  std::cout << "Class: " << Player.Class << "\n";
  std::cout << "Race: " << Player.Race << "\n";
  std::cout << "Profession: " << Player.Profession << "\n";
  std::cout << "Birthplace: " << Player.Birthplace << "\n\n";

  std::cout << "1: Warrior\n";
  std::cout << "2: Burglar\n";
  std::cout << "3: Mage\n";
  std::cout << "4: Cleric\n\n";
  std::cout << "Choice: ";
  std::cin >> class_choice;
  std::cout << "\n";

  if (class_choice == 1) {
    std::cout << "Warrior chosen.\n";
    Player.Class = "Warrior";
    Player.ClassHealthBonus = 6;
    Player.ClassManaBonus = 0;
    Player.ClassDamageDieBonus = 4;
  } else if (class_choice == 2) {
    std::cout << "Burglar chosen.\n";
    Player.Class = "Burglar";
    Player.ClassHealthBonus = 4;
    Player.ClassManaBonus = 6;
    Player.ClassDamageDieBonus = 4;
  } else if (class_choice == 3) {
    std::cout << "Mage chosen.\n";
    Player.Class = "Mage";
    Player.ClassHealthBonus = 2;
    Player.ClassManaBonus = 40;
    Player.ClassDamageDieBonus = 0;
  } else if (class_choice == 4) {
    std::cout << "Cleric chosen.\n";
    Player.Class = "Cleric";
    Player.ClassHealthBonus = 4;
    Player.ClassManaBonus = 20;
    Player.ClassDamageDieBonus = 2;
  } else {
    std::cout << "idk brother, gl\n";
  }
}

void race_select() {
  int race_choice{};
  ClearScreen();
  std::cout << "Class: " << Player.Class << "\n";
  std::cout << "Race: " << Player.Race << "\n";
  std::cout << "Profession: " << Player.Profession << "\n";
  std::cout << "Birthplace: " << Player.Birthplace << "\n\n";

  std::cout << "1: Man\n";
  std::cout << "2: Alf\n\n";
  std::cout << "Choice: ";
  std::cin >> race_choice;

  if (race_choice == 1) {
    std::cout << "Man chosen.\n";
    Player.Race = "Man";
    Player.RaceHealthBonus = 2;
    Player.RaceDamageDieBonus = 0;
    Player.RaceManaBonus = 0;
  } else if (race_choice == 2) {
    std::cout << "Alf choosen.\n";
    Player.Race = "Alf";
    Player.RaceHealthBonus = 0;
    Player.RaceDamageDieBonus = 0;
    Player.RaceManaBonus = 5;
  } else {
    std::cout << "idk brother, gl\n";
  }
}

void profession_select() {
  int profession_choice{};
  ClearScreen();
  std::cout << "Class: " << Player.Class << "\n";
  std::cout << "Race: " << Player.Race << "\n";
  std::cout << "Profession: " << Player.Profession << "\n";
  std::cout << "Birthplace: " << Player.Birthplace << "\n\n";

  std::cout << "1: Townsguard\n";
  std::cout << "2: Librarian\n";
  std::cout << "3: Mercenary\n";
  std::cout << "Choice: ";
  std::cin >> profession_choice;

  if (profession_choice == 1) {
    std::cout << "Townsguard chosen.\n";
    Player.Profession = "Townsguard";
    Player.ProfessionHealthBonus = 2;
    Player.ProfessionManaBonus = 0;
    Player.ProfessionDamageDieBonus = 0;
  } else if (profession_choice == 2) {
    std::cout << "Librarian chosen.\n";
    Player.Profession = "Librarian";
    Player.ProfessionHealthBonus = 0;
    Player.ProfessionManaBonus = 10;
    Player.ProfessionDamageDieBonus = 0;
  } else if (profession_choice == 3) {
    std::cout << "Mercenary chosen.\n";
    Player.Profession = "Mercenary";
    Player.ProfessionHealthBonus = 0;
    Player.ProfessionManaBonus = 0;
    Player.ProfessionDamageDieBonus = 2;
  } else {
    std::cout << "idk brother, gl\n";
  }
}

void birthplace_select() {
  int birthplace_choice{};
  ClearScreen();
  std::cout << "Class: " << Player.Class << "\n";
  std::cout << "Race: " << Player.Race << "\n";
  std::cout << "Profession: " << Player.Profession << "\n";
  std::cout << "Birthplace: " << Player.Birthplace << "\n\n";

  std::cout << "1: Calm Village\n";
  std::cout << "2: Druids Grove\n";
  std::cout << "3: Warzone Camp\n";
  std::cout << "Choice: ";
  std::cin >> birthplace_choice;

  if (birthplace_choice == 1) {
    std::cout << "Calm Village chosen.\n";
    Player.Birthplace = "Calm Village";
    Player.BirthplaceHealthBonus = 2;
  } else if (birthplace_choice == 2) {
    std::cout << "Druids Grove chosen.\n";
    Player.BirthplaceManaBonus = 10;
    Player.Birthplace = "Druids Grove";
  } else if (birthplace_choice == 3) {
    std::cout << "Warzone Camp chosen.\n";
    Player.HeritageDamageBonus = 1;
    Player.Birthplace = "Warzone Camp";
  } else {
    std::cout << "idk brother, gl\n";
  }
}

void RollStats() {
  Player.MaxHealth = (rand() % Player.CCMaxHealth + 1) + 6;
  Player.CurHealth = Player.MaxHealth;
  if (Player.CCMaxMana > 0) {
    Player.MaxMana = rand() % Player.CCMaxMana + 1;
    Player.CurMana = Player.MaxMana;
  } else {
    Player.MaxMana = 0;
    Player.CurMana = 0;
  }
}

void UpdateValues() {
  Player.CCMaxHealth = Player.BaseHealth + Player.ClassHealthBonus +
                       Player.RaceHealthBonus + Player.ProfessionHealthBonus +
                       Player.BirthplaceHealthBonus;
  Player.CCMaxMana = Player.BaseMana + Player.ClassManaBonus +
                     Player.RaceManaBonus + Player.ProfessionManaBonus +
                     Player.BirthplaceManaBonus;
  Player.DamageDie = Player.BaseDamageDie + Player.ClassDamageDieBonus +
                     Player.RaceDamageDieBonus +
                     Player.ProfessionDamageDieBonus +
                     Player.BirthplaceDamageDieBonus;
  Player.DamageDice = 1;
  Player.CurHealth = Player.CCMaxHealth;
  Player.CurMana = Player.CCMaxMana;
  if (Player.CCMaxMana < 0) {
    Player.CurMana = 0;
    Player.CCMaxMana = 0;
  }
}

#endif
