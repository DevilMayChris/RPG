#ifndef __MOVING_OBJECT_H
#define __MOVING_OBJECT_H

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

/** @brief An object which can move in the four cardinal directions (left, right, up, and down).
 *
 * This class extends the basic object class to allow objects to move up, down, left, or right.
 * The player object should extend this class as should monsters.
 *
 * Movement is bounded within a box with corners at (0, 0) and (X_MAX, Y_MAX), inclusive.
 */

#include "object.h"

class MovingObject : public Object
{
    public:
        /** @brief Create a moving object.
         *
         * @param name Name of the object.
         */

        MovingObject(const string name);
        
        /** @brief Create a moving object with name @a name at position @a x,@a y.
         *
         * @param name Name of the object.
         * @param x Initial X-coordinate of the object.
         * @param y Initial Y-coordinate of the object.
         */

        MovingObject(const string name, const int x, const int y);

        /** @brief Move object one square to the left, if not already at left edge of board.
         *
         * @return Returns true if object's position is modified, false if the object was at the edge of the
         * board.
         */

        bool move_left();

        /** @brief Move object one square to the right, if not already at right edge of board.
         *
         * @return Returns true if object's position is modified, false if the object was at the edge of the
         * board.
         */

        bool move_right();

        /** @brief Move object one square up, if not already at top of board.
         *
         * @return Returns true if object's position is modified, false if the object was at the edge of the
         * board.
         */

        bool move_up();

        /** @brief Move object one square down, if not already at bottom of board.
         *
         * @return Returns true if object's position is modified, false if the object was at the edge of the
         * board.
         */

        bool move_down();
};
#endif //__MOVING_OBJECT_H
