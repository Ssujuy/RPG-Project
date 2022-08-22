#include "items.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

//------------------ Item ---------------//

Item::Item (string nam, int pr, int lvl) : name(nam), price(pr), min_level(lvl){
	
}
Item::Item(string nam){														//Constructor
	
	this->name = nam;
	this->min_level = rand() % 50 + 1;										//Level of item is from 1-50
	this->price = 100 + ((rand() % this->get_min_level() + 1) * 2);			//price is from 100-200
	
}

void Item::set_name(string nam){					//setter and getter functions
	
	this->name = nam;
	
}

void Item::set_price(int i){
	
	this->price = i;
	
}

void Item::set_min_level(int i){
	
	this->min_level = i;
	
}

string Item::get_name(){
	
	return this->name;
	
}

int Item::get_price(){
	
	return this->price;
	
}

int Item::get_min_level(){
	
	return this->min_level;
	
}

Item::~Item(){						//destructor , does nothing no data members dynamically allocated
	
}


//------------ end of Item -------------//

//----------- Weapon -------------------//

Weapon::Weapon(string nam, int pr, int lvl, int dam, bool two) 
	: Item (nam, pr, lvl), damage(dam), two_hands(two)
{
	
}

Weapon::Weapon(string nam) : Item(nam){			//Constructor
	
	this->two_hands = rand() % 2;				//weapon is either held with 1 or 2 hands(0 , 1)
	
	if(this->get_two_hands() == 0){				//weapons held with both hands have slightly more damage
		
		this->damage = 20 + ((rand() % 10 + 1) * this->get_min_level());
		
	}
	
	else{
		
		this->damage = (int) (20 + ((rand() % 10 + 1) * this->get_min_level()) *1,5);
		
	}
}


void Weapon::set_damage(int i){					//setter and getter functions
	
	this->damage = i;
	
}

void Weapon::set_two_hands(bool i){
	
	this->two_hands = i;
	
}

int Weapon::get_damage(){
	
	return this->damage;
	
}

bool Weapon::get_two_hands(){
	
	return this->two_hands;
	
}

void Weapon::small_info() {						//small info prints name , damage , minimum level requiered , price and (1 or 2) hands required
	
	cout << this->get_name() << endl;
	cout << "Categorty: Weapon" << endl;
	cout << "Damage : " << this->get_damage() << endl;
	cout<<"Requires minimum level : "<<this->get_min_level()<<endl;
	
	if (two_hands == true) {
		
		cout << "Hands required: 2" << endl;
		
	}
	
	else {
		
		cout << "Hands required: 1" << endl;
		
	}
	cout << "Price: " << this->get_price() << endl;	
	
}

void Weapon::info(){							//info is a more detailed description of small info
	
	cout << "------------------------------ INFO ------------------------------" << endl;
	cout << "This item is a WEAPON" << endl;
	cout << "Name : " << this->get_name() << endl;
	cout << "Minimum level : " << this->get_min_level() << endl;
	cout << "Damage : " << this->get_damage() << endl;
	
	if (two_hands == true) {
		
		cout << "Hands required: 2" << endl;
		
	}
	
	else {
		
		cout << "Hands required: 1" << endl;
		
	}
	
	cout << "Price: " << this->get_price() << endl;	
	cout << "------------------------------ ---- ------------------------------" << endl;
	
}

Weapon::~Weapon(){						//destructor , does nothing no data members dynamically allocated
	
}


//------------ end of Weapon ----------//


//------------ Armor -----------------//

Armor::Armor(string nam, int pr, int lvl, int dam_r)
	: Item(nam, pr, lvl), damage_reduction(dam_r)
{

}

Armor::Armor(string nam) : Item(nam){					//constructor of armor takes a random name from array of names										
	
	this->damage_reduction = 1 + (this->get_min_level() + ((rand()%20 +1)) / 10);					//defense of armor is between 1 - 52
	
}

void Armor::set_damage_reduction(int i){				//setter and getter functions
	
	this->damage_reduction = i;
	
}

int Armor::get_damage_reduction(){
	
	return this->damage_reduction;
	
}

void Armor::small_info(){								//small info prints name , damage reductions ,  minimum level requiered , price and (1 or 2) hands required
	
	cout << "Name: " << this->get_name() << endl;
	cout << "Minimum level: " << this->get_min_level() << endl;
	cout << "Damage reduction: " << damage_reduction << endl;
	cout << "Price: " << this->get_price() << endl;	
	cout <<"Requires minimum level : "<<this->get_min_level()<<endl;
}

