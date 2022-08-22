#ifndef LIVING_H
#define LIVING_H
#include "items.h"
#include <string>
using namespace std;

//forward declaration of item classes
class Item;
class Weapon;
class Armor;
class Potion;
class Spell;
//living.h
//Includes the class Living and all its subclasses

class Living {
	
	private :										//data member for all living (hero,monster) are (name,level,health,alive,static health)
		
		string name;
		int level;
		int health;
		bool alive;
		int static_health;							//static_health is only used to restore health of hero after a battle
		
	public :
		
		Living(string nam , int lvl , int hp);		//constructor is called with random name from array of names , level of living and health
		
		void set_name(string nam);					//setter and getter functions for alla data members
		void set_level(int lvl);
		void set_health(int hp);
		void set_static_health(int i);
		void set_alive(bool a);
		
		string get_name();
		int get_level();
		int get_health();
		int get_static_health();
		bool get_alive();
		
		virtual void info() = 0;					//info gives stats and description of living and is virtual , because living is an abstract class
		
		~Living();									//destructor
		
};

class Monster;

class Hero : public Living {						//class hero is an abstract class that inherits class living
	
	private :
		
		int mana;									//data memebrs of class hero
		int static_mana;
		int strength;
		int dexterity;
		int agillity;
		int money;
		int experience;
		int experience_cap;							//experience cap is increased each level the hero gets and lelvel of hero increases when experience >= experience
		Weapon* hands[2];							//hero has 2 hands to equip weapons
		Armor* armor;
		Item* inventory[20];						//inventory of hero has 20 slots
	
		int potion_strength_boost;					//all boosts from potions used are kept here
		int potion_dexterity_boost;
		int potion_agillity_boost;
		int potion_rounds;
		
		string used_weapons[20];
		string used_spells[20];
		string used_armors[20];	
		int weapons_used;
		int armors_used;
		int potions_used;
		int spells_used;
		int monsters_killed;
		int money_spent;
		int total_health_lost;
		
		
	public : 

		Hero(string nam , int lvl , int hp);		//Constructor of hero is called with random name from an array of names
		
		
		void set_mana(int i);						//setters and getters for all data members
		void set_static_mana(int i);
		void set_strength(int i);
		void set_dexterity(int i);
		void set_agillity(int i);
		void set_money(int i);
		void set_experience(int i);
		void set_experience_cap(int i);
		void set_potion_strength_boost(int i);
		void set_potion_dexterity_boost(int i);
		void set_potion_agillity_boost(int i);
		void set_potion_rounds(int i);
		void set_armor(Armor* armr);
		void set_weapon(Weapon* weapn);
		void set_default_inventory(Weapon* w1, Weapon* w2, Armor* a1, Armor* A2, Spell* s1, Potion* p1);
		
		int get_mana();
		int get_static_mana();
		int get_strength();
		int get_dexterity();
		int get_agillity();
		int get_money();
		int get_experience();
		int get_experience_cap();
		int get_potion_strength_boost();
		int get_potion_dexterity_boost();
		int get_potion_agillity_boost();
		int get_potion_rounds();
		Armor* get_armor();
		Weapon* get_weapon(int i);
		
		void attack(Monster& monster,Weapon& weapon);			//function attack is used from hero to attack a monster with a weapon
		void attack(Monster& monster,Spell& spell);				//function attack is used from hero to attack monster with spell(from inventory)
		void check_inventory();									//function prints the inventory of hero
		void buy( Item* item);					//function buys item given from the market and adds on a empty(NULL) inventory slot
		void sell(Item& item);									//funnction sells an item from hero's inventory
		void stats(); 
		void equip(Armor* armor);								//function equips an armor from hero's inventory
		void equip(Weapon* weapon , int i);						//function equips a weapon from hero's inventory to hero's hand(0 or 1)
		void use(Potion* potion);								//function uses a potion from hero's inventory
		void get_damaged(int damage);							//reduces health of hero after a monster's attack
		void restore();											//restores health and mana of hero after a battle
		
		bool is_in_used_spells(Spell& spell);
		void put_in_used_spells(Spell& spell);
		bool is_in_used_weapons(Weapon& weapon);
		void put_in_used_weapons(Weapon& weapon); 
		bool is_in_used_armors(Armor& arm);
		void put_in_used_armors(Armor& arm);
		Item* search_item(string nam , int lvl);
		
		virtual void info() = 0;								//hero is an abstract class and info and level up are virtual functions
		virtual void levelup() = 0;
		
		~Hero();
};

class Sorcerer : public Hero {									//Sorcerer is a type of hero inherits class hero
	
	public :
		
		Sorcerer(string nam,int lvl,int hp);
		void info();
	    void levelup();											//level up is used to give attributes to hero that has leveled up
	    
};

class Warrior : public Hero {									//Warrior is a type of hero inherits class hero
	
	public :
		
		Warrior(string nam,int lvl,int hp);
		void info();
	    void levelup();											//level up is used to give attributes to hero that has leveled up
	    
};

class Paladin : public Hero {									//Paladin is a type of hero inherits class hero	
	
	public :
		
		Paladin(string nam,int lvl,int hp);
		void info();
	    void levelup();											//level up is used to give attributes to hero that has leveled up
	    
};

class Monster : public Living{									//class monsters inherits class living
	
	private :													//data members of class monster
		
		int min_damage;
		int max_damage;
		int defense;
		int dodge;
		int dodge_reduction;
		int dodge_reduction_rounds;
		int defense_reduction;
		int defense_reduction_rounds;
		int attack_reduction;
		int attack_reduction_rounds;
	
	public :
		
		Monster(string nam,int lvl,int hp);						//Constructor is called with random name from array of names , level of monsters and health
		 
		void set_min_damage(int i);								//setters and getters for all data members	
		void set_max_damage(int i);
		void set_defense(int i);
		void set_dodge(int i);
		void set_dodge_reduction(int i);
		void set_dodge_reduction_rounds(int i);
		void set_defense_reduction(int i);
		void set_defense_reduction_rounds(int i);
		void set_attack_reduction(int i);
		void set_attack_reduction_rounds(int i);
		
		int get_min_damage();
		int get_max_damage();
		int get_defense();
		int get_dodge();
		int get_dodge_reduction();
		int get_dodge_reduction_rounds();
		int get_defense_reduction();
		int get_defense_reduction_rounds();
		int get_attack_reduction();
		int get_attack_reduction_rounds();
		int get_damaged(int damage);
		
		void attack(Hero& hero);							//function is used for monster to attack hero
		virtual void info()=0;								//info is a virtual function of abstract class monster
		
		~Monster();											//Destructor
};

class Dragon : public Monster{								//class dragon is a type of monster and inherits class monster
	public:
		Dragon(string nam, int lvl, int hp);				//Constructor of dragon is called with random name of array with names , level of dragon and health
		void info();										//info is used to print stats and description of monster dragon
};

class Exoskeleton : public Monster{							//class exoskeleton is a type of monster and inherits class monster
	public:
		Exoskeleton(string nam, int lvl, int hp);			//Constructor of exoskeleton is called with random name of array with names , level of exoskeleton and health
		void info();										//info is used to print stats and description of monster dragon
};

class Spirit : public Monster{								//class spirit is a type of monster and inherits class monster
	public:
		Spirit(string nam, int lvl, int hp);				//Constructor of spirit is called with random name of array with names , level of spirit and health
		void info();										//info is used to print stats and description of monster spirit									
};


#endif
