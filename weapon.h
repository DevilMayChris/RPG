#ifndef __WEAPON_H
#define __WEAPON_H

/** 
 *  @author Dr. Robert Marmorstein
 *  @author Chris Smith
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

#include <string>

using namespace std;

/** @brief An weapon which can occupy an (x,y) space.
 *
 * This base class represents an weapon in the game.  It can be extended to provide new
 * functionality, such as movement, or interaction with other weapons.  Every weapon has a
 * name, which is not necessarily unique.
 */

class Weapon 
{
    public:

        /** @brief Rightmost X position of the board.  Weapons cannot be on squares with a greater
         * x-coordinate.
         */
        static const int X_MAX = 10;
        /** @brief Lowest Y position of the board.  Weapon cannot be on squares with a greater
         * y-coordinate.
         */
        static const int Y_MAX = 10;

        /** @brief Creates a new weapon at location (5, 5).
         * 
         * @param name Short description of the weapon.
         * @todo Randomize new weapon location.
         * @todo Ensure weapon is on an unoccupied square.
         *
         */

        Weapon(const string name);

        /** @brief Creates a new weapon at location (x,y).
         *
         * @param x X-coordinate of the new weapon 
         * @param y Y-coordinate of the new weapon 
         * @param name Short description of the weapon.
         * @bug Does not ensure x and y are actually on the board.
         */

        Weapon(const string name, const int x, const int y);
	
	/** @brief Cleans up the weapon when it is destroyed.
	 *
	 * We technically don't need this, but we DO need some virtual function
	 * so that weapons will be polymorphic (i.e. we can use dynamic_cast on them).  Since
	 * a virtual destructor is a good idea in C++ most of the time anyway, we do that here.
	 */

	virtual ~Weapon();

        /** @brief Modifies the weapon's name.
         * 
         * @param name The new name of the weapon.
         *
         */

        void set_name(const string name);

	/** @brief Modifies the weapon's str.
	 *
	 * @param str The new str of the weapon.
	 *
	 */

	void set_str(const int str);

	/** @brief Retrieves the weapon's strength.
	 *
	 * @return The strength of the weapon.
	 */

	int str() const;

        /** @brief Retrieves the weapon's current x position.
         *
         * @return The current x-coordinate of the weapon.
         */

        int x() const;

        /** @brief Retrieves the weapon's current y position.
         *
         * @return The current y-coordinate of the weapon.
         */

        int y() const;

        /** @brief Retrieves the weapon's name
         *
         * @return A short description of the weapon
         */

        string name() const;

    protected:
        /** @brief Short description of the weapon 
         */
        string m_name;

	/** @brief The strength of the weapon
	 */
	int m_str;

        /** @brief X-Coordinate of the weapon 
         */
        int m_x;

        /** @brief Y-Coordinate of the weapon
         */
        int m_y;


};
#endif //__WEAPON_H
