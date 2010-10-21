/** @mainpage A simple role-playing game 
 *  @version 0.1
 *  @author Dr. Robert Marmorstein
 *  @date 8-30-2010
 *
 *  (c) Copyright 2010, Dr. Robert Marmorstein (robert@narnia.homeunix.com)
 *  Released under the GPLv2 licence.  Please see LICENSE for more details.
 *
 *   This program is free software; you can redistribute it and/or modify
 *       it under the terms of the GNU General Public License as published by
 *           the Free Software Foundation; either version 2 of the License, or
 *               (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *         but WITHOUT ANY WARRANTY; without even the implied warranty of
 *             MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *                 GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License along
 *         with this program; if not, write to the Free Software Foundation, Inc.,
 *             51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 **/

#include <iostream>
#include <vector>
#include <cstdlib>

#include "object.h"
#include "monster.h"
#include "player.h"
#include "weapon.h"
#include "armor.h"

using namespace std;

vector<Object*> collection;

string names[] = {"hammer", "iron bar", "pocket watch", "missing bit", "used paper towel", "piece of someone's sanity", "unconscious programmer"};
string moving_names[] = {"tumbleweed", "vicious memory leak", "sarcastic script-kiddy", "dangerous hacker", "absent-minded professor"};

int main(int argc, char** argv){
    int num_objects = 10;
    int num_moving = 5;
    string name;
    int x, y;
    char command;
    int t=1;
	
    Player player("player");
    Player player2("player2");
	
    //If at least one command-line argument was provided, use it as the number of objects to create.
    if (argc > 1) {
        num_objects = atoi(argv[1]);
    }
	
    if (argc > 2) {
        num_moving = atoi(argv[2]);
    }
	
    //Create all the non-moving objects
    for (int i = 0; i < num_objects - num_moving; i++) {
        x = random() % 11;
        y = random() % 11;
        
        name = "random object";
        if (i < 7) {
            name = names[i];
        }
		
        collection.push_back(new Object(name, x, y));
    }
	
    for (int i = 0; i < num_moving; i++) {
        x = random() % 11;
        y = random() % 11;
		
        name = "random moving object";
        if (i < 5) {
            name = moving_names[i];
        }
		
        collection.push_back(new Monster(name,x,y));
    }
		
    //Create armor and weapons.
    Weapon broadsword("Broadsword", random() % 11, random() % 11, 3);
    Weapon pike("Pike", random() % 11, random() % 11, 4);
    Armor chainmail("Chainmail", random() % 11, random() % 11, 3);
    Armor plate("Plate", random() % 11, random() % 11, 4);

    do{ 
		
	
		
	while(t==1){
		cout << "__________________________________________________"<<endl;
		cout << "Player 1" << endl;
		cout << "[" << player.x() << ", " << player.y() << "]" << endl;
		cout << "Your score is: " << player.score() << endl;
		cout << "________________________________________"<<endl;
	        cout << "Enter a command:" << endl;
                cout << "   'i' to move up." << endl;
                cout << "   'm' to move down." << endl;
                cout << "   'j' to move left." << endl;
                cout << "   'k' to move right." << endl;
		cout << "   't' to take an item from this room." << endl;
		cout << "   'a' to attack a monster in this room." << endl;
                cout << "   'q' to quit." << endl;
		cout << "__________________________________________________"<<endl;
		
        //Process command and move player.
        cin >> command;
		
        switch (command) {
            case 'i':
                player.move_up();
                break;
            case 'm':
                player.move_down();
                break;
            case 'j':
                player.move_left();
                break;
            case 'k':
                player.move_right();
                break;
			case 't':
				for (vector<Object*>::iterator i=collection.begin(); i != collection.end(); ) {
					if ((*i)->x() == player.x() && (*i)->y() == player.y()) {
					    Weapon* weap = dynamic_cast<Weapon*>(*i);
					    Armor* arm = dynamic_cast<Armor*>(*i);
					    if (weap){
					        cout << "You inspect the " << weap->name(); << "." << endl;
						if (player.str() < weap->str()) {
						    player.set_weapon(weap);
						    cout << 
						if (player.take_item(*i)) {
							cout << "You take a " << (*i)->name() << endl;
							i = collection.erase(i);
						}
						else {
							i++;
						
						
						}
					}
					else {
						i++;
					    
					}
					}
			case 'a':
				for (vector<Object*>::iterator i=collection.begin(); i != collection.end(); ) {
					if ((*i)->x() == player.x() && (*i)->y() == player.y()) {
						Monster* mon = dynamic_cast<Monster*>(*i);
						if (mon){
								cout << "What do you do?" << endl;
								cout << "'a' for a normal attack." << endl;
								cout << "'s' for a special attack." << endl;
								cin >> command;
								switch (command) {
								    case 'a':
								        cout << "You attack " << mon->name() << endl;
								        if (random() % 2 == 0) {
									    cout << mon->name() << " wins!  You lose 5 health." << endl;
									        if (player.hurt_player(5) == false) {
										    cout << "You have died!" << endl;
										    return 1;
									        }
									    i++;
									
								        }
								        else {
									    cout << "You win!  " << mon->name() << " loses 5 health." << endl;
									    if (mon->hurt_monster(5) == false) {
										cout << "You have killed the monster!" << endl;
										i = collection.erase(i);
										player.give_bonus(10);
									    }
								        }
								    case 's':
								        cout << "You use a special attack on " << mon->name() << endl;
								        if (random() % 10 >= 3) {
									    cout << mon->name() << " wins!  You lose 5 health." << endl;
									        if (player.hurt_player(5) == false) {
										    cout << "You have died!" << endl;
										    return 1;
									        }
									    i++;
									
								        }
								        else {
									    cout << "Your special attack hits!  " << mon->name() << " loses 20 health." << endl;
									    if (mon->hurt_monster(20) == false) {
										cout << "You have killed the monster!" << endl;
										i = collection.erase(i);
										player.give_bonus(10);
									    }
								        }
								}
							}
						else 
							i++;
						   
											}
					else 
						i++;
					    
						
					
				}
            default:
                break;
		}
		
			//Move monsters around
			for (vector<Object*>::iterator i=collection.begin(); i != collection.end(); i++) {
				Monster* mon = dynamic_cast<Monster*>(*i);
				if (mon)
					mon->update();
			}
			
			//Check for objects on the same square as the player
			for (vector<Object*>::iterator i=collection.begin(); i != collection.end(); ) {
				if (player.x() == (*i)->x() && player.y() == (*i)->y()) {
					cout << "There is a " << (*i)->name() << " here." << endl;
					i++;
				} else {
					i++;
				}
			}
			t=2;}
//THIS IS WHERE P2 BEGINS
		//\//\//
		//
		//
		//
		//
		//
		//
		while(t==2){
			cout << "__________________________________________________"<<endl;
			cout << "player2"<<endl;
			cout << "___________________________________"<<endl;
			cout << "[" << player2.x() << ", " << player2.y() << "]" << endl;
			cout << "Your score is: " << player2.score() << endl;
			cout << "Enter a command:" << endl;
			cout << "   'w' to move up." << endl;
			cout << "   'x' to move down." << endl;
			cout << "   'z' to move left." << endl;
			cout << "   'd' to move right." << endl;
			cout << "   't' to take an item from this room." << endl;
			cout << "   'a' to attack a monster in this room." << endl;
			cout << "   'q' to quit." << endl;
			cout << "__________________________________________________"<<endl;
			
			//Process command and move player2.
			cin >> command;
			
			switch (command) {
				case 'w':
					player.move_up();
					break;
				case 'x':
					player.move_down();
					break;
				case 'z':
					player.move_left();
					break;
				case 'd':
					player.move_right();
					break;
				case 't':
					for (vector<Object*>::iterator i=collection.begin(); i != collection.end(); ) {
						if ((*i)->x() == player2.x() && (*i)->y() == player2.y()) {
							if (player2.take_item(*i)) {
								cout << "You take a " << (*i)->name() << endl;
								i = collection.erase(i);
							}
							else {
								i++;
								
							}
						}
						else {
							i++;
					
						}
					}
				case 'a':
					for (vector<Object*>::iterator i=collection.begin(); i != collection.end(); ) {
						if ((*i)->x() == player2.x() && (*i)->y() == player2.y()) {
							Monster* mon = dynamic_cast<Monster*>(*i);
							if (mon){
								cout << "You attack " << mon->name() << endl;
								if (random() % 2 == 0) {
									cout << mon->name() << " wins!  You lose 5 health." << endl;
									if (player.hurt_player(5) == false) {
										cout << "You have died!" << endl;
										return 1;
									}
									i++;
								}
								else {
									cout << "You win!  " << mon->name() << " loses 5 health." << endl;
									if (mon->hurt_monster(5) == false) {
										cout << "You have killed the monster!" << endl;
										i = collection.erase(i);
										player.give_bonus(10);
																		}
									 }
									}
							else 
								i++;
					
						}
						else 
							i++;
					
					}
				default:
					break;
			}
		
		
		//Move monsters around
		for (vector<Object*>::iterator i=collection.begin(); i != collection.end(); i++) {
			Monster* mon = dynamic_cast<Monster*>(*i);
			if (mon)
				mon->update();
		}
		
        //Check for objects on the same square as the player2
        for (vector<Object*>::iterator i=collection.begin(); i != collection.end(); ) {
            if (player.x() == (*i)->x() && player.y() == (*i)->y()) {
                cout << "There is a " << (*i)->name() << " here." << endl;
                i++;
            } else {
                i++;
            }
        }
			t=1; }
	if (collection.empty() && player.score() > player2.score()) {
			cout << "PLAYER ONE WINS!" << endl;
		}else {
			if(player2.score()>player.score()){
				cout << "PLAYER TWO WINS!" << endl;
			}else {
				cout << "TIE"<<endl;
			}
		}

	

		

		
    } while (command != 'q' && !collection.empty());
			

}

