#include "market.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//---------------------- Market -----------------//

Market::Market(Potion**& pot_array, Spell**& spe_array, Weapon**& wea_array, Armor**& arm_array) {	 //Constructor for class Market, initializes data members
	int i, j;
	
	for(i=0 ; i < 5; i++) {		//An array that saves which items have already been selected, receives positive values (indexes of another array)
		jeys[i]= -1;			//Any negative value means that this position has not taken any index yet
	}
	
	//The market will sell 5 items of each category
	spell_stock= new Spell* [5];
	potion_stock= new Potion* [5];
	weapon_stock= new Weapon* [5];
	armor_stock= new Armor* [5];
	
	for (i=0 ; i < 5 ; i++) {
		j= rand()%10;
		
		if (is_in_selected_jeys(j)) {		//If the entries #j have already been chosen
			i--;							//Ignore them, make a new selection
			continue;
		}
		
		add_in_selected_jeys(j);			//If the entries #j are not already in the market's tables
		spell_stock[i]= spe_array[j];
		potion_stock[i]= pot_array[j];
		weapon_stock[i]= wea_array[j];
		armor_stock[i]= arm_array[j];
	}
}

Item* Market::get_item(string key) {       	//Returns the item with name key, if it does exist in the stock
	int i;
	
	//Check every stock and return the item if it is found
	for (i=0; i < 5 ; i++) {
		if (potion_stock[i]->get_name() == key) {
			return potion_stock[i];
		}
		else if (spell_stock[i]->get_name() == key) {
			return spell_stock[i];
		}
		else if (weapon_stock[i]->get_name() == key) {
			return weapon_stock[i];
		}
		else if (armor_stock[i]->get_name() == key) {
			return armor_stock[i];
		}
	}
	//If the item was not found in any stock then probably doesn't exist
	cout << "The item you inserted doesn't exist in this market!" << endl;
	return NULL;                //There is nothing to be returned
}

Market::~Market() {		//Destructor of class market, frees the arrays of pointers, not the instances of items. The items are being deleted in main  function
	delete spell_stock;
	delete weapon_stock;
	delete potion_stock;
	delete armor_stock;
}

void Market::show_spells() {										//A function to print all the available spells on the screen
	int i;
	
	cout << "All the spells available in our stock are:\n" << endl;
	for (i=0; i < 5 ; i++) {
		cout << i << ". " ;
		spell_stock[i]->small_info();
		cout << "" << endl;
	}
}
void Market::show_potions() {										//A function to print all the available potions on the screen
	int i;
	
	cout << "All the potions available in our stock are:" << endl;
	for (i=0; i < 5 ; i++) {
		cout << i << ". " ;
		potion_stock[i]->small_info() ;
		cout << "" << endl;
	}
}

void Market::show_weapons() {										//A function to print all the available weapons on the screen
	int i;
	
	cout << "All the weapons available in our stock are:" << endl;
	for (i=0; i < 5 ; i++) {
		cout << i << ". " ;
		weapon_stock[i]->small_info();
		cout << "" << endl;
	}
}

void Market::show_armors() {										//A function to print all the available armors on the screen
	int i;
	
	cout << "All the armors available in our stock are:" << endl;
	for (i=0; i < 5 ; i++) {
		cout << i << ". " ;
		armor_stock[i]->small_info();
		cout << "" << endl;
	}
}



