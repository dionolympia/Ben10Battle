

#include "Pyronite.h"
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include "Monster.h"
#include "Ben.h"

using namespace std;

//Name: Attack
//Precondition: Requires target
//Postcondition: Does calculated damage to the target based on table in project doc
void Pyronite::Attack(Monster *&target){

  //Displays attack message and calculates miss chance and damage
  cout << "Pyronite attacks using his fire attack." << endl;
  int miss = rand() % 100 + 1;
  int damage = rand() % (m_maxDamageNormal - m_minDamageNormal) + m_minDamageNormal;

  //Displays a miss message
  if(miss <= m_missPercent){
    cout << "The attack missed." << endl;
  }

  //Decreases monster life when attack hits
  else{
    target->SetLife(target->GetLife() - damage);
    cout << "Pyronite did " << damage << " to " << target->GetName() << endl;
  }
}

//Name: Special Attack
//Precondition: Requires target (finite uses)
//Postcondition: Does calculated damage to the target based on table in project doc
void Pyronite::SpecialAttack(Monster *&target){

  //Decreases Monster life by calculated damage
  if(m_usedSpecial < m_maxSpecial){
    cout << "Pyronite attacks using his flamer attack." << endl;
    int damage = m_damageSpecial;
    target->SetLife(target->GetLife() - damage);
    cout << "Pyronite did " << damage << " to " << target->GetName() << endl;

    // Uses up a special attack
    m_usedSpecial = m_usedSpecial + 1;
  }

  //Displays to the user that they cannot use anymore special attacks
  else {
    cout << "Pyronite does not have any special attacks left." << endl;
  }
}
    