void Armor::info(){										//info is a more detailed description of small info
	
	cout << "------------------------------ ARMOR ------------------------------" << endl;
	cout << "This item is an ARMOR" << endl;
	cout << "Armors are used to protect the hero against a monster's attack.\n"
	     << "The armor decreases the amount of damage the hero will get\n" 
	     << "when (s)he is being attacked by a monster.\n" << endl;
	cout << "Name: " << this->get_name() << endl;
	cout << "Minimum level: " << this->get_min_level() << endl;
	cout << "Damage reduction: " << damage_reduction << endl;
	cout << "Price: " << this->get_price() << endl;	
	cout << "------------------------------ ---- ------------------------------" << endl;	
	
}

Armor::~Armor(){									//destructor , does nothing no dynamically allocated memory
	
}



//----------- end of Armor ----------//

//-------------- Potion ------------//

Potion::Potion(string nam, int pr, int lvl) : Item(nam, pr, lvl) {
	this->strength_boost =  1;
		this->dexterity_boost =  1;
		this->agillity_boost =  1;
		this->rounds =  3;	
}

Potion::Potion(string nam) : Item(nam){				//constructor of potion is called with a random name from an array of names

	this->rounds = rand() % 3 + 2;					//rounds that potion will last is between 1-3
	
	if(this->get_rounds() > 1){						//if rounds is 3 has smaller boosts between 1-5
		
		this->strength_boost = rand() % 5 + 1;
		this->dexterity_boost = rand() % 5 + 1;
		this->agillity_boost = rand() % 5 + 1;
		
	}
	
	else{										//else if rounds between 1-2 boost is higher between 1-10
		
		this->strength_boost = rand() % 10 + 1;
		this->dexterity_boost = rand() % 10 + 1;
		this->agillity_boost = rand() % 10 + 1;
		
	}
}

void Potion::set_strength_boost(int i){			//setter and getter functions
	
	this->strength_boost = i;
	
}

void Potion::set_dexterity_boost(int i){
	
	this->dexterity_boost = i;
	
}

void Potion::set_agillity_boost(int i){
	
	this->agillity_boost = i;
	
}

void Potion::set_rounds(int i){
	
	this->rounds = i;
	
}

int Potion::get_strength_boost(){
	
	return this->strength_boost;
	
}

int Potion::get_dexterity_boost(){
	
	return this->dexterity_boost;
	
}

int Potion::get_agillity_boost(){
	
	return this->agillity_boost;
	
}

int Potion::get_rounds(){
	
	return this->rounds;
	
}

void Potion::small_info() {										//small info prints all boosts potion gives and rounds
	
	cout << this->get_name() << endl;
	cout << "Categorty: Potion" << endl;
	cout << "Strength boost: " << this->get_strength_boost() << endl;
	cout << "Dexterity boost: " << this->get_dexterity_boost() << endl;
	cout << "Agility boost: " << this->get_agillity_boost() << endl;
	cout << "Duration (in rounds):  " << this->get_rounds() << endl;
	cout <<"Requires minimum level : "<<this->get_min_level()<<endl;
	cout << "Price: " << this->get_price() << " $" << endl;
	
}

void Potion::info(){											//info is a more detailed description of small info
	
	cout << "------------------------------ POTION ------------------------------" << endl;
	cout<<"This is a potion with name : "<<this->get_name()<<" ."<<endl;
	cout<<"Potions are used to temporarily increase the stats of your Hero"<<endl;
	cout<<"The effect will last for : "<<this->get_rounds()<<endl;
	cout<<"and the effect will be + : "<<this->get_strength_boost()<<" on strength , + "<<this->get_dexterity_boost()<<" on dexterity and + "<<this->get_agillity_boost()<<" on agillity!"<<endl;
	cout << "------------------------------ ---- ------------------------------" << endl;
	
}

Potion::~Potion(){												//destructor , does nothing no dynamically allocated memory
	
}

//----------- end of Potion -------//


//-------------- Spell -----------//

//The initial amounts of minimum damage and minimum magical energy
const int initial_damage = 40;
const int initial_mana = 20;

Spell::Spell(string nam, int pr, int lvl, int dam ,int man):Item(nam,pr, lvl), min_damage(dam), max_damage(dam+50), mana(man){
	
}

Spell::Spell(string nam) : Item(nam){ 					//Call the constructor of the superclass Item via initializer list

	this->min_damage = initial_damage + (rand() % 5 + 1) * this->get_min_level() ; // for initial_damage==10, the minimum damage range is 11-260
	this->max_damage = this->min_damage + 50;
	this->mana = initial_mana + (rand() % 5 + 1) * this->get_min_level();
	
} 

//Setters & Getters

void Spell::set_min_damage(int min) {
	
	this->min_damage= min;
	//max_damage= min + 50;
	
}

void Spell::set_max_damage(int max) {
	
	this->max_damage= max;
	//min_damage= max - 50;
	
}

void Spell::set_mana(int magic_energy) {
	
	this->mana= magic_energy;
	
}


