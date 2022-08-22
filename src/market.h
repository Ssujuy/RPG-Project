#ifndef MARKET_H
#define MARKET_H

#include "items.h"
#include "names.h"
using namespace std;
//market.h
//Includes the market class and the classes that build up the grid of the game

class Market {
private:
	Spell** spell_stock;									//array of spells in market
	Potion** potion_stock;									//array of potions in market
	Weapon** weapon_stock;									//array of weapons in market
	Armor** armor_stock;									//array of armors in market
	int jeys [5];
	bool is_in_selected_jeys(int j);
	void add_in_selected_jeys(int j);
	
public:

	Market(Potion**& pot_array, Spell**& spe_array, Weapon**& wea_array, Armor**& arm_array); //constructor of market takes arrays from all items as arguments
	~Market();
	void show_spells();										//prints small info of all spells available in the market
	void show_potions();									//prints small info of all potions in market
	void show_weapons();									//prints small info of all weapons in market
	void show_armors();										//prints small info of all armor in market
	void show_buyable(Hero* hero);							//prints small info of items the player can buy
	Item* get_item(string key);								//returns item with name key from market
	void item_to_be_sold(Item* item);
	
};

class Box {
private:
	string type;
	bool discovered;
	Market* market;
public:
	Box(Potion**& pot_array, Spell**& spe_array, Weapon**& wea_array, Armor**& arm_array);					//constructor of box takes arrays for all items to create market
	Box(string str, Potion**& pot_array, Spell**& spe_array, Weapon**& wea_array, Armor**& arm_array);
	~Box();
	Market* get_market()const;																				//returns market pointer
	bool has_been_discovered()const;
	void be_discovered();
	string get_type()const;
	void print(bool heroes_here)const;	
};

class Grid {
private: 												//this the map that player's are put into and can move around
	int dimension_x;									//x static axis number
	int dimension_y;									//y static axis number
	Box*** box;											//2D array of boxes pointer
	int x;
	int y;
	Hero** heroes;										//an array of pointers to heroes playing the game
	int heroes_number;									//number of heroes playing the game
	Market* market_box;									//pointer to market_box
	Monster** battle_box;								//array of pointers to monsters that heroes will battle
	string* monster_names;								//an array of string to the names of monsters
	int monsters_number;								//number of monsters
	int jeys [5];
	bool is_in_selected_jeys(int j);
	void add_in_selected_jeys(int j);
	Names n;
	
public:
	Grid(string** preset_grid, Hero**& heroes, int heroes_num, int dim_x, int dim_y, Potion**& pot_array, Spell**& spe_array, Weapon**& wea_array, 
	     Armor**& arm_array);																												//constructor of grid takes arrays for all items to create the market , number of heroes playing and array of heroes
	Grid(Hero**& heroes, int heroes_num, int dim_x, int dim_y, Potion**& pot_array, Spell**& spe_array, Weapon**& wea_array,
	     Armor**& arm_array);
	~Grid();
	void print() const;									//prints entire grid(map)
	string move(string direction);						//heroes move (up,down,left,right)
	Market* get_market_box() const;						//returns market in heroes position
	Monster** get_battle_box()const;					//returns monsters that heroes will battle
	void reveal_map();									//prints map
	int get_monsters_number()const;						//returns number of monsters
	void round_info()const;								//prints some information about the health of the heroes and the monsters after a round of fighting
};

#endif