void Market::show_buyable(Hero* hero) {							//A function to print only the items of each category that a specific hero can afford
	int i, j;
	
	j=0;
	cout << "At the moment you can buy the following stuff:\n" << endl;
	cout << "\nSpells:" << endl;
	for (i=0; i < 5 ; i++) {
		if (spell_stock[i]->get_price() <= hero->get_money() && spell_stock[i]->get_min_level() <= hero->get_level()) {
			j++;
			cout << j << ". " ;
			spell_stock[i]->small_info() ;
			cout << "" << endl;
		}		
	}
	cout << "\nPotions:" << endl;
	j=0;
	for (i=0; i < 5 ; i++) {
		if (potion_stock[i]->get_price() <= hero->get_money() && potion_stock[i]->get_min_level() <= hero->get_level()) {
			j++;
			cout << j << ". " ;
			potion_stock[i]->small_info() ;
			cout << "" << endl;
		}		
	}
	cout << "\nWeapons:" << endl;
	j=0;
	for (i=0; i < 5 ; i++) {
		if (weapon_stock[i]->get_price() <= hero->get_money() && weapon_stock[i]->get_min_level() <= hero->get_level()) {
			j++;
			cout << j << ". " ;
			weapon_stock[i]->small_info() ;
			cout << "" << endl;
		}		
	}
	cout << "\nArmors:" << endl;
	j=0;
	for (i=0; i < 5 ; i++) {
		if (armor_stock[i]->get_price() <= hero->get_money() && armor_stock[i]->get_min_level() <= hero->get_level()) {
			j++;
			cout << j << ". " ;
			armor_stock[i]->small_info() ;
			cout << "" << endl;
		}		
	}
}



void Market::item_to_be_sold(Item* item) {					//A function to remove an item that was sold from the stock
	int i;
	
	for (i=0; i < 5 ; i++) {
		if (spell_stock[i]->get_name() == item->get_name() ) {
			spell_stock[i]->set_name("None");
			return;
		}
		else if (potion_stock[i]->get_name() == item->get_name()) {
			potion_stock[i]->set_name("None");
			return;
		}
		else if (weapon_stock[i]->get_name() == item->get_name()) {
			weapon_stock[i]->set_name("None");
			return;
		}
	}
	cout << item->get_name() << " is not available in this market's stock!" << endl; 
}
	
bool Market::is_in_selected_jeys(int j) {					//A function that prevents inserting two same items in the stock
	int i;
	
	for(i=0; i < 5 ; i++) {
		if (j == jeys[i]) {
			return true;
		}
	}
	return false;
}


void Market::add_in_selected_jeys(int j) {					//A function that prevents inserting two same items in the stock
	int i;
	
	i=0;
	while(jeys[i]!= -1) {
		i++;
	}
	jeys[i]= j;
}


//------------------ end of Market -------------//


//-------------------- Box --------------------//

Box::Box(Potion**& potions_array, Spell**& spells_array, Weapon**& weapons_array, Armor**& armors_array)  //Constructor for class Box, initializes its data members
	:discovered(false)
{
	int i;
	
	i= rand()%100;
	
	//Randomly
	if (i < 75) { 							//75% this box will be a common one
		type= "common";
		market= NULL;
	}
	else if (i < 85) {					 	// 10% this box will be a non accessible one
		type= "non-accessible";
		market= NULL;
	}
	else { 									// 15% this box will be a market
		type= "market";
		market= new Market(potions_array, spells_array, weapons_array, armors_array);
	}
}

Box::Box(string str, Potion**& pot_array, Spell**& spe_array, Weapon**& wea_array, Armor**& armors_array)  //Constructor with preinitialized table
	: discovered(false)
{
	if (str == "c") {
		type= "common";
		market= NULL;
	} 
	else if (str == "n") {
		type= "non-accessible";
		market= NULL;
	}
	else if (str == "m") {
		type= "market";
		market= new Market(pot_array, spe_array, wea_array, armors_array);
	}
	else {
		cout << "ERROR in the grid initialization array" << endl;
	}
	
}

Box::~Box() { 								//Destructor for box, deletes the market
	delete market;
}

Market* Box::get_market()const {			
	return market;
}

bool Box::has_been_discovered()const {
	return discovered;
}

void Box::be_discovered() {
	discovered= true;
}

string Box::get_type()const {
	return type;
}

