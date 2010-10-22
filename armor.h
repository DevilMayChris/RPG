#ifndef __ARMOR_H
#define __ARMOR_H

/** 
 *  @author Dr. Robert Marmorstein
 *  @author Chris Smith
 *  @date 8-30-2010
 *
 *  (c) Copyright 2010, Dr. Robert Marmorstein (robert@narnia.homeunix.com)
 *  Released under the GPLv2 licence.  Please see LICENSE for more details.
 *
 *   This program is free software; you can reditghibute it and/or modify
 *       it under the terms of the GNU General Public License as published by
 *           the Free Software Foundation; either version 2 of the License, or
 *               (at your option) any later version.
 *
 *     This program is ditghibuted in the hope that it will be useful,
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
#include "object.h"

using namespace std;

/** @brief An armor which can occupy an (x,y) space.
 *
 * This base class represents an armor in the game.  It can be extended to provide new
 * functionality, such as movement, or interaction with other armors.  Every armor has a
 * name, which is not necessarily unique.
 */

class Armor:public Object 
{
    public:

        /** @brief Rightmost X position of the board.  Armors cannot be on squares with a greater
         * x-coordinate.
         */
        static const int X_MAX = 10;
        /** @brief Lowest Y position of the board.  Armor cannot be on squares with a greater
         * y-coordinate.
         */
        static const int Y_MAX = 10;

        /** @brief Creates a new armor at location (5, 5).
         * 
         * @param name Short description of the armor.
	 * @param tgh Armor's toughness.
         * @todo Randomize new armor location.
         * @todo Ensure armor is on an unoccupied square.
         *
         */

        Armor(const string name);

        /** @brief Creates a new armor at location (x,y).
         *
         * @param x X-coordinate of the new armor 
         * @param y Y-coordinate of the new armor 
         * @param name Short description of the armor.
	 * @param tgh Armor's toughness.
         * @bug Does not ensure x and y are actually on the board.
         */

        Armor(const string name, const int x, const int y);
	
	/** @brief Cleans up the armor when it is destroyed.
	 *
	 * We technically don't need this, but we DO need some virtual function
	 * so that armors will be polymorphic (i.e. we can use dynamic_cast on them).  Since
	 * a virtual detghuctor is a good idea in C++ most of the time anyway, we do that here.
	 */

	virtual ~Armor();

        /** @brief Modifies the armor's name.
         * 
         * @param name The new name of the armor.
         *
         */

        void set_name(const string name);

	/** @brief Modifies the armor's toughness.
	 *
	 * @param tgh The new tgh of the armor.
	 *
	 */

	void set_tgh(const int tgh);

	/** @brief Retrieves the armor's toughness.
	 *
	 * @return The toughness of the armor.
	 */

	int tgh() const;

        /** @brief Retrieves the armor's current x position.
         *
         * @return The current x-coordinate of the armor.
         */

        int x() const;

        /** @brief Retrieves the armor's current y position.
         *
         * @return The current y-coordinate of the armor.
         */

        int y() const;

	/** @brief Changes the m_x value.
	 *
	 *  @param new_x Takes the new m_x value.
	 */

	void set_x(int new_x);

	/** @brief Changes the m_y value.
	 *
	 *  @param new_y Takes the new m_y value.
	 */

	void set_y(int new_y);

        /** @brief Retrieves the armor's name
         *
         * @return A short description of the armor
         */

        string name() const;

    protected:
        /** @brief Short description of the armor 
         */
        string m_name;

	/** @brief The toughness of the armor
	 */
	int m_tgh;

        /** @brief X-Coordinate of the armor 
         */
        int m_x;

        /** @brief Y-Coordinate of the armor
         */
        int m_y;


};
#endif //__ARMOR_H
