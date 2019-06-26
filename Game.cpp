

#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

const int START_LIFE = 100;
const int FORMS_OF_BEN = 3;
const int NUM_MONSTERS = 29;

//Name: Game (Constructor)
//Precondition: None
//Postcondition: Game is started with monsters initialized, ben initialized,
//decides number of levels
Game::Game(){
  m_level = 1;
  Start(START_LIFE);
}

//Name: Start
//Precondition: Starts the game (Primary driver of game)
//Postcondition: May exit if Ben dies (exits game) or Monster dies (goes to
//next level or wins game!
void Game::Start(int startLife){
  
  //Sets up the levels, monsters, forms of Ben, and stats of monster and Bens
  NumLevels();
  InitBen();
  InitMonsters();
  SetBen(startLife);
  bool gameOn = Input();
  
  //Keeps playing game when Ben is alive and there are more levels
  while(gameOn == true){
    gameOn = Input();
  }
  
} 

//Name: NumLevels
//Precondition: Prompts user for number of levels between 1 and 20
//Postcondition: Returns user response
int Game::NumLevels(){

  //Asks user for how many games they want to play
  int numLevels;
  while(numLevels < 1 || numLevels > 20){
    cout << "How many levels would you like to try?" << endl;
    cin >> numLevels;

    //Validation
    if(numLevels < 1 || numLevels > 20){
      cout << "Invalid input; please re-enter." << endl;
    }
  }

  //Sets total levels to their choice of levels
  m_levels = numLevels;
  return numLevels;
}

//Name: InitMonsters
//Precondition: Requires m_mons
//Postcondition: Dynamically populates m_mons with one monster per level
void Game::InitMonsters(){
  
  // Creates a monster for each level of the game
  m_mons = new Monster* [m_levels];
  for(unsigned int i = 0; i < static_cast<unsigned int>(m_levels); i++){
    Monster* currentMonster;
    currentMonster = new Monster(i+1);
    m_mons[i] = currentMonster;
  }
}

//Name: InitBen
//Precondition: Requires m_ben
//Postcondition: Dynamically populates m_ben with all possible forms
// Level 1 = Ben, Level 2 = Pyronite, Level 3 = Crystalsapien
void Game::InitBen(){
  
  //Creates an array to store the forms of ben
  m_ben = new Ben* [FORMS_OF_BEN];
  
  string name = "Ben"; //Initialization of Ben stats
  int life = START_LIFE;
  string nameNormal = "hand-to-hand";
  string nameSpecial = "kick";
  double defenseBonus = 0;
  double missPercent = 10;
  int usedSpecial = 0;
  int maxSpecial = 2;
  int minDamNorm = 10;
  int maxDamNorm = 20;
  int damSpec = 30;
  
  //Creates a the Normal(Ben) form of Ben
  m_ben[0] = new Ben(name, life, nameNormal, nameSpecial,
		     defenseBonus, missPercent, usedSpecial,
		     maxSpecial, minDamNorm, maxDamNorm, damSpec);

  string pname = "Pyronite"; //Initialization of Pyronite stats
  int plife = START_LIFE;
  string pnameNormal = "fire";
  string pnameSpecial = "flamer";
  double pdefenseBonus = 0;
  double pmissPercent = 15;
  int pusedSpecial = 0;
  int pmaxSpecial = 1;
  int pminDamNorm = 15;
  int pmaxDamNorm = 20;
  int pdamSpec = 25;
  
  //Creates the Pyronite form of Ben
  m_ben[1] = new Pyronite(pname, plife, pnameNormal, pnameSpecial, pdefenseBonus, 
			  pmissPercent, pusedSpecial, pmaxSpecial, pminDamNorm, 
			  pmaxDamNorm, pdamSpec);
  
  string cname = "Crystalsapien"; //Initialization of Crystalsapien stats
  int clife = START_LIFE;
  string cnameNormal = "energy";
  string cnameSpecial = "laser";
  double cdefenseBonus = 25;
  double cmissPercent = 25;
  int cusedSpecial = 0;
  int cmaxSpecial = 1;
  int cminDamNorm = 25;
  int cmaxDamNorm = 30;
  int cdamSpec = 10;
  
  //Creates the Crystalsapien form of ben
  m_ben[2] = new Crystalsapien(cname, clife, cnameNormal, cnameSpecial, cdefenseBonus,
			       cmissPercent, cusedSpecial, cmaxSpecial, cminDamNorm,
			       cmaxDamNorm, cdamSpec);
}

