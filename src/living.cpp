#include "living.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//----------- Living ------------//

Living::Living(string nam , int lvl , int hp){						//constructor of living is called with arguments of level , health and random names from array of names
	
	this->name = nam;
	this->level = lvl;
	this->health = hp;
	this->alive = 1;
	this->static_health = hp;
	
}

void Living::set_name(string nam){					//setter and getter functions
	this->name = nam;
	
}

void Living::set_level(int lvl){
	
	this->level = lvl;
	
}

void Living::set_health(int hp){
	
	this->health = hp;
	
}

void Living::set_static_health(int i){
	
	this->static_health = i;
}

void Living::set_alive(bool a){
	
	this->alive = a;
	
}

string Living::get_name(){
	
	return this->name;
	
}

int Living::get_level(){
	
	return this->level;
	
}

int Living::get_health(){
	
	return this->health;
	
}

int Living::get_static_health(){
	
	return this->static_health;
}

bool Living::get_alive(){
	
	return this->alive;
	
}


Living::~Living(){								//destructor , does nothing no dynamically allocated memory
	
}


//----------- end of Living -----//

//---------- Hero ---------------//

Hero::Hero(string nam, int lvl,int hp) : Living(nam,lvl,hp){			//constructor of hero calls constructor of superclass living with arguments oh health level and random name
	
	this->experience = 0;					//starting experience is 0
	this->experience_cap = 50;				//experience cap is 50 --> 50 experience for 1st level up
	this->mana = 50;						//starting mana is 50 for all heroes
	this->static_mana = 50;					//static mana is equal to mana and won't change to restore mana after battle
	this->money = 150;						//starting money is 150
	this->armor = NULL;						//armor is set to NULL and both hands
	hands[0]= NULL;
    hands[1]= NULL;

    for (int i= 0 ; i < 20 ; i++) {			//inventory is set to NULL

        this->inventory[i]= NULL;
        this->used_spells[i]= "None";
        this->used_weapons[i]= "None";
        this->used_armors[i]= "None";
        
    }

    this->weapons_used= 0;
    this->armors_used= 0;
    this->potions_used= 0;
    this->spells_used= 0;
    this->monsters_killed= 0;
    this->money_spent= 0;
    this->total_health_lost= 0;
    
    this->potion_strength_boost = 0;		//potion boosts are 0
    this->potion_dexterity_boost = 0;
    this->potion_agillity_boost = 0;
    this->potion_rounds = 0;
}

void Hero::set_mana(int i){					//setter and getter functions
	
	this->mana = i;
	
}

void Hero::set_static_mana(int i){
	
	this->static_mana = i;
}

void Hero::set_strength(int i){
	
	this->strength = i;
	
}

void Hero::set_dexterity(int i){
	
	this->dexterity = i;
	
}

void Hero::set_agillity(int i){
	
	this->agillity = i;
	
}

void Hero::set_money(int i){
	
	this->money = i;
	
}

void Hero::set_experience(int i){
	
	this->experience = i;
	
}

void Hero::set_experience_cap(int i){
	
	this->experience_cap = i;
}

void Hero::set_potion_strength_boost(int i){
	
	this->potion_strength_boost = i;
	
}

void Hero::set_potion_dexterity_boost(int i){
	
	this->potion_dexterity_boost = i;
	
}

void Hero::set_potion_agillity_boost(int i){
	
	this->potion_agillity_boost = i;
	
}

void Hero::set_potion_rounds(int i){
	
	this->potion_rounds = i;
	
}

void Hero::set_armor(Armor* armr){
	
	this->armor = armr;
	
	
}

void Hero::set_weapon(Weapon* weapn){
	
	this->hands[0] = weapn;
	
}

void Hero::set_default_inventory(Weapon* w1, Weapon* w2, Armor* a1, Armor* a2, Spell* s1, Potion* p1){
	inventory[0]= w1;
	hands[0]= w1;
	inventory[1]= w2;
	inventory[2]= a1;
	armor= a1;
	inventory[3]= a2;
	inventory[4]= s1;
	inventory[5]= p1;
}

int Hero::get_mana(){
	
	return this->mana;
	
}

int Hero::get_static_mana(){
	
	return this->static_mana;
	
}

int Hero::get_strength(){
	
	return this->strength;
	
}

