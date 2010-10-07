#ifndef __OBJECT_H
#define __OBJECT_H

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

#include <string>

using namespace std;

/** @brief An object which can occupy an (x,y) space.
 *
 * This base class represents an object in the game.  It can be extended to provide new
 * functionality, such as movement, or interaction with other objects.  Every object has a
 * name, which is not necessarily unique.
 */

class Object 
{
    public:

        /** @brief Rightmost X position of the board.  Objects cannot be on squares with a greater
         * x-coordinate.
         */
        static const int X_MAX = 10;
        /** @brief Lowest Y position of the board.  Objects cannot be on squares with a greater
         * y-coordinate.
         */
        static const int Y_MAX = 10;

        /** @brief Creates a new object at location (5, 5).
         * 
         * @param name Short description of the object.
         * @todo Randomize new object location.
         * @todo Ensure object is on an unoccupied square.
         *
         */

        Object(const string name);

        /** @brief Creates a new object at location (x,y).
         *
         * @param x X-coordinate of the new object 
         * @param y Y-coordinate of the new object 
         * @param name Short description of the object.
         * @bug Does not ensure x and y are actually on the board.
         */

        Object(const string name, const int x, const int y);
	
	/** @brief Cleans up the object when it is destroyed.
	 *
	 * We technically don't need this, but we DO need some virtual function
	 * so that objects will be polymorphic (i.e. we can use dynamic_cast on them).  Since
	 * a virtual destructor is a good idea in C++ most of the time anyway, we do that here.
	 */

	virtual ~Object();

        /** @brief Modifies the object's name.
         * 
         * @param name The new name of the object.
         *
         */

        void set_name(const string name);

	/** @brief Modifies the object's value.
	 *
	 * @param value The new value of the object.
	 *
	 */

	void set_value(const int value);

        /** @brief Retrieves the object's current x position.
         *
         * @return The current x-coordinate of the object.
         */

        int x() const;

        /** @brief Retrieves the object's current y position.
         *
         * @return The current y-coordinate of the object.
         */

        int y() const;

        /** @brief Retrieves the object's name
         *
         * @return A short description of the object
         */

        string name() const;

	/** @brief Retrieves the object's value
	 *
	 * @return The value of the object
	 */

	int value() const;

    protected:
        /** @brief Short description of the object 
         */
        string m_name;

	/** @brief The value of the object
	 */
	int m_value;

        /** @brief X-Coordinate of the object 
         */
        int m_x;

        /** @brief Y-Coordiate of the object
         */
        int m_y;
};
#endif //__OBJECT_H