//Name: SetBen
//Precondition: Requires populated m_ben (Lists all possible Bens for that level)
//Postcondition: Sets m_currBen based on the user choice
void Game::SetBen(int startLife){
  
  //Displays current level to player
  cout << "\t\t\t The game starts..." << endl
       << "\t\t\t LEVEL " << m_level << " of " << m_levels << endl;
  
  int choice = 0;

  //Keeps the the health value the for each form of ben the same (for each level)
  m_ben[0]->SetLife(startLife);
  m_ben[1]->SetLife(startLife);
  m_ben[2]->SetLife(startLife);
  
  //Asks the user to pick the form of Ben they want to play
  while(choice < 1 || choice > m_level){
    
    cout << "Select one from the available forms of Ben at " << "level " << m_level
	 << " are: " << endl;

    //Only Ben for available at level 1
    if(m_level == 1){
      cout << "1. " << m_ben[0]->GetName() << endl;
    }

    //Ben and Pyronite available at level 2
    if(m_level == 2){
      cout << "1. " << m_ben[0]->GetName() << endl 
	   << "2. " << m_ben[1]->GetName() << endl;
    }
    
    // Ben, Pyronite, and Crystalsapien available at level 3+
    if(m_level >= 3){
      cout << "1. " << m_ben[0]->GetName() << endl 
	   << "2. " << m_ben[1]->GetName() << endl
	   << "3. " << m_ben[2]->GetName() << endl;
    }
    
   
    //Asks for their choice of Ben's form
    cout << "What would you like to do?" << endl 
	 << "Enter 1 to " << m_level << endl;
    cin >> choice;

    //Validation
    if(choice < 1 || choice > m_level){
      cout << "Invalid input;, please re-enter." << endl
	;
    }
  }
  
  //Sets the current Ben to their choice
  m_currBen = m_ben[choice - 1];
}

//Name: Input
//Precondition: Checks to see if Ben and monster are alive
//During: Prompts user with menu
//Postcondition: Manages types of attacks (normal, special, or ultimate)
bool Game::Input(){
  
  //Sets the current monster of the level
  m_currMons = m_mons[m_level - 1];

  //Displays the names and health of the current form of Ben and
  //the current monster
  cout << "BEN: " << m_currBen->GetName() << endl  
       << "MONSTER: " << m_currMons->GetName() << endl;
  
  cout << m_currBen->GetName() << ": " << m_currBen->GetLife() << "\t"
       << m_currMons->GetName() << ": " << m_currMons->GetLife() << endl;
  
  //Asks the user for their choice of attack
  int choice = 0;
  while (choice < 1 || choice > 3){
    cout << "What would you like to do?" << endl
	 << "1. Normal Attack" << endl
	 << "2. Special Attack" << endl
	 << "3. Ultimate Attack" << endl
	 << "Enter 1 to 3:" << endl;
    cin >> choice;

    //Validation
    if (choice < 1 || choice > 3){
      cout << "Invalid input; please re-enter" << endl;
    }
  }
  
  //Choice 1 = Attack
  if(choice == 1){
    m_currBen->Attack(m_currMons);
  }

  //Chocie 2 = Special Attack
  if(choice == 2){
    m_currBen->SpecialAttack(m_currMons);
  }

  //Choice 3 = Ultimate attack
  if(choice == 3){
    m_currBen->UltimateAttack(m_currMons);
  }
  
  
  // When monster dies, the user progresses to the next level or
  // the game is over
  if(m_currMons->GetLife() <= 0){     
    m_level = m_level +1;

    // When the last level is completed, the user wins the game
    if (m_level > m_levels){
      cout << "Congrats! You won the game!" << endl;
      return false;
    }

    // Progresses to the next level and asks for the user for their
    // choice of the form of Ben they want to use
    else{
      cout << "Congrats! " << m_currBen->GetName() << " won that level." << endl;
      SetBen(m_currBen->GetLife());
      return true;
    }
  }
  
  // Monster attacks Ben
  m_currMons->Attack(m_currBen);
  
  // If Ben reaches level 0, then the game is over
  if(m_currBen->GetLife() <= 0){
    cout << m_currBen->GetName() << " died." << endl
	 << "You lost." << endl;
    return false;
  }
  
  return true;

}






  
 




