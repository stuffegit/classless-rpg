#ifndef TOWN_HPP
#define TOWN_HPP
#include "funct.hpp"
#include "resting.hpp"
#include <iostream>

void Town() {
  ClearScreen();
  DisplayPlayerStats();
  std::cout << "\nSilver: " << Player.Silver << "\n";
  std::cout << "Would you like to head into town?\n";
  std::cout << "1. Yes\n";
  std::cout << "2. No\n";
  char townchoice{};
  char townactivity{};
  int towndone{0};
  Player.Rested = 0;
  std::cin >> townchoice;

  if (townchoice == '1') {
    do {
      ClearScreen();
      DisplayPlayerStats();
      std::cout << "\n1: Inn\n";
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
        std::cout << "\nLeaving Town..";
        Press_Enter();
        ClearScreen();
        towndone = 1;
        break;
      }
    } while (towndone != 1);
  } else {
    ClearScreen();
    DisplayPlayerStats();
    std::cout << "\nContinuing the hunt..";
    Press_Enter();
    ClearScreen();
  }
}

#endif