void Box::print(bool heroes_here)const {		// Prints the Box
	if (heroes_here) {
		if (type == "common") {
			cout << " X " ;
		}
		else {									// type == "market"
			cout << "M , X";
		}
	}
	else if (discovered == false) {
		cout << " ? ";
	}
	else {
		if (type == "common") {
			cout << " . " ;
		}
		else if (type == "market") {
			cout << " M ";
		}
		else { 									// type == "non-accessible"
			cout << " # ";
		}
	}

}

//------------------ end of Box --------------//


//------------------ Grid -------------------//

//Constructor for Grid, initializes data members with a preset array
Grid::Grid(string** preset_grid, Hero**& hero, int heroes_num, int dim_x, int dim_y, Potion**& pot_array, Spell**& spe_array, Weapon**& wea_array,
           Armor**& arm_array) 
	: heroes(hero), heroes_number(heroes_num), dimension_x(dim_x), dimension_y(dim_y),  monsters_number(0), market_box(NULL), 
	  battle_box(NULL)
{
	int i,j;
	
	for (i=0; i < 5; i++) {							//This array holds the selected indexes of another array
		jeys[i]= -1;								//It is initialized with negatives values that represent its emptyness
	}
	
	//Create the boxes
	box= new Box** [dimension_x];
	for(i=0; i < dimension_x ; i++) { 				//for every row
		box[i]= new Box* [dimension_y];
		for(j=0; j < dimension_y ; j++) { 			// for every column
			box[i][j]= new Box(preset_grid[i][j], pot_array, spe_array, wea_array, arm_array );
		}
	}
	
	//Set the start position fo the hero(es)
	while (1) {
		x= rand()%dimension_x;	
		y= rand()%dimension_y;
		
		if (box[x][y]->get_type() == "common") { 	//Stop when a common block is selected
			box[x][y]->be_discovered();
			break;
		}
	}
	
		
	Names n = Names();
	
}


//Constructors of Grid that initializes randomly its data members
Grid::Grid(Hero**& hero, int heroes_num, int dim_x, int dim_y, Potion**& pot_array, Spell**& spe_array, Weapon**& wea_array,
           Armor**& arm_array) 
	: heroes(hero), heroes_number(heroes_num), dimension_x(dim_x), dimension_y(dim_y),monsters_number(0), market_box(NULL), 
	  battle_box(NULL)
{
	int i,j;
	
	for(i=0 ; i < 5; i++) {							//This array holds the selected indexes of another array
		jeys[i]= -1;								//It is initialized with negatives values that represent its emptyness
	}	
	
	//Create the boxes
	box= new Box** [dimension_x];
	for(i=0; i < dimension_x ; i++) { 			//for every row
		box[i]= new Box* [dimension_y];
		for(j=0; j < dimension_y ; j++) { 		// for every column
			box[i][j]= new Box(pot_array, spe_array, wea_array, arm_array );
		}
	}
	
	//Set the start position fo the hero(es)
	while (1) {
		x= rand()%dimension_x;	
		y= rand()%dimension_y;
		
		if (box[x][y]->get_type() == "common") { 	//Stop when the selected block is a common one
			box[x][y]->be_discovered();
			break;
		}
	}
	
}

bool Grid::is_in_selected_jeys(int j) {		//This function prevents the creation of two (or more) same monsters in a battle
	int i;
	
	for(i=0; i < 5 ; i++) {					
		if (j == jeys[i]) {
			return true;
		}
	}
	return false;
}


void Grid::add_in_selected_jeys(int j) {	//This function prevents the creation of two (or more) same monsters in a battle 
	int i;
	
	i=0;
	while(jeys[i]!= -1) {
		i++;
	}
	jeys[i]= j;
}

int Grid::get_monsters_number()const {
	return monsters_number;
}

Market* Grid::get_market_box() const {
	return market_box;
}
	
