#ifndef TOWN_H
#define TOWN_H
#include "funct.h"
#include "resting.h"
#include <iostream>

void Town() {
  ClearScreen();
  std::cout << "Would you like to head into town? Y/N\n";
  char townchoice{};
  char townactivity{};
  int towndone{0};
  int rested{0};
  std::cin >> townchoice;

  if (townchoice == 'y' or townchoice == 'Y') {
    do {
      ClearScreen();
      std::cout << "1: Rest\n";
      std::cout << "2: PH\n";
      std::cout << "3: PH\n";
      std::cout << "4: PH\n";
      std::cout << "Q: Quit Town\n";
      std::cin >> townactivity;
      switch (townactivity) {
      case '1':
        if (rested == 0) {
          Resting();
        } else {
          ClearScreen();
          std::cout << "I already rested for today.";
          Press_Enter();
        }
        rested = 1;
        break;
      case '2':
        std::cout << "Choice 2";
        break;
      case '3':
        std::cout << "Choice 3";
        break;
      case '4':
        std::cout << "Choice 4";
        break;
      case 'Q':
      case 'q':
        ClearScreen();
        std::cout << "Leaving Town..";
        Press_Enter();
        ClearScreen();
        towndone = 1;
        break;
      }
    } while (towndone != 1);
  } else if (townchoice == 'n' or townchoice == 'N') {
    ClearScreen();
    std::cout << "Continuing the hunt..";
    Press_Enter();
    ClearScreen();
  }
}

#endif
