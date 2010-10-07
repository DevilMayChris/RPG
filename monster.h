#ifndef __MONSTER_H
#define __MONSTER_H

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

/** @brief A moving object which self-updates.
 *
 * Most moving objects have to be explicitly moved.  The monster class,
 * however, moves in a random direction every time an "update" is called.  The
 * update function can also be extended to do things like healing the monster,
 * so it is very flexible.
 */

class Monster : public MovingObject {
	protected:
		/** @brief The monster's current health on a scale of 0 to 100.
		 */
		int m_health;

	public:
	  	/** @brief Create a monster object.
	         *
	         * @param name Name of the object.
	         */
		Monster(string name);

	  	/** @brief Create a monster object.
	         *
	         * @param name Name of the object.
	         * @param x Initial x-coordinate of the object.
	         * @param y Initial y-coordinate of the object.
	         */

		Monster(string name, int x, int y);

		/** @brief Update the monster
		 *
		 * This moves the object around in a random direction.
		 */
		void update();

		/** @brief Decreases the monsters's current health.
		 *
		 * The health must be between 0 and 100.  If it falls below 0,
		 * the monster has died.
		 *
		 * @param damage How much to decrease the monster's health.
		 * @return Returns true if the monster is still alive, false if he has died.
		 */

		bool hurt_monster(const int damage);

		/** @brief Increases the monster's current health.
		 *
		 * The health must be between 0 and 100.  If healed above 100, we
		 * simply round to 100.
		 *
		 * @param healing How much to increase the monster's health.
		 */

		void heal_monster(const int healing);

		/** @brief Retrieve the monster's current health
		 *
		 * @return Returns the monster's current health in points out of 100.
		 */

		int health() const;
};

#endif
