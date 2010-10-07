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

using namespace std;

vector<Object*> collection;

string names[] = {"hammer", "iron bar", "pocket watch", "missing bit", "used paper towel", "piece of someone's sanity", "unconscious programmer"};
string moving_names[] = {"tumbleweed", "vicious memory leak", "sarcastic script-kiddy", "dangerous hacker", "absent-minded professor"};

int main(int argc, char** argv){
    int num_objects = 10;
    int num_moving = 0;
    string name;
    int x, y;
    char command;

    Player player("player");

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

    do{
	cout << "[" << player.x() << ", " << player.y() << "]" << endl;
	cout << "Your score is: " << player.score() << endl;
        cout << "Enter a command:" << endl;
        cout << "   'i' to move up." << endl;
        cout << "   'm' to move down." << endl;
        cout << "   'j' to move left." << endl;
        cout << "   'k' to move right." << endl;
	cout << "   't' to take an item from this room." << endl;
	cout << "   'a' to attack a monster in this room." << endl;
        cout << "   'q' to quit." << endl;
	cout << endl;

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

        //Check for objects on the same square as the player
        for (vector<Object*>::iterator i=collection.begin(); i != collection.end(); ) {
            if (player.x() == (*i)->x() && player.y() == (*i)->y()) {
                cout << "There is a " << (*i)->name() << " here." << endl;
                i++;
            } else {
                i++;
            }
        }
    } while (command != 'q');
}