int Hero::get_dexterity(){
	
	return this->dexterity;
	
}

int Hero::get_agillity(){
	
	return this->agillity;
	
}

int Hero::get_money(){
	
	return this->money;
	
}

int Hero::get_experience(){
	
	return this->experience;
	
}

int Hero::get_experience_cap(){
	
	return this->experience_cap;
}

int Hero::get_potion_strength_boost(){
	
	return this->potion_strength_boost;
	
}

int Hero::get_potion_dexterity_boost(){
	
	return this->potion_dexterity_boost;
	
}

int Hero::get_potion_agillity_boost(){
	
	return this->potion_agillity_boost;
	
}

int Hero::get_potion_rounds(){
	
	return this->potion_rounds;
	
}

void Hero::get_damaged(int damage){
	
	this->set_health(this->get_health() - damage);
	
}

Armor* Hero::get_armor(){
	
	return this->armor;
	
}

Weapon* Hero::get_weapon(int i){
	
	if(i == 0 && this->hands[0] != NULL){
		
		return this->hands[0];
		
	}
	
	else if(i == 1 && this->hands[1] != NULL){
		
		return this->hands[1];
		
	}
	
	else{
		
		return NULL;
		
	}

}

void Hero::use(Potion* potion){							//function to use potion from inventory
	
	int s,d,a,r;
	
	if(potion->get_min_level() > this->get_level()){	//checks if hero has not reached the level required to use potion
		
		
		cout<<"You can't use this Potion "<<this->get_name()<<", yet it has "<<potion->get_min_level()<<" minimum level "<<endl;
		return;
	}
	
	s = potion->get_strength_boost();
	d = potion->get_dexterity_boost();
	a = potion->get_agillity_boost();
	r = potion->get_rounds();
	
	this->set_potion_strength_boost(s);
	this->set_potion_dexterity_boost(d);
	this->set_potion_agillity_boost(a);
	this->set_potion_rounds(r);
	
	
	for(int i = 0;i < 20;i++){							//makes inventory slot where potion was saved NULL
		
		if(this->inventory[i] != NULL && this->inventory[i]->get_name() == potion->get_name() && this->inventory[i]->get_min_level() == potion->get_min_level()){
			
			this->inventory[i] = NULL;
			
		}
		
	}
	
}	


void Hero::attack(Monster& monster, Spell& spell) {
	
	
	int damage ; // The damage that the attack will cause to the monster
	int random_number; 
	
	if(monster.get_health() == 0 || monster.get_alive() == 0){
		
		cout<<"Monster : "<<monster.get_name()<<" is already dead you missed your attack!"<<endl;
	}
	
	//The hero must have a certain level to use a spell
	if (spell.get_min_level() > this->get_level()) {
		
		cout << this->get_name() << " can't use the " << spell.get_name() << " spell yet." << endl;
		cout << "(The hero's level must be advanced first)" << endl;
		return;
		
	}
	
	//The hero must have a certain amount of magical power to use a spell
	if (this->get_mana() < spell.get_mana()) {
		
		cout << this->get_name() << " can't use the " << spell.get_name() << " spell yet." << endl;
		cout << "(The hero's magical power is not enough)" << endl;
		return;
		
	}
		
	random_number = rand() % 100;
	
	//If the monster, by chance, avoided the attack
	//If the monster did not avoid the attack
	//Compute the damage that this spell will cause, that depends on hero's dexterity
	//Equals min_damage + (dexterity/2) (dexterity's range:0-100) 
	//Respects the rule that damage lies between min_damage and max_damage, as max_damage= min_damage+50
	//The computation below is more generic (in case the difference of min_damage and max_damage change)
	if (this->get_alive()) { //If hero has not passed out
		if (random_number < (monster.get_dodge() - monster.get_dodge_reduction())) {
			
			this->mana -= spell.get_mana();
			
			cout << monster.get_name() << " avoided " << this->get_name() << "'s attack with the "															
			     << spell.get_name() << " spell!" << endl; 
			     
			} 
			
			else { 	
																							
			damage = spell.get_min_damage() - monster.get_defense() + monster.get_defense_reduction() + ((spell.get_max_damage() - spell.get_min_damage()) / 100.0 * (this->dexterity + this->potion_dexterity_boost)) / 1;
			 
		  	//Hurt the monster
			monster.get_damaged(damage);
			
			//Apply the spells magic powers on the monster
			
			spell.to_be_used_against(monster);
			
			//Reduce the magical power needed by the hero in order to use the spell
			
			this->mana -= spell.get_mana();
			
			//Print a message to inform the player for the success of the attack
			
			cout << this->get_name() << " attacked " << monster.get_name() << " with "
			     << spell.get_name() << " spell, causing " << damage << " damage!" << endl;
			     
			//Check if the monster passed out
			
			if (monster.get_health() <= 0) {
				
				monster.set_alive(false);
				cout << "Monster " << monster.get_name() << " passed out!" << endl; 
				
			}
		}
		
		//Statistics
		if (spells_used < 20) {
			
			if (!this->is_in_used_spells(spell)) {
				
				this->put_in_used_spells(spell);
				spells_used++;
				
			}
		}
	}
}

