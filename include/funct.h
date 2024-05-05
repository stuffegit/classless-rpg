#ifndef FUNCT_H
#define FUNCT_H

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
void DisplayCombatStats();

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

#endif
