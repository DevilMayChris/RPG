/** A simple role-playing game 
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
#include <string>

using namespace std;

MovingObject::MovingObject(const string name) : Object(name)
{ }

MovingObject::MovingObject(const string name, const int x, const int y) : Object(name, x, y)
{ }

bool MovingObject::move_left()
{
    if (m_x>0){
        m_x--;
        return true;
    } else {
        return false;
    }
}

bool MovingObject::move_up()
{
    if (m_y>0){
        m_y--;
        return true;
    } else {
        return false;
    }
}

bool MovingObject::move_right()
{
    if (m_x<X_MAX){
        m_x++;
        return true;
    } else {
        return false;
    }
}

bool MovingObject::move_down()
{
    if (m_y<Y_MAX){
        m_y++;
        return true;
    } else {
        return false;
    }
}