void Hero::attack(Monster& monster , Weapon& weapon) {
	
	int damage; 						// The damage that the attack will cause to the monster
	int random_number;
	
	random_number = rand() % 100;
	
		
	if (this->get_alive()) { //If the hero has not passed out
	
		//If the monster, by chance, avoided the attack	
		if (random_number < (monster.get_dodge() - monster.get_dodge_reduction())) {
			
			cout << monster.get_name() << " avoided " << this->get_name() << "'s attack with the "
			     << weapon.get_name() << " !" << endl; 
			     
		}
		
		else { 																		//If the monster did not avoid the attack
																					//Compute the damage that this weapon will cause, that depends on hero's strength
		  	damage = weapon.get_damage() + this->strength + this->potion_strength_boost - monster.get_defense() + monster.get_defense_reduction(); 
		  	
		  	//Hurt the monster
		  	
			if(damage <= 0){
				
				cout<<"Hero "<<this->get_name()<<" did not inflict damage to the monster "<<monster.get_name()<<endl;
				return;
				
			}
			
			monster.get_damaged(damage);
			
			//Update hero's stats
			//Print a message to inform the player for the success of the attack
			
			cout << this->get_name() << " attacked " << monster.get_name() << " with "
			     << weapon.get_name() << ", causing " << damage << " damage!" << endl;
			     
			//Check if the monster passed out
			
			if (monster.get_health() <= 0) {
				
				monster.set_alive(false);
				cout << "Monster " << monster.get_name() << " passed out!" << endl; 
				
			}
		}
	
	
		//Statistics
		if (weapons_used < 20) {
			
			if (!this->is_in_used_weapons(weapon)) {
				
				this->put_in_used_weapons(weapon);
				weapons_used++;
				
			}
		}	
	}
}

void Hero::check_inventory(){			//function to print all items in player's inventory , weapons held in hand and armor equiped
	
	cout << "------------------------------ INVENTORY ------------------------------" << endl;
	cout<<"Printing inventory of Hero with name : "<<this->get_name()<<endl;
	
	for(int i = 0;i < 20;i++){
		
		if(this->inventory[i] != NULL){
			
			cout<<i<<") "<<this->inventory[i]->get_name()<<endl;
			
		}
		
	}
	
	if(this->hands[0] != NULL){
		
		cout<<"Weapon held in right hand is : "<<this->hands[0]->get_name()<<endl;
		
	}
	
	if(this->hands[1] != NULL){
		
		cout<<"Weapon held in left hand is : "<<this->hands[1]->get_name()<<endl;
		
	}
	
	if(this->armor != NULL){
		
		cout<<"Armor equiped is : "<<this->armor->get_name()<<endl;
		
	}
}

void Hero::buy(Item* item) {			//function buys an item from the market and adds it to player's inventory
	
 	int i;
 	
 	for (i=0; i < 20 ; i++) {
 		if (inventory[i] == NULL) {						//checks inventory , finds an empty slot and adds the item bought there
 			inventory[i] = item;
 			this->set_money(money-inventory[i]->get_price());			//reduces player's money
 			cout<<"You have successfully bought the item : "<<inventory[i]->get_name()<<endl;
 			return;
		 }
	 }
	 cout << "The hero's inventory doesn't have enough space!" << endl;
}

