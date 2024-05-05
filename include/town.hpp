#ifndef TOWN_H
#define TOWN_H
#include "funct.hpp"
#include "resting.hpp"
#include <iostream>

void Town() {
  ClearScreen();
  DisplayPlayerStats();
  std::cout << "Silver: " << Player.Silver << "\n";
  std::cout << "Would you like to head into town? Y/N\n";
  char townchoice{};
  char townactivity{};
  int towndone{0};
  Player.Rested = 0;
  std::cin >> townchoice;

  if (townchoice == 'y' or townchoice == 'Y') {
    do {
      ClearScreen();
      DisplayPlayerStats();
      std::cout << "1: Inn\n";
      std::cout << "2: Guilds\n";
      std::cout << "3: Blacksmith\n";
      std::cout << "4: General Store\n";
      std::cout << "Q: Quit Town\n";
      std::cin >> townactivity;
      switch (townactivity) {
      case '1':
        if (Player.Rested == 0) {
          Resting();
        } else {
          ClearScreen();
          std::cout << "I already rested for today.";
          Press_Enter();
        }
        Player.Rested = 1;
        break;
      case '2':
        ClearScreen();
        std::cout << "TODO: Implement Guilds for quests";
        Press_Enter();
        break;
      case '3':
        ClearScreen();
        std::cout << "TODO: Implement Blacksmith";
        Press_Enter();
        break;
      case '4':
        ClearScreen();
        std::cout << "TODO : Implement General store";
        Press_Enter();
        break;
      case 'Q':
      case 'q':
        ClearScreen();
        DisplayPlayerStats();
        std::cout << "Leaving Town..";
        Press_Enter();
        ClearScreen();
        towndone = 1;
        break;
      }
    } while (towndone != 1);
  } else if (townchoice == 'n' or townchoice == 'N') {
    ClearScreen();
    DisplayPlayerStats();
    std::cout << "Continuing the hunt..";
    Press_Enter();
    ClearScreen();
  }
}

#endif
