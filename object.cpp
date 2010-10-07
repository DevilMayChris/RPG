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

#include "object.h"
#include <string>
#include <cstdlib>

using namespace std;

Object::Object(const string name) : m_name(name), m_x(5), m_y(5), m_healing(1)
{
        //Initial Values are selected randomly, but are multiples of 5 in the range 0 to 100.
	m_value = (random() % 21 ) * 5;
}

Object::Object(const string name, const int x, const int y) : m_name(name), m_x(x), m_y(y), m_healing(1)
{ 
        //Initial Values are selected randomly, but are multiples of 5 in the range 0 to 100.
	m_value = (random() % 21 ) * 5;
}

Object::~Object()
{ }

void Object::set_name(const string name)
{
    m_name = name;
}

void Object::set_value(const int value)
{
	m_value = value;
}

void Object::set_healing(const int healing)
{
	if (healing >= 0)
		m_healing = healing;
}

int Object::x() const
{
    return m_x;
}

int Object::y() const
{
    return m_y;
}

string Object::name() const
{
    return m_name;
}

int Object::value() const
{
    return m_value;
}

int Object::healing() const
{
    return m_healing;
}
