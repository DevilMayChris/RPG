#ifndef __PLAYER_H
#define __PLAYER_H

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
#include "weapon.h"
#include "armor.h"
#include <vector>

using namespace std;

/** @brief A special object which represents one player of the game.
 *
 * Unlike most objects, players have inventories and can pick up objects.
 * Movement of the player is controlled by the keyboard in the main function.
 */

class Player : public MovingObject {
	private:
		/** @brief An inventory of all items the player has taken.
		 */
		vector<Object *> inventory;

		/** @brief The player's current score.
		 */
		int m_score;

		/** @brief The player's current health on a scale of 0 to 100.
		 */
		int m_health;
		
		/** @brief The player's current weapon.
		 */
		string weapon;
		
		/** @brief The player's current armor.
		 */
		string armor;
		
		/** @brief The player's strength.
		 */
		int str;
		
		/** @brief The player's toughness.
		 */
		int tgh;
		
		

	public:
	  	/** @brief Create a player object.
	         *
	         * @param name Name of the player.
	         */
		Player(string name);

	  	/** @brief Create a player object.
	         *
	         * @param name Name of the player.
	         * @param x Initial x-coordinate of the player.
	         * @param y Initial y-coordinate of the player.
	         */

		Player(string name, int x, int y);


		/** @brief Move an object from the room into a player's inventory.
		 *
		 * Only non-self-moving objects (i.e. non-monsters) can be taken.  The function
		 * checks for this and returns false if the item is a monster.  Taking items increases 
		 * a player's score.
		 *
		 * @param item A pointer to the object to take.
		 * @return If taking the item was successful, returns true.  Otherwise, returns false.
		 */

		bool take_item(Object* item);

		/** @brief Increases the player's score
		 *
		 * @param bonus The amount to increase the score (must be positive).
		 */

		void give_bonus(const int bonus);

		/** @brief Decreases the player's current health.
		 *
		 * The health must be between 0 and 100.  If it falls below 0,
		 * the player has died.
		 *
		 * @param damage How much to decrease the player's health.
		 * @return Returns true if the player is still alive, false if he has died.
		 */

		bool hurt_player(const int damage);

		/** @brief Increases the player's current health.
		 *
		 * The health must be between 0 and 100.  If healed above 100, we
		 * simply round to 100.
		 *
		 * @param healing How much to increase the player's health.
		 */

		void heal_player(const int healing);


		/** @brief Retrieve the player's current score
		 * 
		 * @return Returns the integer value of the score.
		 */

		int score() const;

		/** @brief Retrieve the player's current health
		 *
		 * @return Returns the player's current health in points out of 100.
		 */

		int health() const;
		
		/** @brief Set player's weapon.
		 * 
		 *  @param weapon A pointer to the weapon.
		 */
		
		void set_weapon(Weapon* weapon);
		
		/** @brief Set player's armor.
		 * 
		 *  @param armor A point to the armor.
		 */
		
		void set_armor(Armor* armor);
		
		/** @brief Get player's armor name.
		 * 
		 *  @return The player's armor value.
		 */
		
		string get_armor();
		
		/** @brief Get player's weapon name.
		 * 
		 *  @return The player's weapon value.
		 */
		
		string get_weapon();
		
		/** @brief Get player's str.
		 * 
		 *  @return The player's str value.
		 */
		
		int get_str();
		
		/** @brief Get player's tgh.
		 * 
		 *  @return The player's tgh value.
		 */
		
		int get_tgh();
};

#endif //__PLAYER_H
