

#include "Monster.h"

//Name: Monster (Constructor)
//Precondition: Must have the level of the game.
//Sets the name of the monster randomly from the monster.txt file.
//Sets the life and attack based on calculated values
//Postcondition: Loads a new monster with stats based on the level.
Monster::Monster(int level){

  // Monster stats for level 1
  if(level == 1){
    m_life = rand() % (50-20) + 20;
    m_attack = rand() % (5-1) + 1;
  }

  // Monster stats for level 2
  if(level == 2){
    m_life = rand() % (60-30) + 30;
    m_attack = rand() % (10-3) + 3;
  }

  // Monster stats for level 3
  if(level >= 3){
    m_life = rand() % (70-40) + 40;
    m_attack = rand() % (15-5) + 5;
  }

  // Creates a list of all the monsters and
  // puts one in each level of the game
  LoadMonster();
  m_name = SummonMonster();

}

//Name: SummonMonster
//Precondition: Need to have the m_monster vector populated by LoadMonster
//Postcondition: Returns the string value of a random monster from the vector
string Monster::SummonMonster(){

  // Picks a random monster from the monster list
  int randomMonster = rand() % 29;
  return m_monster.at(randomMonster);
}

//Name: LoadMonster
//Precondition: Must have the m_monster vector available and the monster.txt
//Postcondition: Populates the m_monster vector with the monster names in the file
void Monster::LoadMonster(){

  // Opens the text file with the monsters
  ifstream monsters;
  monsters.open("monster.txt");

  // Takes each monster and puts them in the monster vector
  string name;
  while(getline(monsters, name)){
    m_monster.push_back(name);
  }
}

//Name: Attack
//Precondition: Must have a form of Ben to attack
//Postcondition: Reduces current version of Ben by calculated damage
void Monster::Attack(Ben *&target){

  //Displays an attack message and decreases Ben's life
  cout << GetName() << " attacks Ben." << endl;
  target->SetLife(target->GetLife() - m_attack);
  cout << GetName() << " did " << m_attack << " to " << target->GetName() << endl;
  
}
//Name: Mutators and Accessors
//Normal getters and setters
void Monster::SetLife(int life){
  m_life = life;
}

int Monster::GetLife(){
  return m_life;
}

string Monster::GetName(){
  return m_name;
}




