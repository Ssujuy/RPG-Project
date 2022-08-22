#ifndef ITEMS_H
#define ITEMS_H

#include "living.h"
#include <string>

class Monster;

using namespace std;
//items.h
//Includes the item class and all of its subclasses

class Item{
	
	private :										//data members of all item(potions,spells,weapons,armor) are name , minimum level to use item and price to buy it
		
		string name;
		int price;  
		int min_level;
		
	public :
		
		Item (string nam, int pr, int lvl);
		Item(string nam); 							//Constructor takes random name from an array of names
	
		virtual void info() = 0;					//info gives stats and description of item and is virtual , because item is an abstract class
		
		void set_name(string nam);					//setters and getters for all data members
		void set_price(int i);
		void set_min_level(int i);
		
		string get_name();
		int get_price();
		int get_min_level();
		
		~Item();									//destructor

};

class Weapon : public Item{ 						//class weapon is an item and inherits abstract class item
	
	private :										//data members of weapon are damage and two_hands(if weapon is held with both hands two_hands = 1)
		
		int damage;
		bool two_hands;
		
	public : 
		
		Weapon(string nam, int pr, int lvl, int dam, bool two);
		Weapon(string nam); 						//Constructor is called with random name from an array of names
		
		void set_damage(int i);						//setters and getters for all data mambers
		void set_two_hands(bool i);
		
		int get_damage();
		bool get_two_hands();
		
		void small_info();							//small info is used to print stats and a small description of weapon
		
		void info();								//info gives stats and description of weapon and is defined here because weapon is not an abstract class
		
		~Weapon();
		
};

class Armor : public Item{							//class armor is an item and inherits abstract class item
	
	private :										//data member of armor is damage_reduction
		
		int damage_reduction;
		
	public :
		Armor(string nam, int pr, int lvl, int dam_r);
		Armor(string nam);							//Constructor is called with random name from an array of names
		
		void set_damage_reduction(int i);			//setter and getter
		
		int get_damage_reduction();
		
		void small_info();							//small info is used to print stats and a small description of armor
		
		void info();								//info gives stats and description of armor and is defined here because armor is not an abstract class
		
		~Armor();									//destructor
};

class Potion : public Item{							//class potion is an item and inherits abstract class item
	
	private :										//data members of potion
		
		int strength_boost;
		int dexterity_boost;
		int agillity_boost;
		int rounds;									//keeps rounds(duration) of potion
		
	public : 
		Potion(string nam, int pr, int lvl);
		Potion(string nam);							//Constructor of potion is called with random name from array of names
		
		void set_strength_boost(int i);				//setters and getters for all data members
		void set_dexterity_boost(int i);
		void set_agillity_boost(int i);
		void set_rounds(int i);
		
		int get_strength_boost();
		int get_dexterity_boost();
		int get_agillity_boost();
		int get_rounds();
		
		void small_info();							//small info is used to print stats and a small description of potion
		void info();								//info gives stats and description of armor and is defined here because armor is not an abstract class
		
		~Potion();									//destructor
};

class Spell : public Item{							//abstract class spell is an item and inherits abstract class item	
	
	private :										//data members of spell are min-max damage and mana(magic power of hero which is consumed by spell to use it)
		
		int min_damage;  
		int max_damage; 
		int mana; 
		
	public :
		Spell(string na, int pr, int lvl, int dam ,int man);
		Spell(string nam); 							//Constructor is called with random name from array of names
		
		void set_min_damage(int min);				//setters and getters
		void set_max_damage(int max);
		void set_mana(int magic_energy);

		
		int get_min_damage() const;
		int get_max_damage() const;
		int get_mana() const;
		
		virtual void small_info() = 0;				//info and small info  are virtual becaue spell is an abstract class
		virtual void info() = 0;
		virtual void to_be_used_against(Monster&) = 0;
		
		~Spell();									//destructor
};

class LightningSpell : public Spell {   			//lightning spell is a class which inherits spell

	private :
		
		int attack_avoidance_reduction ;  			//data members are attack_avoidance_reduction (to monster) type and rounds(duration of attack_avoidance_reduction)
		int rounds;
		string type;
		 
	public :
		LightningSpell(string na,int da, int ma, int l, int p);
		LightningSpell(string nam); 				//Constructor is called with random name from array of names
		
		void set_attack_avoidance_reduction(int reduction);		//setters and getters
		void set_rounds(int round);

		int get_attack_avoidance_reduction() const;
		int get_rounds() const;
		
		void small_info();							//small info is used to print stats and small description of lightning spell
		void info();
		void to_be_used_against(Monster& monster);	//to be used against adds the redution to the monster
		
		~LightningSpell();							//destructor
};

class IceSpell : public Spell {  					//Ice spell is a class which inherits spell
 
	private :
		
		int damage_reduction ;  					//data members of ice spell
		int rounds;
		string type; 
		 
	public :
		
		IceSpell(string nam); 						//Constructor is called with random name from array of names
		
		void set_damage_reduction(int dam_reduction);	//setters and getters
		void set_rounds(int round);
		
		int get_damage_reduction() const;
		int get_rounds() const;
		
		void small_info();							//small info is used to print stats and small description of ice spell
		void info();
		void to_be_used_against(Monster& monster);	//to be used against adds the redution to the monster
		
		~IceSpell();								//destructor
		
};


class FireSpell : public Spell {  
 
	private :
		
		int defence_reduction ;  
		int rounds;
		string type; 
		 
	public :
		
		FireSpell(string nam, int pr, int lvl , int dam, int man, int def_red, int r);
		FireSpell(string nam); 						//Constructor is called with random name from array of names
	
		void set_defence_reduction(int def_reduction);	//setters and getters
		void set_rounds(int round);
		
		int get_defence_reduction() const;
		int get_rounds() const;
		
		void small_info();							//small info is used to print stats and small description of lightning spell
		void info();
		void to_be_used_against(Monster& monster);	//to be used against adds the redution to the monster
		
		~FireSpell();								//destructor
		
};

#endif

