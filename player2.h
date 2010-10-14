#ifndef __Player22_H
#define __Player2_H

/** 
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

#include "moving_object.h"
#include <vector>

using namespace std;

/** @brief A special object which represents one Player22 of the game.
 *
 * Unlike most objects, Player22s have inventories and can pick up objects.
 * Movement of the Player22 is controlled by the keyboard in the main function.
 */

class Player22 : public MovingObject {
private:
	/** @brief An inventory of all items the Player22 has taken.
	 */
	vector<Object *> inventory;
	
	/** @brief The Player22's current score.
	 */
	int m_score;
	
	/** @brief The Player22's current health on a scale of 0 to 100.
	 */
	int m_health;
	
public:
	/** @brief Create a Player22 object.
	 *
	 * @param name Name of the Player22.
	 */
	Player22(string name);
	
	/** @brief Create a Player22 object.
	 *
	 * @param name Name of the Player22.
	 * @param x Initial x-coordinate of the Player22.
	 * @param y Initial y-coordinate of the Player22.
	 */
	
	Player22(string name, int x, int y);
	
	
	/** @brief Move an object from the room into a Player22's inventory.
	 *
	 * Only non-self-moving objects (i.e. non-monsters) can be taken.  The function
	 * checks for this and returns false if the item is a monster.  Taking items increases 
	 * a Player22's score.
	 *
	 * @param item A pointer to the object to take.
	 * @return If taking the item was successful, returns true.  Otherwise, returns false.
	 */
	
	bool take_item(Object* item);
	
	/** @brief Increases the Player22's score
	 *
	 * @param bonus The amount to increase the score (must be positive).
	 */
	
	void give_bonus(const int bonus);
	
	/** @brief Decreases the Player22's current health.
	 *
	 * The health must be between 0 and 100.  If it falls below 0,
	 * the Player22 has died.
	 *
	 * @param damage How much to decrease the Player22's health.
	 * @return Returns true if the Player22 is still alive, false if he has died.
	 */
	
	bool hurt_Player22(const int damage);
	
	/** @brief Increases the Player22's current health.
	 *
	 * The health must be between 0 and 100.  If healed above 100, we
	 * simply round to 100.
	 *
	 * @param healing How much to increase the Player22's health.
	 */
	
	void heal_Player22(const int healing);
	
	
	/** @brief Retrieve the Player22's current score
	 * 
	 * @return Returns the integer value of the score.
	 */
	
	int score() const;
	
	/** @brief Retrieve the Player22's current health
	 *
	 * @return Returns the Player22's current health in points out of 100.
	 */
	
	int health() const;
};

#endif