int Spell::get_min_damage()const {
	
	return this->min_damage;
	
}

int Spell::get_max_damage()const {
	
	return this->max_damage;
	
}

int Spell::get_mana()const {	
	return this->mana;	
}

Spell::~Spell() {				//destructor , does nothing no dynamically allocated memory
	
}

//---------- end of Spell -------//

//----------- LightningSpell ----//

LightningSpell::LightningSpell(string na,int da, int ma, int l, int p) : Spell(na,da,ma,l,p) {
	this->attack_avoidance_reduction = (int) ( (rand() % 21 +5) * (this->get_min_level() / 50.0) ); // Range of reduction:  5-25% * fraction (minimum_level / 25) --> Range: 0-50%
	this->rounds = rand() % 5 + 1; 
	this->type = "LightningSpell";
}

LightningSpell::LightningSpell(string nam) : Spell(nam){ 				//Call the constructor of the superclass Spell

	this->attack_avoidance_reduction = (int) ( (rand() % 21 +5) * (this->get_min_level() / 50.0) ); // Range of reduction:  5-25% * fraction (minimum_level / 25) --> Range: 0-50%
	this->rounds = rand() % 5 + 1; 
	this->type = "LightningSpell";
}

void LightningSpell::set_attack_avoidance_reduction(int reduction) {			//setter and getter functions
	this->attack_avoidance_reduction= reduction;
	
}

void LightningSpell::set_rounds(int round) {
	
	this->rounds= round;
	
}


int LightningSpell::get_attack_avoidance_reduction() const {
	
	return this->attack_avoidance_reduction;
	
}

int LightningSpell::get_rounds() const {
	
	return this->rounds;
	
}


void LightningSpell::small_info(){								//small info prints damage , avoidance reduction(on monster) , minimum level and price
	
	cout << this->get_name() << endl;
	cout << "Categorty: Lighting Spell" << endl;
	cout << "Damage: " << this->get_min_damage() << " - " << this->get_max_damage() << endl;
	cout << "Attack avoidance chance reduction: " << this->get_attack_avoidance_reduction() << endl;
	cout << "Duration (in rounds):  " << this->get_rounds() << endl;
	cout <<"Requires minimum level : "<<this->get_min_level()<<endl;
	cout << "Requires " << this->get_mana() << " mana and " << this->get_price() << " $" << endl;
	
}

void LightningSpell::info() {									//info is a more detailed description of small info
	
	cout << "------------------------------ SPELL ------------------------------" << endl;
	cout << "This item is a SPELL" << endl;
	cout << "Category : LIGHTINGSPELL" << endl;
	cout << "Lightingspells decrease the possibility of a monster to avoid\n"
	     << "a hero's attack for a number of rounds. Like all kinds of spells\n" 
	     << "they require an amount of magical energy (mana) and the hero to\n"
	     << "reach a minimum level in order to get and use them\n" << endl;
	cout << "Name : " << this->get_name() << endl;
	cout << "Minimum Damage: " << this->get_min_damage() << endl;
	cout << "Minimum level : " << this->get_min_level() << endl;
	cout << "Mana requiered : " << this->get_mana() << endl;
	cout << "Attack avoidance reduction : " << this->attack_avoidance_reduction << endl;
	cout << "Rounds : " << this->rounds << endl;	
	cout << "------------------------------ ---- ------------------------------" << endl;
	
}

void LightningSpell::to_be_used_against(Monster& monster) {					//Implements only the special spell's attack (not the damage causing)
	
	monster.set_dodge_reduction(this->attack_avoidance_reduction);
	monster.set_dodge_reduction_rounds(this->rounds);
	
}

LightningSpell::~LightningSpell() {											//destructor , does nothing no dynamically allocated memory

}



// ---- end of LightningSpell ---//

//---------- IceSpell -----------//

IceSpell::IceSpell(string nam) : Spell(nam){					//Call the constructor of the superclass Spell 
					
	this->damage_reduction=(int) ( (rand() % 21 +5) * (this->get_min_level() / 50.0) ); 			// Range of reduction:  5-25% * fraction (minimum_level / 25) --> Range: 0-50%
	this->rounds= rand() % 5 + 1; 
	this->type = "IceSpell";
	
}

void IceSpell::set_damage_reduction(int dam_reduction) {			//setters and getter functions
	this->damage_reduction= dam_reduction;
	
}

void IceSpell::set_rounds(int round) {
	
	this->rounds= round;
	
}

int IceSpell::get_damage_reduction() const {
	
	return this->damage_reduction;
	
}

int IceSpell::get_rounds() const {
	
	return this->rounds;
	
}


