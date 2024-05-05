#ifndef FUNCT_H
#define FUNCT_H

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
void RollStats();
void ClearScreen();
void Combat();
void RandomEnemy();
void Press_Enter();
void CheckLvlUp();
void Resting();
void Town();
void DisplayCombatStats();
int PressEnter;

// Structs
struct {
  int CCMaxHealth{0};
  int MaxHealth{0};
  int CurHealth{0};
  int BaseHealth{4};
  int ClassHealthBonus{0};
  int RaceHealthBonus{0};
  int ProfessionHealthBonus{0};
  int BirthplaceHealthBonus{0};

  int CCMaxMana{0};
  int MaxMana{0};
  int CurMana{0};
  int BaseMana{0};
  int ClassManaBonus{0};
  int RaceManaBonus{0};
  int ProfessionManaBonus{0};
  int BirthplaceManaBonus{0};

  int DamageDie{0};
  int DamageDice{0};
  int BaseDamageDie{4};
  int HeritageDamageBonus{0};
  int ClassDamageDieBonus{0};
  int RaceDamageDieBonus{0};
  int ProfessionDamageDieBonus{0};
  int BirthplaceDamageDieBonus{0};

  std::string Class = "";
  std::string Race = "";
  std::string Profession = "";
  std::string Birthplace = "";

  int Level{1};
  int Exp{0};

} Player;

struct {
  std::string Name{"Missingno"};
  int Health{0};
  int AC{0};
  int DamageDie{0};
  int DamageDice{0};
  int Exp{0};
} Enemy;

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

#endif