void Hero::sell(Item& item){							//function sells an item from player's inventory
	
	for(int i = 0;i < 20;i++){
		
		if(item.get_name() == this->inventory[i]->get_name()){	//finds the item in player's inventory and makes the slot empty			
			
			int k = this->inventory[i]->get_price() / 2;
			this->inventory[i]= NULL;
			this->set_money(this->get_money() + k);				//adds money to the player
			cout<<"Item with name : "<<item.get_name()<<" has been sold to the Market "<<endl;
			return;
			
		}
	}
	
	cout<<"Item with name : "<<item.get_name()<<" is not in the Inventory and cannot be sold "<<endl;
}

void Hero::equip(Weapon* weapon , int hand){						//function equips a weapon to player's hand/hands
	
	//cout<<"If you don't have space in your inventory weapons that are unequiped will be tossed !"<<endl;

	for(int i = 0;i < 20;i++){									//finds the item in player's inventory
		
		if(weapon->get_name() == this->inventory[i]->get_name()){
			
			if(weapon->get_two_hands() == 1) {
				hands[0]= weapon;
				hands[1]= weapon;
				return;
			}	
			else {
				if (hands[hand-1]->get_two_hands() == false) {
					this->hands[hand - 1] = weapon;
					return;	
				}
				else {
					this->hands[0]= NULL;
					this->hands[1]= NULL;
					this->hands[hand - 1] = weapon;
					return;	
				}
				
			}
			
		}
	}			
	cout<<"Weapon was not found in your inventory and can't be equiped!"<<endl;
}

void Hero::equip(Armor* arm){									//functions equips armor from player's inventory 
	
	//cout<<"If you don't have space in your inventory weapons that are unequiped will be tossed !"<<endl;

	for(int i = 0;i < 20;i++){									//finds armor in player's inventory
		
		if(armor->get_name() == this->inventory[i]->get_name()){
			cout << this->get_name() << " wears a new armor (" << arm->get_name() << ")"<< endl;
			this->armor = arm;
			return;
		}	
	}
	cout<<"Armor was not found in your inventory and can't be equiped!"<<endl;
	 
	
}

void Hero::restore(){											//restores health and mana of hero after battle
	
	this->set_health(this->get_static_health());
	this->set_static_mana(this->get_mana());
	this->set_alive(true);
	
}

bool Hero::is_in_used_spells(Spell& spell) {
	
	int i;
	
	for (i= 0; i < 20 ; i ++) {
		
		if (used_spells[i] == spell.get_name()) {
			
			return true;
			
		}
	}
	
	return false;
	
}

void Hero::put_in_used_spells(Spell& spell) {
	
	used_spells[spells_used]= spell.get_name();
	
}

bool Hero::is_in_used_weapons(Weapon& weapon) {
	
	int i;
	
	for (i= 0; i < 20 ; i ++) {
		
		if (used_weapons[i] == weapon.get_name()) {
			
			return true;
			
		}
	}
	
	return false;
	
}

void Hero::put_in_used_weapons(Weapon& weapon) {
	
	used_weapons[weapons_used]= weapon.get_name();
	
}

bool Hero::is_in_used_armors(Armor& arm) {
	
	int i;
	
	for (i= 0; i < 20 ; i ++) {
		
		if (used_armors[i] == arm.get_name()) {
			
			return true;
			
		}
	}
	
	return false;
	
}

void Hero::put_in_used_armors(Armor& arm) {
	
	used_armors[armors_used]= arm.get_name();
	
}

Item* Hero::search_item(string nam , int lvl){				//function to help us developers finds item with name = nam and level/minimum level = lvl in player's inventory/hands/armor else returns NULL
	
	for(int i = 0;i < 20;i++){
		
		if(this->inventory[i] != NULL && this->inventory[i]->get_name() == nam && this->inventory[i]->get_min_level() == lvl){
		
		
			return this->inventory[i];
		}
		
	}
	
	if(this->hands[0] != NULL && this->hands[0]->get_name() == nam && this->hands[0]->get_min_level() == lvl){
		
		return this->hands[0];
		
	}
	
	else if(this->hands[1] != NULL  && this->hands[1]->get_name() == nam && this->hands[1]->get_min_level() == lvl){
		
		return this->hands[1];
		
	}
	
	else if(this->armor != NULL && this->armor->get_name() == nam && this->armor->get_min_level() == lvl){
		
		return this->armor;
		
	}
	
	return NULL;
}

Hero::~Hero(){		//destructor , does nothing no dynamically allocated memory
	
}