void IceSpell::small_info(){						//small info prints damage , damage reduction + rounds(duration of reduction) , minimum level and price
	
	cout << this->get_name() << endl;
	cout << "Categorty: Ice Spell" << endl;
	cout << "Damage: " << this->get_min_damage() << " - " << this->get_max_damage() << endl;
	cout << "Damage reduction: " << this->get_damage_reduction() << endl;
	cout << "Duration (in rounds):  " << this->get_rounds() << endl;
	cout <<"Requires minimum level : "<<this->get_min_level()<<endl;
	cout << "Requires " << this->get_mana() << " mana and " << this->get_price() << " $" << endl;
	
}

void IceSpell::info() {								//info is a more detailed description of small info
	
	cout << "------------------------------ SPELL ------------------------------" << endl;
	cout << "This item is a SPELL" << endl;
	cout << "Category : ICESPELL" << endl;
	cout << "Icespells decrease the damage that a monster causes to a\n"
	     << "hero for a number of rounds. Like all kinds of spells they\n"
	     << "require an amount of magical energy (mana) and the hero to\n"
	     << "reach a minimum level in order to get and use them\n" << endl;
	cout << "Name : " << this->get_name() << endl;
	cout << "Minimum level : " << this->get_min_level() << endl;
	cout << "Mana requiered : " << this->get_mana() << endl;
	cout << "Damage reduction : " << this->damage_reduction << endl;
	cout << "Rounds : " << this->rounds << endl;	
	cout << "------------------------------ ---- ------------------------------" << endl;
	
}

//Implements only the special spell's attack (not the damage causing)
void IceSpell::to_be_used_against(Monster& monster) {
	
    monster.set_attack_reduction(this->damage_reduction);
    monster.set_attack_reduction_rounds(this->rounds);
    
}

IceSpell::~IceSpell() {						//destructor , does nothing no dynamically allocated memory
	
}


//-------- end of IceSpell ------//

//----------- FireSpell ---------//

FireSpell::FireSpell(string nam, int pr, int lvl , int dam, int man, int def_red, int r)
	: Spell(nam, pr, lvl, dam , man), defence_reduction(def_red), rounds(r), type("FireSpell")
{
		
}

FireSpell::FireSpell(string nam) : Spell(nam){ 								//Call the constructor of the superclass Spell via initializer list

	this->defence_reduction = (int) ( (rand() % 21 + 5) * (this->get_min_level() / 50.0) ); 				// Range of reduction:  5-25% * fraction (minimum_level / 25) --> Range: 0-50%
	this->rounds = rand() % 5 + 1;
	this->type = "FireSpell"; 
}

void FireSpell::set_defence_reduction(int dam_reduction) {					//setters and getter functions
	
	this->defence_reduction= dam_reduction;
	
}

void FireSpell::set_rounds(int round) {
	
	this->rounds = round;
	
}

int FireSpell::get_defence_reduction() const {
	
	return this->defence_reduction;
	
}

int FireSpell::get_rounds() const {
	
	return this->rounds;
	
}

void FireSpell::small_info() {								//small info prints damage , defense reduction , rounds(duration) , minimum level and mana required
	cout << this->get_name() << endl;
	cout << "Categorty: Fire Spell" << endl;
	cout << "Damage: " << this->get_min_damage() << " - " << this->get_max_damage() << endl;
	cout << "Defence reduction: " << this->get_defence_reduction() << endl;
	cout << "Duration (in rounds):  " << this->get_rounds() << endl;
	cout <<"Requires minimum level : "<<this->get_min_level()<<endl;
	cout << "Requires " << this->get_mana() << " mana and " << this->get_price() << " $" << endl;
}


void FireSpell::info() {									//info is a more detailed description of small info
	
	cout << "------------------------------ SPELL ------------------------------" << endl;
	cout << "This item is a SPELL" << endl;
	cout << "Category : FIRESPELL" << endl;
	cout << "Firespells decrease the defence of a monster against heros'\n"
	     << "attacks for a number of rounds. Like all kinds of spells they\n"
	     << "require an amount of magical energy (mana) and the hero to\n"
	     << "reach a minimum level in order to get and use them\n" << endl;
	cout << "Name : " << this->get_name() << endl;
	cout << "Minimum level : " << this->get_min_level() << endl;
	cout << "Mana requiered : " << this->get_mana() << endl;
	cout << "Defence reduction : " << defence_reduction << endl;
	cout << "Rounds : " << rounds << endl;	
	cout << "------------------------------ ---- ------------------------------" << endl;
	
}

//Implements only the special spell's attack (not the damage causing)
void FireSpell::to_be_used_against(Monster& monster) {
	
	monster.set_defense_reduction(this->defence_reduction);
	monster.set_defense_reduction_rounds(this->rounds);
	
}

FireSpell::~FireSpell() {							//destructor , does nothing no dynamically allocated memory
	
}


//------- end of FireSpell -----//

