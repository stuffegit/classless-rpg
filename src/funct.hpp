#ifndef FUNCT_HPP
#define FUNCT_HPP

#include <iostream>
#include <string>

// prefiring funct so cpp doesnt fkn whine
void DebugDataFull();
void DebugData();
void char_creation();
void class_select();
void race_select();
void profession_select();
void birthplace_select();
void UpdateValues();
void ClearScreen();
void ClearStats();
void Combat();
void RandomEnemyForest();
void Press_Enter();
void CheckLvlUp();
void Resting();
void Town();
void DisplayCombatStats();
void DisplayPlayerStats();
void DisplayEnemyStats();
void PressEnter();

// Structs
struct {
  int CCMaxHealth{1};
  int MaxHealth{1};
  int CurHealth{1};
  int BaseHealth{0};

  int DamageDie{1};
  int DamageDice{1};
  int DamageBonus{1};

  std::string Class = "Civilian";
  std::string Race = "Uncertain";
  std::string Profession = "";
  std::string Birthplace = "";

  int Level{1};
  int Exp{0};
  int Silver{0};
  int Rested{0};
  int Defeated{0};
  int Region{0};

  int ClassStats[6] = {0, 0, 0, 0, 0, 0};
  int RaceStats[6] = {0, 0, 0, 0, 0, 0};

  int Str{10};
  int Dex{10};
  int Con{10};
  int Int{10};
  int Wis{10};
  int Cha{10};

} Player;

struct {
  std::string Name{"Missingno"};
  int Health{100};
  int AC{1};
  int DamageDie{10};
  int DamageDice{20};
  int DamageBonus{0};
  int Level{1};
  int Silver{1};
} Enemy;

void DebugData() {

  std::cout << "Debug stats:\n";
  std::cout << Player.MaxHealth << "\t Player.MaxHealth\n";
  std::cout << Player.CurHealth << "\t Player.CurHealth\n";
  std::cout << "1d" << Player.DamageDie << "\t Player.DamageDie\n";
}

void DebugDataFull() {

  std::cout << "Debug stats:\n";
  std::cout << Player.CCMaxHealth << "\t Player.CCMaxHealth\n";
  std::cout << Player.CurHealth << "\t Player.CurHealth\n";
  std::cout << Player.MaxHealth << "\t Player.MaxHealth\n";
  std::cout << Player.BaseHealth << "\t Player.BaseHealth\n";
  std::cout << Player.DamageDie << "\t Player.DamageDie\n";
  std::cout << Player.Silver << "\t Player.Silver\n";
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

#endif