//------- end of Hero ----------//

//---------- Sorcerer ----------//

Sorcerer::Sorcerer(string nam,int lvl,int hp) : Hero(nam,lvl,hp){							//Constructor of class Sorcerer takes arguments nam (name of Sorcerer) , level and health
	
	this->set_strength(1);						//Sorcerer starts with stronger dexterity and agillity
	this->set_agillity(2);
	this->set_dexterity(2);
	
}

void Sorcerer::info() {							//info prints all stats of hero sorcerer name, attributes , money ,experience , health and mana
	
	cout << "------------------------------ SORCERER ------------------------------" << endl;			
	cout << "This hero is a SORCERER" << endl;
	cout << "Sorcerers excel in dexterity and agility.\n"
	     << "They are spell experts and also have a good\n"
	     << "chance to avoid a monster's attack. They are\n"
	     << "weak in using weapons\n" << endl;
	cout << "Name : " << this->get_name() << endl;
	cout << "Strength : " << this->get_strength()+this->get_potion_strength_boost() << endl;
	cout << "Dexterity : " << this->get_dexterity()+this->get_potion_dexterity_boost() << endl;
	cout << "Agility : " << this->get_agillity()+this->get_potion_agillity_boost() << endl;
	cout << "Level : " << this->get_level() << endl;	
	cout << "Money : " << this->get_money() << endl;	
	cout << "Experience : " << this->get_experience() << endl;		
	cout << "------------------------------ ---- ------------------------------" << endl;
	
}

void Sorcerer::levelup() {						//level up adds experience to hero and if experience >= experience cap hero level ups and gets a boost on all attributes , health and mana
	
	if(this->get_level() >= 50){
		
		cout<<"You must have loved the game !!"<<endl;
		cout<<"Congratulations you have achieved maximum level on : "<<this->get_name()<<endl;
		cout<<"Unfortunately you can no longer level up!"<<endl;
		return;
	}
	
	this->set_experience(this->get_experience() + 25);
	
	if(this->get_experience() >= this->get_experience_cap()){
		
		this->set_strength(this->get_strength() + 1);				//Sorcerer is stronger on dexterity , agility(2 points added) and weaker on stregth(1 point added)
		this->set_dexterity(this->get_dexterity() + 2);
		this->set_agillity(this->get_agillity() + 2);
		this->set_health(this->get_health() + 60);					//Sorcerer gets lesser health but more mana
		this->set_mana(this->get_mana() + 40);
		this->set_static_health(this->get_health());
		this->set_static_mana(this->get_mana());
		this->set_level(this->get_level() + 1);
		
		cout<<"Congratulations you have achieved level : "<<this->get_level()<<endl;
		cout<<"Points have been allocated to your stats!"<<endl;
		
		this->set_experience_cap(this->get_experience_cap() + (this->get_level() * 15));			//experince cap gets larger
	}
	
	else{
		
		cout<<"You have "<<this->get_experience()<<" / "<<this->get_experience_cap()<<" to level up!"<<endl;
		
	}

}


//----- end of Sorcerer -------//

//--------- Warrior -----------//

Warrior::Warrior(string nam,int lvl,int hp) : Hero(nam,lvl,hp){	//Constructor of class Warrior takes arguments nam (name of Warrior) , level and health
	
	this->set_strength(2);										//Warrior starts with stronger strength and agillity
	this->set_agillity(2);
	this->set_dexterity(1);
	
}

void Warrior::info() {						//info prints all stats of hero warrior name, attributes , money ,experience , health and mana
	
	cout << "------------------------------ WARRIOR ------------------------------" << endl;
	cout << "This hero is a WARRIOR" << endl;
	cout << "Warriors excel in strength and agility.\n"
	     << "They are effective in weapon attacks. They\n"
	     << "also have a good chance to avoid a monster's\n"
	     << "attack. They are, however,poor in performing\n"
		 << "magical attacks." << endl;
	cout << "Name : " << this->get_name() << endl;
	cout << "Strength : " << this->get_strength()+this->get_potion_strength_boost() << endl;
	cout << "Dexterity : " << this->get_dexterity()+this->get_potion_dexterity_boost() << endl;
	cout << "Agillity : " << this->get_agillity()+this->get_potion_agillity_boost() << endl;
	cout << "Level : " << this->get_level() << endl;	
	cout << "Money : " << this->get_money() << endl;	
	cout << "Experience : " << this->get_experience() << endl;		
	cout << "------------------------------ ---- ------------------------------" << endl;
	
}

