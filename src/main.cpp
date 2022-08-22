#include "names.h"
#include "items.h"
#include "living.h"
#include "market.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	
	srand(time(NULL));
	
	int nmb,i,j,k;									//initializing all variables that will be used in main
	string str1,str2,str3;
	Hero* h1 = NULL;
	Hero* h2 = NULL;
	Hero* h3 = NULL;
	Warrior* wp;
	Sorcerer* ss;
	Paladin* sp;
	
	Names names = Names();
	
	Warrior w = Warrior(names.get_hero_name(),1,200);			//3 heroes are created one of each type(Warrior,Paladin,Sorcerer)
	Sorcerer s = Sorcerer(names.get_hero_name() , 1 ,200);
	Paladin p = Paladin(names.get_hero_name() , 1 , 200);
	
	Weapon default2_weapon("NewbieCrossbow", 26, 1, 34, true) ;	
	Weapon default1_weapon = Weapon("NewbieSword", 30, 1, 40, false );			//3 default weapons are created , 1 for each hero with the same stats and name

	Armor default2_armor = Armor("NewbieShild", 22, 1, 8);
	Armor default1_armor = Armor("NewbieArmor", 30, 1, 10);			//3 default armors are created , 1 for each hero with the same stats and name
	
	Potion default_potion= Potion("NewbiPotion", 60, 1);
	FireSpell default_spell= FireSpell("NewbieSpell", 48, 1, 60, 20, 12, 3);
	
	w.set_default_inventory(&default1_weapon, &default2_weapon, &default1_armor, &default2_armor, &default_spell, &default_potion);
	s.set_default_inventory(&default1_weapon, &default2_weapon, &default1_armor, &default2_armor, &default_spell, &default_potion);
	p.set_default_inventory(&default1_weapon, &default2_weapon, &default1_armor, &default2_armor, &default_spell, &default_potion);
	
	Potion** pot_array= new Potion* [50];					//arrays of pointers for weapons,armors,potions and spells are created in main
	Spell** spe_array= new Spell* [60];
	Weapon** wea_array= new Weapon* [50];
	Armor** arm_array= new Armor* [50];
		
		
	for (i= 0 ; i <50 ; i++) {
		
		pot_array[i]= new Potion(names.get_potion_name());
		wea_array[i]= new Weapon (names.get_weapon_name());
		arm_array[i]= new Armor (names.get_armor_name());
		
	}
	
	for(int c = 0;c < 20;c++){
		
		spe_array[c] = new IceSpell(names.get_spell_name());
		
	}
	
	for(int c=20; c < 40;c++){
		
		spe_array[c] = new FireSpell(names.get_spell_name());
		
	}
	
	for(int c= 40; c <60; c++){
		
		spe_array[c] = new LightningSpell(names.get_spell_name());
		
	}
	
	
	//small introduction to the game
	
	cout<<"Welcome to our game " " a production by Apostolos Theodorou and Konstantinos Arvanitis "<<endl;
	cout<<"This is basically a simple RPG game created on C++"<<endl;
	cout<<"You start with an amount of characters of your choice and you can have any class of heroes you want"<<endl;
	cout<<"Classes of heroes are Warrior , Paladin and Sorcerer "<<endl;
	cout<<"The board or grid is the map where you can move around , explore , find and fight different monsters and buy items from the market"<<endl;
	cout<<"Your spawn square is a common square with no enemies or market "<<endl;
	cout<<"Your basic goal is to slay monsters with weapons and spells , explore the map , level up and have fun !"<<endl;
	cout<<"Your skills are strength (basically more damage with weapons) , dexterity (basically you do more damage with spells) and agillity (basically gives you a better chance of dodging an attack)"<<endl;
	cout<<"You can use Potions to enhance your skills different potions give you different attributes"<<endl;
	cout<<"Below are all the functions you can use to play the game and how to use them"<<endl<<endl;
	
	help();					//function help prints a manual for all functions a player can use
	
	cout<<"We are now ready to begin the game , we hope you enjoy!!!"<<endl;								//player chooses the number of heroes she/he will be playing with
	cout<<"Please select the number of heroes you'd like to play with (from 1 to 3)"<<endl;
	cin>>nmb;
	while (nmb != 1 && nmb != 2 && nmb != 3) {
		cout<<"Please select the number of heroes you'd like to play with (from 1 to 3)"<<endl;
		cin>>nmb;
	}
	
	if(nmb == 1){										//if checks for number given
		
		cout<<"Which character would you like to be?(options: Warrior , Sorcerer , Paladin)"<<endl;
		cin>>str1;
		
		while (str1 != "Warrior" && str1 != "warrior" && str1 != "WARRIOR" && str1 != "Paladin" && str1 != "paladin" && str1 != "PALADIN"
			   && str1 != "Sorcerer" && str1 != "sorcerer" && str1 != "SORCERER") 
		{
			cout<<"Which character would you like to be?(options: Warrior , Sorcerer , Paladin)"<<endl;			//player chooses which hero he will be
			cin>>str1;	   	
		}
		
		if(str1 == "Warrior" || str1 == "warrior" || str1 == "WARRIOR"  ){
			
			
			h1 = &w;
			cout<<"Name of Warrior is "<<h1->get_name()<<endl;
		}
		
		else if(str1 == "Sorcerer" ||  str1 == "sorcerer" || str1 == "SORCERER"){
			
			h1 = &s;
				cout<<"Name of Sorcerer is "<<h1->get_name()<<endl;
		}
		
		else if(str1 == "Paladin" || str1 == "paladin" || str1 != "PALADIN"){
			
			h1 = &p;
			cout<<"Name of Paladin is "<<h1->get_name()<<endl;
		}
		
		else{
			
			cout<<"Restart the game and give a correct class of heroes"<<endl;
			return 0;
			
		}
	}
	
	else if(nmb == 2){
		
		cout<<"Which characters would you like to be?(options: Warrior , Sorcerer , Paladin)"<<endl;			//player gives 2 typew of heroes to play with
		cin>>str1>>str2;
		
		while (str1 != "Warrior" && str1 != "warrior" && str1 != "WARRIOR" && str1 != "Paladin" && str1 != "paladin" && str1 != "PALADIN"
			   && str1 != "Sorcerer" && str1 != "sorcerer" && str1 != "SORCERER") 
		{
			cout<<"Which characters would you like to be?(options: Warrior , Sorcerer , Paladin)"<<endl;
			cin>>str1>>str2;	   	
		}
		while (str2 != "Warrior" && str2 != "warrior" && str2 != "WARRIOR" && str2 != "Paladin" && str2 != "paladin" && str2 != "PALADIN"
			   && str2 != "Sorcerer" && str2 != "sorcerer" && str2 != "SORCERER") 
		{
			cout<<"Which characters would you like to be?(options: Warrior , Sorcerer , Paladin)"<<endl;
			cin>>str1>>str2;	   	
		}
		
		if((str1 == "Warrior" && str2 == "Sorcerer") || (str1 == "Sorcerer" && str1 == "Warrior")){			//if checks which type of heroes player wants to play with , heroes are assigned to a pointer(h1,h2)
			 
			h1 = &w;
			h2 = &s;
			cout<<"Name of Warrior is "<<h1->get_name()<<endl;
			cout<<"Name of Sorcerer is "<<h2->get_name()<<endl;
		}
		
		else if((str1 == "Paladin" && str2 == "Sorcerer") || (str1 == "Sorcerer" && str2 == "Paladin")){
			
			h1 = &p;
			h2 = &s;
			cout<<"Name of Paladin is "<<h1->get_name()<<endl;
			cout<<"Name of Sorcerer is "<<h2->get_name()<<endl;
		}
		
		else if((str1 == "Warrior" && str2 == "Paladin") || (str1 == "Paladin" && str2 == "Warrior")){
			
			h1 = &w;
			h2 = &p;
			cout<<"Name of Warrior is "<<h1->get_name()<<endl;
			cout<<"Name of Paladin is "<<h2->get_name()<<endl;
		}
		
		else{
			
			cout<<"Restart the game and give a correct class of heroes"<<endl;
			return 0;
			
		}
	}
	
	else if(nmb == 3){				//player has chosen 3 heroes to play with , they are assigned to 3 pointers (h1, h2, h3)
		
		h1 = &w;
		h2 = &p;
		h3 = &s;
		cout<<"Name of Warrior is "<<h1->get_name()<<endl;
		cout<<"Name of Paladin is "<<h2->get_name()<<endl;
		cout<<"Name of Sorcerer is "<<h3->get_name()<<endl;
	}
	
	else{
				
		cout<<"Restart the game and give a correct number between 1 and 3"<<endl;
		return 0;
		
	}
	
	Hero** my_heros = new Hero*[nmb];
	my_heros[0] = h1;
	my_heros[1] = h2;
	my_heros[2] = h3;
	
	Grid grid(my_heros, nmb, 8, 6,  pot_array,  spe_array, wea_array, arm_array);			//grid is created passes arguments of an array of heros,items and number of heroes
	
	cout<<"The game is ready to start choose your move!! (up, down, right, left, info, equip, inventory, help, quit , map)"<<endl;			//game starts and player makes his move , str3 is the variable that saves it
	cin>>str3;
	
	while(str3 != "Quitgame" || str3 != "Endgame" || str3 != "quit" || str3 != "end" || str3 == "End" || str3 == "Quit"){					//while player doesn't quit the game
		
		if(str3 == "Quitgame" || str3 == "Endgame" || str3 == "quit" || str3 == "end" || str3 == "End" || str3 == "Quit"){					//if player pressed quit or end or endgame
														
			cout<<"Game is now exiting!"<<endl;			//game stops
			return 0;
							
		}
		
		if(str3 == "help" || str3 == "Help" || str3 == "Manual" || str3 == "manual"){			//if player typed help manual is printed
				
			help();
				
		}
		
		else if(str3 == "map" || str3 == "displaymap" || str3 == "printmap"){				//if player typed map/displaymap grid.print() function is called (grid gets printed)
			
			grid.print();
			
		}
		
		else if(str3 == "info"){					//if player typed info
			
			cout<<"Give type (hero/item)"<<endl;		//player types hero(print info of a hero) or item (print info of item in player's) inventory
			cin>>str3;
			
			if(str3 == "hero" || str3 == "Hero"){			
				
				cout<<"Give name of hero" <<endl;			//player gives name of hero
				cin>>str3;
				
				if(h1 != NULL && h1->get_name() == str3){		//if checks if name of pointer is same with name given and pointer is not NULL and use correct info
					
					h1->info();
					
				}
				
				else if(h2 != NULL && h2->get_name() == str3){
					
					h2->info();
					
				}
				
				else if(h3 != NULL && h3->get_name() == str3){
					
					h3->info();
					
				}
				
				else{
					
					cout<<"Maybe you gave a wrong hero name"<<endl;
					continue;
					
				}
			}
			
			else if(str3 == "item" || str3 == "Item"){
				
				cout<<"Give name of item"<<endl;			//player gives name of item and name of hero that has it
				cin>>str3;
				
				cout<<"Give name of hero"<<endl;
				cin>>str2;
				
				if(h1 != NULL && h1->get_name() == str2){			//checks if pointer h1 is not NULL and if name of hero is same as name given by player
					 
					 cout<<"Give level/minimum level of item"<<endl;			//player also gives minimum level of item to avoid problems with items that have the same name
					 cin>>j;
					 
					 Item* item = h1->search_item(str3,j);
					 
					 if(item == NULL){			//item was not found 
					 	
					 	cout<<"Item was not found in your inventory try again!"<<endl;
					 	
					 }
					 
					 else{						//item was found and info is called
					 	
					 	item->info();
					 	
					 }
				}
				
				else if(h2 != NULL && h2->get_name() == str2){				//checks if pointer h2 is not NULL and if name of hero is same as name given by player
					
					cout<<"Give level/minimum level of item"<<endl;				//player also gives minimum level of item to avoid problems with items that have the same name
					cin>>j;
					 
					Item* item = h2->search_item(str3,j);
					 
					if(item == NULL){					//item was not found 
					 	
					 	cout<<"Item was not found in your inventory try again!"<<endl;
					 	
					}
					 
					else{								//item was found and info is called
					 	
					 	item->info();
					 	
					}
				}
				
				else if(h3 != NULL && h3->get_name() == str2){				//checks if pointer h3 is not NULL and if name of hero is same as name given by player
					 
					cout<<"Give level/minimum level of item"<<endl;			//player also gives minimum level of item to avoid problems with items that have the same name
					cin>>j;
					 
					Item* item = h3->search_item(str3,j);
					 
					if(item == NULL){					//item was not found 
					 	
					 	cout<<"Item was not found in your inventory try again!"<<endl;
					 	
					}
					 
					else{								//item was found and info is called
					 	
						item->info();
					 	
					}
				}
			}
		}
		
		else if(str3 == "equip"){					//if is true when player types equip
			
			cout<<"Equip armor or weapon??"<<endl;			//asks if player wants to equip armor or weapon
			cin>>str3;
			
			if(str3 == "weapon" || str3 == "Weapon"){				//if player types weapon
				
				cout<<"Give weapon name"<<endl;				//player gives weapon name , hero name , hand 1 or 2 and minimum level of item to be equiped
				cin>>str3;
				cout<<"Give hero name "<<endl;
				cin>>str2;
				cout<<"Give 1 or 2 for which hand to hold the weapon with"<<endl;
				cin>>j;
				
				if(h1 != NULL && h1->get_name() == str2){
					
					cout<<"Give level/minimum level of item!"<<endl;
					cin>>k;
					
					Item* item = h1->search_item(str3,k);
					
					if(item == NULL){							//if item was not found
						
						cout<<"Item was not found in your inventory!"<<endl;
						
					}
					
					else{										//item was found hero::equip is called
						
						h1->equip((Weapon*)item,j);
						
					}
				}
				
				else if(h2 != NULL && h2->get_name() == str2){			//if checks if second player's name matches hero name that player gave
					
					
					cout<<"Give level/minimum level of item!"<<endl;		//player gives minimum level of item
					cin>>k;
					
					Item* item = h2->search_item(str3,k);					//search is called to find the item
					
					if(item == NULL){									//item was not found
						
						cout<<"Item was not found in your inventory!"<<endl;
						
					}
					
					else{							//item was found hero::equip is called
						
						h2->equip((Weapon*)item,j);
						
					}
					
				}
				
				if(h3 != NULL && h3->get_name() == str2){			//if checks if third player's name matches hero name that player gave
					
					
					cout<<"Give level/minimum level of item!"<<endl;
					cin>>k;
					
					Item* item = h3->search_item(str3,k);			//search is called to find item to equip
					
					if(item == NULL){			//item was not found
						
						cout<<"Item was not found in your inventory!"<<endl;
						
					}
					
					else{					//item was found hero::equip is called
						
						h3->equip((Weapon*)item,j);
						
					}
				}
			}
			
			else if(str3 == "Armor" || str3 == "armor"){			//same rules apply for armor except hero does not have to give right or left hand armor is wore by the player
				
				cout<<"Give armor name"<<endl;
				cin>>str3;
				cout<<"Give hero name "<<endl;
				cin>>str2;
				
				if(h1 != NULL && h1->get_name() == str2){
					
					
					cout<<"Give level/minimum level of item!"<<endl;
					cin>>k;
					
					Item* item = h1->search_item(str3,k);
					
					if(item == NULL){
						
						cout<<"Item was not found in your inventory!"<<endl;
						
					}
					
					else{
						
						h1->equip((Armor*)item);
						
					}
				}
				
				else if(h2 != NULL && h2->get_name() == str2){
					
					
					cout<<"Give level/minimum level of item!"<<endl;
					cin>>k;
					
					Item* item = h2->search_item(str3,k);
					
					if(item == NULL){
						
						cout<<"Item was not found in your inventory!"<<endl;
						
					}
					
					else{
						
						h2->equip((Armor*)item);
						
					}
					
				}
			
				if(h3 != NULL && h3->get_name() == str2){
					
					
					cout<<"Give level/minimum level of item!"<<endl;
					cin>>k;
					
					Item* item = h3->search_item(str3,k);
					
					if(item == NULL){
						
						cout<<"Item was not found in your inventory!"<<endl;
						
					}
					
					else{
						
						h3->equip((Armor*)item);
						
					}
					
				}
			}
		}
		
		else if(str3 == "inventory" || str3 == "Inventory"){			//if checks if player typed inventory
			
			cout<<"Give hero name"<<endl;			//player gives hero's name
			cin>>str3;
			
			if(h1 != NULL && h1->get_name() == str3){		//if and else if matches the name given with all heroes available(if h2 or h3 are NULL they are not available)
				
				h1->check_inventory();						//hero::inventory is called 
				
			}
			
			else if(h2 != NULL && h2->get_name() == str3){
				
				h2->check_inventory();
				
			}
			
			else if(h3 != NULL && h2->get_name() == str3){
				
				h3->check_inventory();
				
			}	
		}
		
		else if(str3 == "up" || str3 == "Up" || str3 == "Down" || str3 == "down" || str3 == "left" || str3 == "Left" || str3 == "right" || str3 == "Right"){			//players can move up/down/left/right
			
			if(str3 == "up" || str3 == "Up"){		//if checks which direction player typed and grid.move is called
				
				str3 = grid.move("up");
				
			}
			
			else if(str3 == "down" || str3 == "Down"){
				
				str3 = grid.move("down");
				
			}
			
			else if(str3 == "Left" || str3 == "left"){
				
				str3 = grid.move("left");
				
			}
			
			else if(str3 == "right" || str3 == "Right"){
				
				str3 = grid.move("right");
				
			}
			
		   		if(str3 == "b"){			//if grid.move returned players are in battle phase
				
				int rounds = 1;
				int h1r = 0,h2r = 0,h3r = 0;
				Monster** monsters = grid.get_battle_box();			//grid.get_battle_box returns all monsters players will fight
				int count_monsters = grid.get_monsters_number();	//get_monsters_number returns number of monsters to avoid any sigseg errors
				bool flag = 0;
				
				cout<<"Monsters have appeared prepare for battle"<<endl;
				cout<<"You are fighting these monsters!!"<<endl;
				
				for(int l = 0;l <= count_monsters - 1;l++){				//prints all monster names heroes will fight
					
					cout<<l + 1<<" )"<<monsters[l]->get_name() <<endl;
							
				}
				
				while(str3 != "Quitgame" || str3 != "Endgame" || str3 != "quit" || str3 != "end" || str3 != "End" || str3 != "Quit"){				//while stops if player wants to quit the game
					
					if(((h1 != NULL && h1->get_health() <= 0) && (h2 != NULL && h2->get_health() <= 0) && (h3 != NULL && h3->get_health() <= 0))){		//if checks how many heroes are playing 1,2 or 3 and if they are dead then calls restore for 1,2 or 3 heroes , heroes have lost the battle and lose half of thei money
						
						cout<<"Ufortunately heroes lost the battle and monsters have prevailed!"<<endl;
						cout<<"As a consiquence heroes lose half of their gold!!"<<endl;
						
						h1->restore();
						h2->restore();
						h3->restore();
						h1->set_money(h1->get_money() / 2);
						h2->set_money(h2->get_money() / 2);
						h3->set_money(h3->get_money() / 2);
						
						break;
						
					}
					else if(((h1 != NULL && h1->get_health() <= 0) && nmb == 2 && (h2 != NULL && h2->get_health() <= 0))){
						
						cout<<"Ufortunately heroes lost the battle and monsters have prevailed!"<<endl;
						cout<<"As a consiquence heroes lose half of their gold!!"<<endl;
						
						h1->restore();
						h2->restore();
						h1->set_money(h1->get_money() / 2);
						h2->set_money(h2->get_money() / 2);
						
						break;
						
					}
					
					else if(h1 != NULL && h1->get_health() <= 0 && nmb ==1){
						
						cout<<"Ufortunately heroes lost the battle and monsters have prevailed!"<<endl;
						cout<<"As a consiquence heroes lose half of their gold!!"<<endl;
						
						h1->restore();
						h1->set_money(h1->get_money() / 2);
						
						break;
						
					}
					
					for(int l = 0;l <= count_monsters - 1;l++){				//for checks health of monsters
						
						if(monsters[l]->get_health() > 0){
							
							flag = 0;
							break;							
						}

						flag = 1;

					}
					
					if(flag == 1){			//flag was true means that heroes have won the battle restore is called for 1,2 or 3 heroes and level up as well
						
						cout<<"Heroes have prevailed , you have looted all the monsters for gold!"<<endl;
						cout<<"Experience will be added to all players!"<<endl;
						
						if(h1 != NULL){
							
							h1->restore();
							h1->levelup();
							h1->set_money(h1->get_money() + 25 + (h1->get_level() * count_monsters));
						}
						
						if(h2 != NULL){
							
							h2->restore();
							h2->levelup();
							h2->set_money(h2->get_money() + 25 + (h2->get_level() * count_monsters));
						}
						
						if(h3 != NULL){
							
							h3->restore();
							h3->levelup();
							h3->set_money(h3->get_money() + 25 + (h3->get_level() * count_monsters));
						}
						
						break;
						
					}
					
					if(h1 != NULL && h1r < rounds && h1->get_alive()){			//it's first hero's turn , hero can type (info,help,equip) like before the battle
						
						cout<<"It's your turn : "<<h1->get_name()<<" choose your move "<<"(help, info, equip, use, attack, quit)"<<endl;
						cin>>str3;
						
						if(str3 == "help" || str3 == "Help" || str3 == "Manual" || str3 == "manual"){
						
							help();
							continue;
						
						}
						
						else if (str3== "Quitgame" || str3 == "Endgame" || str3 == "quit" || str3 == "end" || str3 == "End" || str3 == "Quit" ) {
							cout << "You have successfully quited the game"<<endl;
							return 0;
						}
												
						else if(str3 == "info"){
							
							cout<<"Give type (monster/hero/item)"<<endl;
							cin>>str3;
							
							if(str3 == "hero" || str3 == "Hero"){
								
								h1->info();
								continue;
								
							}
							
							else if(str3 == "item" || str3 == "Item"){
								
								cout<<"Give name of item"<<endl;
								cin>>str3;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>j;
								
								Item* item = h1->search_item(str3,j);
							 
								if(item == NULL){
									
									cout<<"Item was not found in your inventory"<<endl;
									continue;
									
								}
								
								else{
									
									item->info();
									continue;
									
								}
							}
							
							else if(str3 == "Monster" || str3 == "monster"){
								
								cout<<"Give monster name "<<endl;
								cin>>str3;
								int l;
									
								for(l = 0;l <= count_monsters - 1;l++){
										
									if(monsters[l]->get_name() == str3){
											
										break;
											
									}
								}
								
								monsters[l]->info();
								continue;
								
							}
						}
							
						else if(str3 == "equip"){
						
							cout<<"Equip armor or weapon??"<<endl;
							cin>>str3;
						
							if(str3 == "weapon" || str3 == "Weapon"){
							
								cout<<"Give weapon name"<<endl;
								cin>>str3;
								cout<<"Give 1 or 2 for which hand to hold the weapon with"<<endl;
								cin>>j;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>k;
								
								Item* item = h1->search_item(str3,k);
								
								if(item == NULL){
									
									cout<<"Item was not found in your inventory"<<endl;
									continue;
									
								}
								
								else{
									
									h1->equip((Weapon*)item,j);
									continue;
									
								}
								
							}
							
							else if(str3 == "armor" || str3 == "Armor"){
							
								cout<<"Give armor name"<<endl;
								cin>>str3;
								cout<<"Give level/minimum leve of item"<<endl;
								cin>>j;
								
								Item* item = h1->search_item(str3,j);
								
								if(item == NULL){
									
									cout<<"Item was not found in your inventory"<<endl;
									continue;
									
								}
								
								else{
									
									h1->equip((Armor*)item);
									continue;
									
								}
								
							}
						}
						
						else if(str3 == "use" || str3 == "Use"){			//if player typed use(potion)
							
							cout<<"Give Potion name"<<endl;					//player gives potion's name
							cin>>str3;
							cout<<"Give level/minimum leve of item"<<endl;		//level/minimum level of potion
							cin>>j;
							Item* item = h1->search_item(str3,j);
							
							if(item == NULL){			//potion was not found
								
								cout<<"Potion is not in player's inventory!"<<endl;
								continue;
								
							}
							
							else{				//potion was found and hero::use is called
								
								h1->use((Potion*)item);
								
							}
							
							h1r++;
							continue;
						}
						
						else if(str3 == "attack" || str3 == "Attack"){		//checks if player typed attack
							
							cout<<"Attack with Spell or Weapon?? (spell, weapon)"<<endl;				//checks if player wants to attack with weapon or spell
							cin>>str3;
							while (str3 != "Spell" && str3 != "spell" && str3 != "weapon" && str3 != "Weapon") {
								cout<<"Attack with Spell or Weapon?? (spell, weapon)"<<endl;
							cin>>str3;
							}
							cout<<"Give monster name (";
							for (int i=0 ; i < count_monsters ; i++) {			//prints all options player has to attack
								if (i != count_monsters-1) {
									if (monsters[i]->get_alive()) {
										cout << monsters[i]->get_name() << ", ";	
									}
								}
								else {
									if (monsters[i]->get_alive()) {
										cout << monsters[i]->get_name();	
									}
								}
							}
							cout << ")" << endl;
							cin>>str2;
							
							if(str3 == "Weapon" || str3 == "weapon"){			//if player typed weapon
								
								cout<<"Give 0 for left hand or 1 for right hand"<<endl;			//player gives which hand he wants to attack with
								cin>>j;
								Weapon* weapon = h1->get_weapon(j);
								
								if(weapon != NULL){
									
									int l;
									
									for(l = 0;l <= count_monsters - 1;l++){			//searches for monster that match the name given
										
										if(monsters[l]->get_name() == str2){
											
											break;
											
										}
									}
									
									if(monsters[l] != NULL && monsters[l]->get_name() == str2){		//if monster was found hero attacks
									
										h1->attack((*monsters[l]),(*weapon));
									
									}
									
									else{			//monster was not found
										
										cout<<"Monster name given was wrong!"<<endl;
										continue;
										
									}
									
								}
								
																
								else{			//prints a message if hand given was wrong
									
									cout<<"Maybe hand give was wrong (0 , 1) or weapon was not equiped!"<<endl;
									continue;
									
								}
								
								h1r++;
								continue;
							}
							
							else if(str3 == "Spell" || str3 == "spell"){				//checks if player wants to attack with spell
								
								cout<<"Give spell name"<<endl;							//player gives spell name spell level and monster name
								cin>>str3;
								cout<<"Give monster name"<<endl;
								cin>>str2;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>j;
								
								Item* item = h1->search_item(str3,j);					//search is called to find the spell
								
								if(item == NULL){			//item was not found
									
									cout<<"Spell was not found in your inventory!"<<endl;
									
								}
								
								else{				//item was found and for matches monster given with available monsters
									
									for(int a = 0;a <= count_monsters - 1;a++){
										
										if(monsters[a]->get_name() == str2 && monsters[a]->get_health() > 0){
											
											h1->attack(*(monsters[a]),*((Spell*)item));
											break;
											
										}
									}
								}
								
								h1r++;			//first hero has done his turn
								continue;
								
							}
							
							else{		//something went wrong hero must try his turn again
								
								cout<<"Something went wrong , try your move again!"<<endl;
								continue;
								
							}
						}
					}
					
					if(h2 != NULL && h2r < rounds  && h2->get_alive()){			//same rules apply for second hero
						
						cout<<"It's your turn : "<<h2->get_name()<<" choose your move "<<"(help, info, equip, use, attack, quit)"<<endl;
						cin>>str3;
						
						if(str3 == "help" || str3 == "Help" || str3 == "Manual" || str3 == "manual"){
						
							help();
							continue;
						
						}
						
						else if (str3== "Quitgame" || str3 == "Endgame" || str3 == "quit" || str3 == "end" || str3 == "End" || str3 == "Quit" ) {
							cout << "You have successfully quited the game"<<endl;
							return 0;
						}
						
						else if(str3 == "info"){
							
							cout<<"Give type (monster/hero/item)"<<endl;
							cin>>str3;
							
							if(str3 == "hero" || str3 == "Hero"){
								
								h2->info();
								continue;
								
							}
							
							else if(str3 == "item" || str3 == "Item"){
								
								cout<<"Give name of item"<<endl;
								cin>>str3;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>j;
								
								Item* item = h2->search_item(str3,j);
								
								if(item == NULL){
									
									cout<<"Item was not found in your inventory"<<endl;
									continue;
									
								}
								
								else{
									
									item->info();
									continue;
									
								}
							}
							
							else if(str3 == "Monster" || str3 == "monster"){
								
								cout<<"Give monster name "<<endl;
								cin>>str3;
								int l;
									
								for(l = 0;l <= count_monsters - 1;l++){
										
									if(monsters[l]->get_name() == str3){
											
										break;
											
									}
								}
								
								monsters[l]->info();
								continue;
							}
						}
							
						else if(str3 == "equip"){
					
							cout<<"Equip armor or weapon??"<<endl;
							cin>>str3;
					
							if(str3 == "weapon" || str3 == "Weapon"){
						
								cout<<"Give weapon name"<<endl;
								cin>>str3;
								cout<<"Give 1 or 2 for which hand to hold the weapon with"<<endl;
								cin>>j;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>k;
								
								Item* item = h2->search_item(str3,k);
								
								if(item == NULL){
									
									cout<<"Item was not found in your inventory"<<endl;
									continue;
									
								}
								
								else{
									
									h2->equip((Weapon*)item,j);
									continue;
									
								}
							}
						
							else if(str3 == "armor" || str3 == "Armor"){
						
								cout<<"Give armor name"<<endl;
								cin>>str3;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>j;
								
								Item* item = h2->search_item(str3,j);
								
								if(item == NULL){
									
									cout<<"Item was not found in your inventory!"<<endl;
									continue;
									
								}
								
								else{
									
									h2->equip((Armor*)item);
									continue;
									
								}
							}
						}
						
						else if(str3 == "use" || str3 == "Use"){
							
							cout<<"Give Potion name"<<endl;
							cin>>str3;
							cout<<"Give level/minimum level of item"<<endl;
							cin>>j;
							Item* item = h2->search_item(str3,j);
							
							if(item == NULL){
								
								cout<<"Item was not found in your inventory"<<endl;
								continue;
								
							}
							
							else{
								
								h2->use((Potion*)item);
								
							}
							
							h2r++;
							continue;
						}
						
						else if(str3 == "attack" || str3 == "Attack"){
							
							cout<<"Attack with Spell or Weapon?? (spell, weapon)"<<endl;
							cin>>str3;
							while (str3 != "Spell" && str3 != "spell" && str3 != "weapon" && str3 != "Weapon") {
								cout<<"Attack with Spell or Weapon?? (spell, weapon)"<<endl;
							cin>>str3;
							}
							cout<<"Give monster name (";
							for (int i=0 ; i < count_monsters ; i++) {
								if (i != count_monsters-1) {
									if (monsters[i]->get_alive()) {
										cout << monsters[i]->get_name() << ", ";
									}
								}
								else {
									if (monsters[i]->get_alive()) {
										cout << monsters[i]->get_name() ;
									}
								}
							}
							cout << ")" << endl;
							
							cout<<"Give monster name"<<endl;
							cin>>str2;
							
							if(str3 == "Weapon" || str3 == "weapon"){
								
								cout<<"Give 0 for left hand or 1 for right hand"<<endl;
								cin>>j;
								Weapon* weapon = h2->get_weapon(j);
								
								if(weapon != NULL){
									
									int l;
									
									for(l = 0;l <= count_monsters - 1;l++){
										
										if(monsters[l]->get_name() == str2){
											
											break;
											
										}
									}
									
									if(monsters[l] != NULL && monsters[l]->get_name() == str2){
									
										h2->attack((*monsters[l]),(*weapon));
									
									}
									
									else{
										
										cout<<"Monster name given was wrong!"<<endl;
										continue;
										
									}
								}
								
								else{
									
									cout<<"Maybe hand given was wrong (0 , 1) or weapon was not equiped!"<<endl;
									continue;
									
								}
								
								h2r++;
								continue;
							}
							
							else if(str3 == "Spell" || str3 == "spell"){
								
								cout<<"Give spell name"<<endl;
								cin>>str3;
								cout<<"Give monster name"<<endl;
								cin>>str2;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>j;
								
								Item* item = h2->search_item(str3,j);
								
								if(item == NULL){
									
									cout<<"Spell was not found in your inventory!"<<endl;
									
								}
								
								else{
									
									for(int a = 0;a <= count_monsters - 1;a++){
										
										if(monsters[a]->get_name() == str2 && monsters[a]->get_health() > 0){
											
											h2->attack((*monsters[a]),*((Spell*)item));
											
										}
									}
									
								}
									
								h2r++;
								continue;
									
							}
						}	
					}
					
					if(h3 != NULL && h3r < rounds && h3->get_alive()){			//same rules apply for third hero as described above
						
						cout<<"It's your turn : "<<h3->get_name()<<" choose your move "<<"(help, info, equip, use, attack, quit)"<<endl;
						cin>>str3;
						
						if(str3 == "help" || str3 == "Help" || str3 == "Manual" || str3 == "manual"){
						
							help();
							continue;
						
						}
						
						else if (str3== "Quitgame" || str3 == "Endgame" || str3 == "quit" || str3 == "end" || str3 == "End" || str3 == "Quit" ) {
							cout << "You have successfully quited the game"<<endl;
							return 0;
						}
						
						else if(str3 == "info"){
							
							cout<<"Give type (monster/hero/item)"<<endl;
							cin>>str3;
							
							if(str3 == "hero" || str3 == "Hero"){
								
								h3->info();
								continue;
								
							}
							
							else if(str3 == "item" || str3 == "Item"){
								
								cout<<"Give name of item"<<endl;
								cin>>str3;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>j;
								
								Item* item = h3->search_item(str3,j);
							 
							 	if(item == NULL){
							 		
							 		cout<<"Item was not found in your inventory!"<<endl;
							 		continue;
							 		
								 }
								 
								 else{
								 	
								 	item->info();
								 	continue;
								 	
								 }
							 
							}
							
							else if(str3 == "Monster" || str3 == "monster"){
								
								cout<<"Give monster name "<<endl;
								cin>>str3;
								int l;
									
								for(l = 0;l <= count_monsters - 1;l++){
										
									if(monsters[l]->get_name() == str3){
											
										break;
											
									}
								}
								
								monsters[l]->info();
								continue;
								
							}
						}
							
						else if(str3 == "equip"){
						
							cout<<"Equip armor or weapon??"<<endl;
							cin>>str3;
						
							if(str3 == "weapon" || str3 == "Weapon"){
							
								cout<<"Give weapon name"<<endl;
								cin>>str3;
								cout<<"Give 1 or 2 for which hand to hold the weapon with"<<endl;
								cin>>j;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>k;
								
								Item* item = h3->search_item(str3,k);
								
								if(item == NULL){
									
									cout<<"Item was not found in your inventory"<<endl;
									continue;
									
								}
								
								else{
																		
									h3->equip((Weapon*)item,j);
									continue;
									
								}
								
							}
							
							else if(str3 == "armor" || str3 == "Armor"){
							
								cout<<"Give armor name"<<endl;
								cin>>str3;
								cout<<"Give level/minimum level"<<endl;
								cin>>j;
								
								Item* item = h3->search_item(str3,j);
								
								if(item == NULL){
									
									cout<<"Item was not found in your inventory!"<<endl;
									continue;
									
								}
								
								else{
									
									h3->equip((Armor*)item);
									continue;
									
								}
							}
						}
						
						else if(str3 == "use" || str3 == "Use"){
							
							cout<<"Give Potion name"<<endl;
							cin>>str3;
							cout<<"Give level/minimum level of potion "<<endl;
							cin>>j;
							
							Item* item = h3->search_item(str3,j);
							
							if(item == NULL){
								
								cout<<"Item was not found in your inventory!"<<endl;
								continue;
								
							}
							
							else{
								
								h3->use((Potion*)item);
								
							}
							
							h3r++;
							continue;
						}												
						
						else if(str3 == "attack" || str3 == "Attack"){
							
							cout<<"Attack with Spell or Weapon?? (spell, weapon)"<<endl;
							cin>>str3;
							while (str3 != "Spell" && str3 != "spell" && str3 != "weapon" && str3 != "Weapon") {
								cout<<"Attack with Spell or Weapon?? (spell, weapon)"<<endl;
							cin>>str3;
							}
							cout<<"Give monster name (";
							for (int i=0 ; i < count_monsters ; i++) {
								if (i != count_monsters-1) {
									if (monsters[i]->get_alive()) {
										cout << monsters[i]->get_name() << ", ";
									}
								}
								else {
									if (monsters[i]->get_alive()) {
										cout << monsters[i]->get_name() ;	
									}
								}
							}
							cout << ")" << endl;
							
							cout<<"Give monster name"<<endl;
							cin>>str2;
							
							if(str3 == "Weapon" || str3 == "weapon"){
								
								cout<<"Give 0 for left hand or 1 for right hand"<<endl;
								cin>>j;
								Weapon* weapon = h3->get_weapon(j);
								
								if(weapon != NULL){
									
									int l;
									
									for(l = 0;l <= count_monsters - 1;l++){
										
										if(monsters[l]->get_name() == str2){
											
											break;
											
										}
									}
									
									if(monsters[l] != NULL && monsters[l]->get_name() == str2){
									
										h3->attack((*monsters[l]),(*weapon));
									
									}
									
									else{
										
										cout<<"Monster name given was wrong!"<<endl;
										continue;
										
									}
									
								}
								
								else{
									
									cout<<"Maybe hand given (0 , 1) was wrong or weapon was not equiped"<<endl;
									continue;
									
								}
								
								h3r++;
								continue;
							}
							
							else if(str3 == "Spell" || str3 == "spell"){
								
								cout<<"Give spell name"<<endl;
								cin>>str3;
								cout<<"Give monster name"<<endl;
								cin>>str2;
								cout<<"Give level/minimum level"<<endl;
								cin>>j;
								Item* spell = h3->search_item(str3,j);
								
								int l;
									
								for(l = 0;l <= count_monsters - 1;l++){
										
									if(monsters[l]->get_name() == str2){
											
										break;
											
									}	
								}
								
								if(spell = NULL){
									
									cout<<"Item was not found in your inventory!"<<endl;
									
								}
								
								else{
									
									h3->attack((*monsters[l]),(*(Spell*)spell));
									
								}
								
								h3r++;
								continue;
								
							}
						}
					}
					
					for(int b = 0;b <= count_monsters - 1;b++){				//now it's monsters' turn they randomly attack availble heroes
						
						if (nmb == 3) {
							if (!h1->get_alive() && !h2->get_alive() && !h3->get_alive() ) { //If all heroes are dead
								break;
							}
						}
						else if (nmb ==2) {
							if (!h1->get_alive() && !h2->get_alive() ) { //If all heroes are dead
								break;
							}
						}
						else {
							if (!h1->get_alive() ) { //If all heroes are dead
								break;
							}	
						}
						
						int rn = rand() % nmb + 1;
						
						if(rn == 1 && monsters[b]->get_health() > 0){
							if (h1->get_alive()) {
								monsters[b]->attack(*h1);	
							}
							else {
								b--;
								continue;
							}
							
						}
						
						else if(rn == 2 && monsters[b]->get_health() > 0){
							
							if (h2->get_alive()) {
								monsters[b]->attack(*h2);	
							}
							else {
								b--;
								continue;
							}
							
						}
						
						else if(rn == 3 && monsters[b]->get_health() > 0){
							
							if (h3->get_alive()) {
								monsters[b]->attack(*h3);	
							}
							else {
								b--;
								continue;
							}							
						}
					}
					
					rounds++;
					grid.round_info();
					
					if(h1 != NULL && h1->get_potion_rounds() > 0){			//a round has passed in the battle and potions lose a round or if rounds of potion hit 0 hero loses all of his stats
						
						h1->set_potion_rounds(h1->get_potion_rounds() - 1);
						
					}
					
					else if(h1 != NULL && h1->get_potion_rounds() == 0){
						
						h1->set_potion_agillity_boost(0);
						h1->set_potion_dexterity_boost(0);
						h1->set_potion_strength_boost(0);
						
					}
					
					if(h2 != NULL && h2->get_potion_rounds() > 0){
						
						h2->set_potion_rounds(h2->get_potion_rounds() - 1);
						
					}
					
					else if(h2 != NULL && h2->get_potion_rounds() == 0){
						
						h2->set_potion_agillity_boost(0);
						h2->set_potion_dexterity_boost(0);
						h2->set_potion_strength_boost(0);
						
					}
					if(h3 != NULL && h3->get_potion_rounds() > 0){
						
						h3->set_potion_rounds(h3->get_potion_rounds() - 1);
						
					}
					
					else if(h3 != NULL && h3->get_potion_rounds() == 0){
						
						h3->set_potion_agillity_boost(0);
						h3->set_potion_dexterity_boost(0);
						h3->set_potion_strength_boost(0);
												
					}				
				}
			}
			
			else if(str3 == "m"){				//if grid.move returned m , heroes have reached a market
				
				Market* market = grid.get_market_box();			//grid.get_market_box() returns a pointer to the market
				cout<<"You have reached a market!"<<endl;
				cout<<"Would you like to enter (yes, no)?"<<endl;		//asks if players want to go into the market
				cin>>str3;
				
				if(str3 == "n" || str3 == "N" || str3 == "No" || str3 == "no"){			//answer was no players choose another move
					
					continue;
					
				}
				
				else if(str3 == "Y" || str3 == "y" || str3 == "Yes" || str3 == "yes"){		//ansswer was yes
					
					if(nmb > 2){			//small if just for fun
						
						cout<<"Please keep your distance to prevent the spread of COVID-19"<<endl;
						
					}
					
					cout<<"What would you like to do (show(spells,potions,armors,weapons) , buy , sell , buyable , exit)?"<<endl;			//asks what players would like to do
					cin>>str3;
					
					bool asked_the_player= true;
					while(str3 != "exit" || str3 != "Exit" || str3 != "Exitmarket" || str3 == "Quitmarket" || str3 != "Quitgame" || str3 != "Endgame" || str3 != "quit" || str3 != "end" || str3 == "End" || str3 == "Quit"){  //while stops if players want to quit the game or exit the market
						
						if (asked_the_player == false) {			//checks if a function was given by the player
							cout<<"What would you like to do (show(spells,potions,armors,weapons) , buy , sell , buyable , exit)?"<<endl;
							cin>>str3;	
						}
						asked_the_player= false;
						
					
						if(str3 == "Exitmarket" || str3 == "exit" || str3 == "Exit" || str3 == "Quitmarket" || str3 == "exitmarket" || str3 == "quitmarket"){			//checks if player wants to exit market
							
							break;
							
						}
						
						else if(str3 == "Quitgame" || str3 == "Endgame" || str3 == "quit" || str3 == "end" || str3 == "End" || str3 == "Quit"){				//checks if player want to quit the game
														
							cout<<"Game is now exiting!"<<endl;
							return 0;
							
						}
						
						
							
						if(str3 == "show" || str3 == "Show"){					//player typed show 
								
							cout<<"What would you like to see?"<<endl;			//depending on what player types (potion,weapons,armor,spells) , market->show is called
							cin>>str3;
								
							if(str3 == "potions" || str3 == "Potions" || str3 == "Potion" ||str3 == "potion"){
									
								market->show_potions();
									
							}
								
							else if(str3 == "weapons" || str3 == "Weapons" || str3 == "Weapon" || str3 == "weapon"){
									
								market->show_weapons();
									
							}
								
							else if(str3 == "spells" || str3 == "Spells" || str3 == "Spell" || str3 == "spell"){
									
								market->show_spells();
									
							}
								
							else if(str3 == "armors" || str3 == "Armors" || str3 == "Armor" || str3 == "Armor"){
									
								market->show_armors();
									
							}
						}
							
						else if(str3 == "buyable" || str3 == "Buyable"){			//if player typed buyable , all affordable options in market are printed
							cout<<"Give hero name "<<endl;
							cin>>str2;
						
							if(h1 != NULL && h1->get_name() == str2){		
								market->show_buyable(h1);
								
							} 
							else if (h2 != NULL && h2->get_name() == str2){		
								market->show_buyable(h2);
								
							} 
							else if (h3 != NULL && h3->get_name() == str2){		
								market->show_buyable(h3);
								
							} 
						}
							
						else if(str3 == "buy" || str3 == "Buy"){			//player typed buy
							cout<<"Give hero name "<<endl;					//player gives hero's name
							cin>>str2;	
							
							if(h1 != NULL && h1->get_name() == str2){		//checks if hero name matches with hero name given	

								cout<<"Give name of item"<<endl;
								cin>>str2;
								Item* item = market->get_item(str2);
								
								if (item == NULL) {		//checks if item was not found
									
									continue;
									
								}
								
								if(item->get_price() > h1->get_money()){			//player does not have enough money
									
									cout<<"You dont have enough money to buy "<<item->get_name()<<endl;
									
								}
								
								else{			//h1->buy is called player has bought the item
									
									h1->buy(item);
									
								}
								
							} 
							else if(h2 != NULL && h2->get_name() == str2){			//same rules apply for second hero if name matches with name given from player
								
								cout<<"Give name of item"<<endl;
								cin>>str2;
								Item* item = market->get_item(str2);
								
								if (item == NULL) {
									continue;
								}
								
								if(item->get_price() > h2->get_money()){
									
									cout<<"You dont have enough money to buy "<<item->get_name()<<endl;
									
								}
								
								else{
									
									h2->buy(item);
									
								}
								
							}
							else if(h3 != NULL && h3->get_name() == str2){				//same rules apply for third hero if name matches with name given from player
								
								cout<<"Give name of item"<<endl;
								cin>>str2;
								Item* item = market->get_item(str2);
								
								if (item == NULL) {
									continue;
								}
								
								if(item->get_price() > h3->get_money()){
									
									cout<<"You dont have enough money to buy "<<item->get_name()<<endl;
									
								}
								
								else{
									
									h3->buy(item);
									
								}
								
							}	
						}
							
						else if(str3 == "sell" || str3 == "Sell"){			//if player typed sell
							
							cout<<"Give hero name "<<endl;					//player gives hero's name
							cin>>str2;	
							
							if(h1 != NULL && h1->get_name() == str2){		//name given matches first hero's name
								
								cout<<"Give name of item"<<endl;			//player gives name and minimum level of item
								cin>>str2;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>j;

								Item* item = h1->search_item(str2,j);			//search is called
								
								if(item == NULL){			//item was not found
									
									cout<<"Item was not found in your inventory!"<<endl;
									
								}
								
								else{			//item was found h1->sell is called
								
									h1->sell(*item);
									
								}
							}
							else if(h2 != NULL && h2->get_name() == str2){				//same rules apply for second hero
								
								cout<<"Give name of item"<<endl;
								cin>>str2;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>j;

								Item* item = h2->search_item(str2,j);
								
								if(item == NULL){
									
									cout<<"Item was not found in your inventory!"<<endl;
									
								}
								
								else{
								
									h2->sell(*item);
									
								}
							}
							else if(h3 != NULL && h3->get_name() == str2){			//same rules apply for third hero
								
								cout<<"Give name of item"<<endl;
								cin>>str2;
								cout<<"Give level/minimum level of item"<<endl;
								cin>>j;

								Item* item = h3->search_item(str2,j);
								
								if(item == NULL){
									
									cout<<"Item was not found in your inventory!"<<endl;
									
								}
								
								else{
								
									h3->sell(*item);
									
								}
							}
								
						}				
					}
				}
			}
			
			else if(str3 == "c"){			//if grid.move returned c nothing happens heroes have reached a common block
				
				cout<<"You have reached a common block , choose your move (up, down, right, left, info, equip, inventory, help, quit): "<<endl;
				cin>>str3;
				continue;
				
			}
			
			else if(str3 == "n"){			//if grid.move returned n heroes have reached a non-accessible block , which they can't go to/heroes choose another move
				
				cout<<"You have reached a non-accessible block choose another move (up, down, right, left, info, equip, inventory, help, quit) : "<<endl;
				cin>>str3;
				continue;
								
			}
			
			else if(str3 == "e"){			//if grid.move returns e heroes have reached an edge they can't go any further (up/down/left/right)
				
				cout<<"Choose another move (up, down, right, left, info, equip, inventory, help, quit): "<<endl;
				cin>>str3;
				continue;
								
			}
			
			else if(str3 != "Quitgame" || str3 != "Endgame" || str3 != "quit" || str3 != "end" || str3 == "End" || str3 == "Quit"){			//checks if playerrs want to quit the game
				
				cout<<"You have successfully quited the game"<<endl;
				for (i= 0 ; i <50 ; i++) {
		
					delete pot_array[i];
					delete wea_array[i];
					delete arm_array[i];
					
				}
				delete pot_array;
				delete wea_array;
				delete arm_array;
				
				for(int c = 0;c < 20;c++){
					
					delete spe_array[c] ;
					
				}
				
				
				for(int c=20; c < 40;c++){
					
					delete spe_array[c] ;
					
				}
				
				for(int c= 40; c <60; c++){
					
					delete spe_array[c];
					
				}
				delete spe_array;
				return 0;
			}
		}
		
		cout<<"Choose your next move (up, down, right, left, info, equip, inventory, help, quit)"<<endl;			//end of while players must choose their next move
		cin>>str3;
	}
	
	
	
	cout<<"You have successfully quited the game"<<endl;
	
	
		
		
	for (i= 0 ; i <50 ; i++) {
		
		delete pot_array[i];
		delete wea_array[i];
		delete arm_array[i];
		
	}
	delete pot_array;
	delete wea_array;
	delete arm_array;
	
	for(int c = 0;c < 20;c++){
		
		delete spe_array[c] ;
		
	}
	
	
	for(int c=20; c < 40;c++){
		
		delete spe_array[c] ;
		
	}
	
	for(int c= 40; c <60; c++){
		
		delete spe_array[c];
		
	}
	delete spe_array;
	
	return 0;
}