Monster** Grid::get_battle_box()const {
	return battle_box;
}
	
	
Grid::~Grid() {									//Destructor of grid, delete every box of it
	
	int i,j;
	
	for(i=0; i < dimension_x ; i++) { 			//for every row
		for(j=0; j < dimension_y ; j++) { 		// for every column
			delete box[i][j];
		}
	}
	
	for(i=0; i < dimension_x ; i++) {
		delete box[i];
	}
	delete box;

	delete heroes;
	
	for(i=0; i < monsters_number ; i++) {
		delete battle_box[i];
	}
	
}
	
void Grid::print() const {							//Prints the whole Grid
	int i,j,k;
	
	for (i=0 ; i < dimension_x ; i++) { 			//for every row (top---->bottom)
		if (i == 0) { 								//if it is the first row
			for (k=0 ; k < dimension_y-1; k++) { 	// draw the upper border of the map
				cout << "_________";
			}
		}
		cout << "\n|                                          |\n" ;		//draw the side borders of the map
		for (j=0; j < dimension_y ; j++) { 			//for every column (left----->right)
			if (j == 0) { 							//if it is at the very left 
				cout << "|" ; 						//draw the left side border
			}
			if ( x== i & y == j) { 					//if it is the box where the hero(es) are
				box[i][j]->print(true);				//print the box with the heroes in it (true means heroes are here)
				if (j == dimension_y-1) { 			//if it is at the very right
					cout << "|"; 					//draw the right border of the map
				}
				else {
					cout << "	" ; 				//if it is in the middle, leave some free space
				}
			}
			else { 									//the heroes are not in that box
				box[i][j]->print(false); 			//print just the box (false means heroes are not here)
				if (j == dimension_y-1) { 			//if it is at the very right 
					cout << "|"; 					//draw the right border of the map
				}
				else {
					cout << "	" ; 				//if the box is in the middle, leave some free space 
				}
			}
		}
	}
	cout << "" << endl; 
	for (k=0 ; k < dimension_y-1; k++) {
				cout << "_________";
	}
	cout << "" << endl;
}