void Warrior::levelup() {				//level up adds experience to hero and if experience >= experience cap hero level ups and gets a boost on all attributes , health and mana
	
	if(this->get_level() >= 50){
		
		cout<<"You must have loved the game !!"<<endl;
		cout<<"Congratulations you have achieved maximum level on : "<<this->get_name()<<endl;
		cout<<"Unfortunately you can no longer level up!"<<endl;
		return;
	}
	
	this->set_experience(this->get_experience() + 25);
	
	if(this->get_experience() >= this->get_experience_cap()){
		
		this->set_strength(this->get_strength() + 2);						//Warrior is stronger on strength and agility(2 points added) but weaker on dexterity(1 point added)
		this->set_dexterity(this->get_dexterity() + 1);
		this->set_agillity(this->get_agillity() + 2);
		this->set_health(this->get_health() + 120);							//Warrior gets more health but less mana
		this->set_mana(this->get_mana() + 10);
		this->set_static_health(this->get_health());
		this->set_static_mana(this->get_mana());
		this->set_level(this->get_level() + 1);
		
		cout<<"Congratulations you have achieved level : "<<this->get_level()<<endl;
		cout<<"Points have been allocated to your stats!"<<endl;
		
		this->set_experience_cap(this->get_experience_cap() + (this->get_level() * 15));				//experince cap gets larger
	}
	
	else{
		
		cout<<"You have "<<this->get_experience()<<" / "<<this->get_experience_cap()<<" to level up!"<<endl;
		
	}

}


//----- end of Warrior -------//


//--------- Paladin ----------//

Paladin::Paladin(string nam, int lvl, int hp) : Hero(nam,lvl,hp){				//Constructor of class Paladin takes arguments nam (name of Paladin) , level and health
	
	this->set_strength(2);						//Paladin starts with stronger strength and dexterity
	this->set_dexterity(2);
	this->set_agillity(1);
	
}

void Paladin::info() {							//info prints all stats of hero paladin name, attributes , money ,experience , health and mana			
	
	cout << "------------------------------ PALADIN ------------------------------" << endl;
	cout << "This hero is a PALADIN" << endl;
	cout << "Paladins excel in strength and dexterity.\n"
	     << "They are the preferred units when the player\n"
	     << "wants to cause the maximum damage to a monster\n"
	     << "in any weapon or spell attack. They are, however,\n"
		 << "poor in agility." << endl;
	cout << "Name : " << this->get_name() << endl;
	cout << "Strength : " << this->get_strength()+this->get_potion_strength_boost() << endl;
	cout << "Dexterity : " << this->get_dexterity()+this->get_potion_dexterity_boost() << endl;
	cout << "Agility : " << this->get_agillity()+this->get_potion_agillity_boost() << endl;
	cout << "Level : " << this->get_level() << endl;	
	cout << "Money : " << this->get_money() << endl;	
	cout << "Experience : " << this->get_experience() << endl;		
	cout << "------------------------------ ---- ------------------------------" << endl;
	
}

void Paladin::levelup() {						//level up adds experience to hero and if experience >= experience cap hero level ups and gets a boost on all attributes , health and mana
	
	if(this->get_level() >= 50){
		
		cout<<"You must have loved the game !!"<<endl;
		cout<<"Congratulations you have achieved maximum level on : "<<this->get_name()<<endl;
		cout<<"Unfortunately you can no longer level up!"<<endl;
		return;
	}
	
	this->set_experience(this->get_experience() + 25);
	
	if(this->get_experience() >= this->get_experience_cap()){
		
		this->set_strength(this->get_strength() + 2);						//Paladin is stronger on dexterity and strength(2 points added) but weaker on agility(1 point added)
		this->set_dexterity(this->get_dexterity() + 2);
		this->set_agillity(this->get_agillity() + 1);
		this->set_health(this->get_health() + 80);							//Paladin is in the middle he is both good with spells and attacks so he gets more health than a sorcerer but less mana and vice versa in comparison with warrior
		this->set_mana(this->get_mana() + 20);
		this->set_static_health(this->get_health());
		this->set_static_mana(this->get_mana());
		this->set_level(this->get_level() + 1);
		
		cout<<"Congratulations you have achieved level : "<<this->get_level()<<endl;
		cout<<"Points have been allocated to your stats!"<<endl;
		
		this->set_experience_cap(this->get_experience_cap() + (this->get_level() * 15));
	}
	
	else{
		
		cout<<"You have "<<this->get_experience()<<" / "<<this->get_experience_cap()<<" to level up!"<<endl;
		
	}

}


