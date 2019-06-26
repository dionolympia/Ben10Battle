

#include "Crystalsapien.h"
#include "Ben.h"
#include "Pyronite.h"
#include "Monster.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

const int ULTIMATE_ATTACK_BONUS = 10;

using namespace std;

//Name: Attack
//Precondition: Requires target
//Postcondition: Does calculated damage to the target based on table in project doc
void Crystalsapien::Attack(Monster *&target){

  //Displays attack message and calculates miss chance and damage
  cout << "Crystalsapien attacks using his energy attack." << endl;
  int miss = rand() % 100 + 1;
  int damage = rand() % (m_maxDamageNormal - m_minDamageNormal) + m_minDamageNormal;

  //Attack misses
  if(miss <= m_missPercent){
    cout << "The attack missed." << endl;
  }

  //Decreases monster life if attack hits
  else{
    target->SetLife(target->GetLife() - damage);
    cout << "Crystalsapien did " << damage << " to " << target->GetName() << endl;
  }
}
//Name: Special Attack
//Precondition: Requires target (finite uses)
//Postcondition: Does calculated damage to the target based on table in projec\t doc
void Crystalsapien::SpecialAttack(Monster *&target){

  // Decreases monster life by calculated damage
  if (m_usedSpecial < m_maxSpecial){
    cout << "Crystalsapien attacks using his laser attack." << endl;
    int damage = m_damageSpecial;
    target->SetLife(target->GetLife() - damage);
    cout << "Crystalsapien did " << damage << " to " << target->GetName() << endl;
    m_usedSpecial = m_usedSpecial +1;
  }

  //Tells user they don't have any special attacks left
  else{
    cout << "Crystalsapien does not have any special attacks left." << endl;
  }
}

//Name: Ultimate Attack
//Precondition: Requires target (unlimited  uses)
//Postcondition: Does calculated damage to the target (10x special attack damage)
void Crystalsapien::UltimateAttack(Monster *&target){

  //Displays attack message and decreases monster life by ultimate damage
  cout << "Crystalsapien attacks using **ULTIMATE** ATTACK!!" << endl;
  int damage = m_damageSpecial * ULTIMATE_ATTACK_BONUS;
  target->SetLife(target->GetLife() - damage);
  cout << "Crystalsapien did " << damage << " to " << target->GetName() << endl;
}