string Grid::move(string direction) {				//Receives a direction, and moves the players to it, if this is possible
	
	int i, lvl, how_many, initial_hp, j;
	string monster_name;
	
	initial_hp= 20;									//The minimum health power each monster has
	
	for(i=0 ; i < 5; i++) {							//Reinitialize the array with the selected indexes in every call of the function
		jeys[i]= -1;
	}
	
	if (direction == "up") {						//If the player wants to go up
		if (x != 0) {								//If the heroes are not at the first row of the grid
			if (box[x-1][y]->get_type() != "non-accessible") {	//If the block above them is an accessible one
				x--;											//Good, they can go there
				box[x][y]->be_discovered();						//Make the block visible (if not already)
				if (box[x][y]->get_type() == "market") {		//If it has a market
					this->market_box= box[x][y]->get_market();	//Update the class'es variable
					// cout << "Look, there is a market over there!" << endl;
					this->print();								//Print the grid
					return "m";
				}
				else { 											// If it doesn't have a market, so it is just a common block
					i= rand()%100;								
					if (i < 50) { 								// 50% a battle will take place there (some monsters will appear)
						lvl= heroes[0]->get_level() + (rand()%3);	//Their level will be close to heroes's level (maybe a little higher)
						how_many= rand()%3 + heroes_number ;		//The amount of monsters appeared can be less than the heroes's amount, can't be more than heroes's amount + 2 either
					
						//Free the allocated space of the last encountered monsters
						if (battle_box != NULL) {
							for (j= 0; j < this->monsters_number ; j++) {
								delete battle_box[j];
							}	
						}
						delete battle_box;
						
						//Allocate some space for the new monsters
						battle_box= new Monster* [how_many];
						monsters_number= how_many;					//Update the class's variable
						for (i= 0; i < how_many ; i++) {			//Create "how_many" monsters
							j= rand()%10; 
							if (this->is_in_selected_jeys(j)) {		//If this index has been chosen in the same call of the function
								i--;								//Ignore it, choose another one
								continue;
							}
							this->add_in_selected_jeys(j);
							j= rand()%3;							//The monster can be a Dragon, an Exoskeleton or a Spirit (same possibility)
							if (j == 0) {	
								battle_box[i]= new Dragon(this->n.get_monster_name(), lvl, initial_hp*lvl);	
							}
							else if (j == 1) {
								battle_box[i]= new Exoskeleton(this->n.get_monster_name(), lvl, initial_hp*lvl);
							}
							else {
								battle_box[i]= new Spirit(this->n.get_monster_name(), lvl, initial_hp*lvl);
							}
							
						}
						this->print();								//Print the grid
						return "b";
					}
					else { 											//If no battle takes place
						this->print();								//Print the grid
						return "c";
					}
				}
				
			}
			else { 													//If the block above is non accessible
				box[x-1][y]->be_discovered();						//Reveal it, make it visible
				this->print();										//Print the grid
				return "n";
			}
		}
		else {														//If heroes are already on the first row, they can't move any higher
			cout << "you can't go any higher than that!" << endl;
			return "e";
		}
	}
	else if (direction == "down") {
		if (x != dimension_x-1) {
			if (box[x+1][y]->get_type() != "non-accessible") {
				x++;
				box[x][y]->be_discovered();
				if (box[x][y]->get_type() == "market") {
					this->market_box= box[x][y]->get_market();
					// cout << "Look, there is a market over there!" << endl;
					this->print();
					return "m";
				}
				else { //common
					i= rand()%100;
					if (i < 50) { // battle
						lvl= heroes[0]->get_level() + (rand()%3);
						how_many= rand()%3 + heroes_number;
					
						//Free the allocated space of the last encountered monsters
						if (battle_box != NULL) {
							for (j= 0; j < this->monsters_number ; j++) {
								delete battle_box[j];
							}	
						}
						delete battle_box;
						
						battle_box= new Monster* [how_many];
						monsters_number= how_many;
						for (i= 0; i < how_many ; i++) {
							j= rand()%10; 
							if (this->is_in_selected_jeys(j)) {
								i--;
								continue;
							}
							this->add_in_selected_jeys(j);
							j= rand()%3;
							if (j == 0) {
								battle_box[i]= new Dragon(this->n.get_monster_name(), lvl, initial_hp*lvl);	
							}
							else if (j == 1) {
								battle_box[i]= new Exoskeleton(this->n.get_monster_name(), lvl, initial_hp*lvl);
							}
							else {
								battle_box[i]= new Spirit(this->n.get_monster_name(), lvl, initial_hp*lvl);
							}
							
						}
						this->print();
						return "b";
					}
					else { //no battle
						this->print();
						return "c";
					}
				}
			}
			else { //non-accessible
				box[x+1][y]->be_discovered();
				this->print();
				return "n";
			}
		}
		else { 
			cout << "you can't go any lower than that!" << endl;
			return "e";
		}
		
	}
	else if (direction == "right") {
		if (y != dimension_y-1) {
			if (box[x][y+1]->get_type() != "non-accessible") {
				y++;
				box[x][y]->be_discovered();
				if (box[x][y]->get_type() == "market") {
					this->market_box= box[x][y]->get_market();
					// cout << "Look, there is a market over there!" << endl;
					this->print();
					return "m";
				}
				else { //common
					i= rand()%100;
					if (i < 50) { // battle
						lvl= heroes[0]->get_level() + (rand()%3);
						how_many= rand()%3 + heroes_number;
					
						//Free the allocated space of the last encountered monsters
						if (battle_box != NULL) {
							for (j= 0; j < this->monsters_number ; j++) {
								delete battle_box[j];
							}	
						}
						delete battle_box;
						
						battle_box= new Monster* [how_many];
						monsters_number= how_many;
						for (i= 0; i < how_many ; i++) {
							j= rand()%10; 
							if (this->is_in_selected_jeys(j)) {
								i--;
								continue;
							}
							this->add_in_selected_jeys(j);
							j= rand()%3;
							if (j == 0) {
								battle_box[i]= new Dragon(this->n.get_monster_name(), lvl, initial_hp*lvl);	
							}
							else if (j == 1) {
								battle_box[i]= new Exoskeleton(this->n.get_monster_name(), lvl, initial_hp*lvl);
							}
							else {
								battle_box[i]= new Spirit(this->n.get_monster_name(), lvl, initial_hp*lvl);
							}
							
						}
						this->print();
						return "b";
					}
					else { //no battle
						this->print();
						return "c";
					}
				}
			}
			else { // non-accessible
				box[x][y+1]->be_discovered();
				this->print();
				return "n";
			}
		}
		else {
			cout << "Sorry, you can't go right!" << endl;
			return "e";
		}
		
	}
	else if (direction == "left" ) {
		if (y != 0) {
			if (box[x][y-1]->get_type() != "non-accessible") {
				y--;
				box[x][y]->be_discovered();
				if (box[x][y]->get_type() == "market") {
					this->market_box= box[x][y]->get_market();
					// cout << "Look, there is a market over there!" << endl;
					this->print();
					return "m";
				}
				else { //common
					i= rand()%100;
					if (i < 50) { // battle
						lvl= heroes[0]->get_level() + (rand()%3);
						how_many= rand()%3 + heroes_number;
					
						//Free the allocated space of the last encountered monsters
						if (battle_box != NULL) {
							for (j= 0; j < this->monsters_number ; j++) {
								delete battle_box[j];
							}	
						}
						delete battle_box;
						
						battle_box= new Monster* [how_many];
						monsters_number= how_many;
						for (i= 0; i < how_many ; i++) {
							j= rand()%10; 
							if (this->is_in_selected_jeys(j)) {
								i--;
								continue;
							}
							this->add_in_selected_jeys(j);
							j= rand()%3;
							if (j == 0) {
								battle_box[i]= new Dragon(this->n.get_monster_name(), lvl, initial_hp*lvl);	
							}
							else if (j == 1) {
								battle_box[i]= new Exoskeleton(this->n.get_monster_name(), lvl, initial_hp*lvl);
							}
							else {
								battle_box[i]= new Spirit(this->n.get_monster_name(), lvl, initial_hp*lvl);
							}
							
						}
						this->print();
						return "b";
					}
					else { //no battle
						this->print();
						return "c";
					}
				}
			}
			else {// non-accessible
				box[x][y-1]->be_discovered();
				this->print();
				return "n";
			}
		}
		else {
			cout << "Sorry, you can't go left!" << endl;
			return "e";
		}
		
	}
	else {
		cout << "ERROR wrong direction" << endl;
		return "e";
	}
}

void Grid::reveal_map() {					//This function  makes all the boxes of the Grid visible, whether they've been visited before or not
	int i,j;
	for (i=0 ; i < dimension_x ; i++) {
		for (j=0; j < dimension_y ; j++) {
			box[i][j]->be_discovered();
		}
	}
	this->print();
	cout << "" << endl;

}

void Grid::round_info()const{
	int i;
	cout << "" << endl; 
	for(i=0; i < monsters_number; i++){				//for every monster
		if (battle_box[i]->get_alive()) {			//that has not passed out
			cout << battle_box[i]->get_name() << "'s hp: " << battle_box[i]->get_health() << endl;  //print its hp
		}
	}
	for(i=0 ; i < heroes_number ; i++) {  			//for every hero
		if (heroes[i]->get_alive()) {				//who has not passed out
			cout << heroes[i]->get_name() << "'s hp: " << heroes[i]->get_health() << "  and mana: " << heroes[i]->get_mana() << endl; //print his hp and mana
		}
	}
	cout << "" << endl; 							//print a blank line
	
}


//----------------- end of Grid ------------//