//------ end of Paladin ------//


//----------- Monster --------//

Monster::Monster(string nam,int lvl,int hp) : Living(nam,lvl,hp){				//class Monster is an abstract class calls Constructor of superclass Living with arguments name, level , health
	this->dodge_reduction = 0;
	this->dodge_reduction_rounds = 0;
	this->defense_reduction = 0;
	this->defense_reduction_rounds = 0;
	
}

void Monster::set_min_damage(int i){					//setter and getter functions
	
	this->min_damage = i;
	
}

void Monster::set_max_damage(int i){
	
	this->max_damage = i;
	
}

void Monster::set_defense(int i){
	
	this->defense = i;
	
}

void Monster::set_dodge(int i){
	
	this->dodge = i;
	
}

void Monster::set_dodge_reduction(int i){
	
	this->dodge_reduction = i;
	
}

void Monster::set_dodge_reduction_rounds(int i){
	
	this->dodge_reduction_rounds = i;
	
}

void Monster::set_defense_reduction(int i){
	
	this->defense_reduction = i;
	
}

void Monster::set_defense_reduction_rounds(int i){
	
	this->defense_reduction_rounds;
	
}

void Monster::set_attack_reduction(int i){
	
	this->attack_reduction;
	
}

void Monster::set_attack_reduction_rounds(int i){
	
	this->attack_reduction_rounds = i;
	
}

int Monster::get_min_damage(){
	
	return this->min_damage;
	
}

int Monster::get_max_damage(){
	
	return this->max_damage;
	
}

int Monster::get_defense(){
	
	return this->defense;
	
}

int Monster::get_dodge(){
	
	return this->dodge;
	
}

int Monster::get_dodge_reduction() {
	
    return dodge_reduction;
    
}

int Monster::get_dodge_reduction_rounds() {
	
    return dodge_reduction_rounds;
    
}

int Monster::get_defense_reduction() {
	
    return defense_reduction;
    
}

int Monster::get_defense_reduction_rounds() {
	
    return defense_reduction_rounds;
    
}

int Monster::get_attack_reduction() {
	
    return attack_reduction;
    
}

int Monster::get_attack_reduction_rounds() {
	
    return attack_reduction_rounds;
    
}

int Monster::get_damaged(int damage){
	
	this->set_health(this->get_health() - damage);
	
}

void Monster::attack(Hero& hero){								//function for monster to attack hero
	
	int damage; 						
	int random_number;
	
	random_number = rand() % 100;
	
	if(random_number < (hero.get_agillity() + hero.get_potion_agillity_boost() / 2)){					//checks with random number if hero dodges the attack
		
		cout << hero.get_name() << " avoided " << this->get_name() << "'s attack!"<<endl; 
		
	}
	
	else{														//damage from monster to hero is based on damage from monster - damage reduction from armor
		
		Armor* armor = hero.get_armor();
		
		damage = this->get_min_damage() + (rand() % 50 + 1) - armor->get_damage_reduction();
		
		hero.get_damaged(damage);	
		
		cout << this->get_name() << " attacked " << hero.get_name() << ", causing " << damage << " damage!" << endl;
			
	}
	
	if (hero.get_health() <= 0) {								//checks if hero passed out
			
			hero.set_alive(false);
			cout << "Hero with name : " << hero.get_name() << " passed out!" << endl; 
			
	}
}


Monster::~Monster(){											//destructor , does nothing no dynamically alocated memory
	
}


//------ end of Monster -----//


//--------- Dragon ---------//

Dragon::Dragon(string nam, int lvl, int hp)  					//Dragon class is a type of monster that calls Constructor of superclass Monster
	:Monster(nam, lvl, hp)										//Dragon is stronger in damage and weaker in defense
{
	this->set_min_damage (20 + (rand() % 20 + 1) * lvl);
	this->set_max_damage  (this->get_min_damage() + 50);
	this->set_defense (5 + ((rand() % 5 + 1) * lvl));
	this->set_dodge((int)rand() % 10 + 1 + lvl/4); 
}

