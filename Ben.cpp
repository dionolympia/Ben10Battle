


#include "Ben.h"
#include "Monster.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

const int BEN_NORMAL_MISS = 10;
const int BEN_NORMAL_MIN = 10;
const int BEN_NORMAL_MAX = 20;
const int BEN_SPECIAL_DMG = 25;
const int BEN_SPECIAL_QUANTITY = 2;

using namespace std;

//Name: Ben (Constructor)
//Precondition: Need to have the name and the life (from table in project doc)
//Postcondition: Creates a default version of Ben (not transformed)
Ben::Ben(string name, int life){
  m_name = name;
  m_life = life;
}

//Name: Ben (Overloaded constructor)
//Precondition: Need to have all of the stats for an advanced form
//Data from table in project document
//Postcondition: Creates a specific version of Ben for use in transformed versions
Ben::Ben(string name, int life, string nameNorm, string nameSpecial,
	 double defenseBonus, double missPercent, int usedSpecial, 
	 int maxSpecial, int minDamNorm, int maxDamNorm, int damSpec){
  m_name = name; 
  m_life = life;
  m_nameNormal = nameNorm;
  m_nameSpecial = nameSpecial;
  m_defenseBonus = defenseBonus;
  m_missPercent = missPercent;
  m_usedSpecial = usedSpecial;
  m_maxSpecial = maxSpecial;
  m_minDamageNormal = minDamNorm;
  m_maxDamageNormal = maxDamNorm;
  m_damageSpecial = damSpec; 
}

//Name: ~Ben
//Precondition: Dynamically allocated Ben (using new)
//Postcondition: Removes allocated Ben from memory
//~Ben();
//Name: Attack
//Precondition: Need a target (May miss!)
//Postcondition: Reduces life of target with output
void Ben::Attack(Monster *&target){

  //Displays an attack message
  cout << "Ben attacks using his hand-to-hand attack." << endl;

  //Gets random values to determine is damage and miss chance
  int miss = rand() % (static_cast <int>(m_missPercent) + 1);
  int damage = rand() % (m_maxDamageNormal - m_minDamageNormal) + m_minDamageNormal;

  //Decreases Monster life by calculated damage if attack hits
  if(miss > 1){
    target->SetLife(target->GetLife() - damage);
    cout << "Ben did " << damage << " to " << target->GetName() << endl;
  }
  //Does nothing if the attack misses
  else{
    cout << "The attack missed." << endl;
  }
}

//Name: Special Attack
//Precondition: Needs a target (Finite number of special attacks by form)
//Postcondition: Reduces life of target with output
void Ben::SpecialAttack(Monster *&target){

  //Decreases Monster life by calculated damage if attack hits
  if(m_usedSpecial < m_maxSpecial){
    cout << "Ben attacks using his kick attack." << endl;
    int damage = m_damageSpecial;
    target->SetLife(target->GetLife() - damage);
    cout << "Ben did " << damage << " to " << target->GetName() << endl;

    // Uses up one of Ben's special attacks
    m_usedSpecial = m_usedSpecial + 1;
  }    

  //Tells ths user they used all of the special attacks
  else{
    cout << "Ben does not have any special attacks left." << endl;
  }
}
  
//Name: Ultimate Attack
//Precondition: Needs a target (only available with Crystalsapien)
//Postcondition: Reduces life of target with output
void Ben::UltimateAttack(Monster *&target){

  //Tells user Ben doesn't have an ultimate attack
  cout << "Ben has no ultimate attack! " << target->GetName() 
       << " retaliates!" << endl;
}

//Name: Mutators and Acccessors
void Ben::SetLife(int life){
  m_life = life;
}

string Ben::GetName(){
  return m_name;
}

int Ben::GetLife(){
  return m_life;
}



  
  

