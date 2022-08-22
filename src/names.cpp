#include "names.h"


void help(){			//Prints a manual
	
	cout << "------------------------------ MANUAL --------------------------------------------------" << endl;
	
	cout <<"help/manual prints manual for all functions player can use"<<endl;
	cout <<"map/displaymap/printmap prints entire grid"<<endl;
	cout <<"info then item/hero prints information for hero or item"<<endl;
	cout <<"equip then armor/weapon equips a weapon to player's(chosen by player) or a new armor for player to wear"<<endl;
	cout <<"inventory prints all items inside hero's inventory , weapons held in item and armor"<<endl;
	cout <<"up/down/left/right moves player to directions on grid"<<endl;
	cout <<"info then monster name to get stats of a monster you are fighting"<<endl;
	cout <<"attack then weapon/spell to attack a monster"<<endl;
	cout <<"use then potion name to use a potion from your inventory"<<endl;
	cout <<"buy then name of item , hero buy an item from the market"<<endl;
	cout <<"sell then item name , hero sells an item to the market"<<endl;
	cout <<"show then (potions,spells,weapons,armors) prints all potions/spells/weapons/armor in market"<<endl;
	cout <<"buyable prints all items in market that the hero can buy"<<endl;
	
	cout << "------------------------------ ---- -----------------------------------------------" <<endl<<endl;
	
}
string Names::get_weapon_name(){
	
	int i = rand()%100;
	
	return this->weapon_names[i]; 
	
}

string Names::get_potion_name(){
	
	int i = rand()%70;
	
	return this->potion_names[i];
	
}

string Names::get_armor_name(){
	
	int i = rand()%80;
	
	return this->armor_names[i];
	
}

string Names::get_spell_name(){
	
	int i = rand()%91;
	
	return this->spell_names[i];
	
}

string Names::get_hero_name(){
	
	int i = rand()%10;
	
	return this->hero_names[i];
	
}

string Names::get_monster_name(){
	
	int i = rand()%91;
	
	return this->monster_names[i];
	
}