void Dragon::info(){											//info prints all stats of Monster Dragon , damage ,health
	cout << "------------------------------ DRAGON ------------------------------" << endl;
	cout<<"This is a dragon "<<this->get_name()<< "and is your enemy randomly appearing in unexplored blocks "<<endl;
	cout<<"It's damage has a range of 50 (like all heroes) with min damage : "<<this->get_min_damage()<<" and max damage : "<<this->get_max_damage()<<endl;
	cout<<"It has health : "<<this->get_health()<<" , and dodge : "<<this->get_dodge()<<" and defense : "<<this->get_defense()<<endl;
	
	if(this->get_defense_reduction() > 0 || this->get_dodge_reduction() > 0){
		
		cout<<"Stats have been reduced by a spell , defense reduction : "<<this->get_defense_reduction()<<" and dodge reduction : "<<this->get_dodge_reduction()<<endl;
		
	}

	
	cout << "------------------------------ ---- ------------------------------" << endl;	
}


//------ end of Dragon -----//

//-------- Exoskeleton -----//

Exoskeleton::Exoskeleton(string nam, int lvl, int hp) 			//Exoskeleton class is a type of monster that calls Constructor of superclass Monster
	: Monster(nam, lvl, hp)										//Exoskeleton is stronger in defense and  weaker in dodge
{
	this->set_min_damage (10 + (rand() % 10 + 1) * lvl);
	this->set_max_damage ( this->get_min_damage() + 50);
	this->set_defense ( 10 + ((rand() % 5 + 1) * lvl));
	this->set_dodge ( rand() % 10 + 1 + lvl/4); 
}

void Exoskeleton::info(){										//info prints all stats of Exoskeleton , health , level , name and damage
	cout << "------------------------------ EXOSKELETON ------------------------------" << endl;
	cout<<"This is an exoskeleton "<<this->get_name()<< "and is your enemy randomly appearing in unexplored blocks "<<endl;
	cout<<"It's damage has a range of 50 (like all heroes) with min damage : "<<this->get_min_damage()<<" and max damage : "<<this->get_max_damage()<<endl;
	cout<<"It has health : "<<this->get_health()<<" , and dodge : "<<this->get_dodge()<<" and defense : "<<this->get_defense()<<endl;
	
	if(this->get_defense_reduction() > 0 || this->get_dodge_reduction() > 0){
		
		cout<<"Stats have been reduced by a spell , defense reduction : "<<this->get_defense_reduction()<<" and dodge reduction : "<<this->get_dodge_reduction()<<endl;
		
	}
}

//----- end of Exoskeleton -//

//---------- Spirit --------//

Spirit::Spirit(string nam, int lvl, int hp) 					//Spirit is a type of Monster that calls Constructor of superclass Monster
	: Monster(nam, lvl, hp)										//Spirit is stronger in dodge but weaker in attack
{
	this->set_min_damage ( 5 + (rand() % 10 + 1) * lvl);
	this->set_max_damage ( this->get_min_damage() + 50);
	this->set_defense ( 5 + ((rand() % 5 + 1) * lvl));
	this->set_dodge ( 3 + rand() % 10 + 1 + lvl/4); 
}

void Spirit::info(){											//info prints all stats of Spirit , health , level , name and damage
	cout << "------------------------------ Spirit ------------------------------" << endl;
	cout<<"This is a spirit "<<this->get_name()<< "and is your enemy randomly appearing in unexplored blocks "<<endl;
	cout<<"It's damage has a range of 50 (like all heroes) with min damage : "<<this->get_min_damage()<<" and max damage : "<<this->get_max_damage()<<endl;
	cout<<"It has health : "<<this->get_health()<<" , and dodge : "<<this->get_dodge()<<" and defense : "<<this->get_defense()<<endl;
	
	if(this->get_defense_reduction() > 0 || this->get_dodge_reduction() > 0){
		
		cout<<"Stats have been reduced by a spell , defense reduction : "<<this->get_defense_reduction()<<" and dodge reduction : "<<this->get_dodge_reduction()<<endl;
		
	}
}

//------ end of Spirit -----//

