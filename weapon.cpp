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

#include "weapon.h"
#include <string>
#include <cstdlib>

using namespace std;

Weapon::Weapon(const string name) : Object(name)
{
        m_name = name;
        m_str = (random() % 5) + 1;
}

Weapon::Weapon(const string name, const int x, const int y) : Object(name, x, y)
{ 
        m_name = name;
        m_str  = (random() % 5) + 1;
	m_x = x;
	m_y = y;
}

Weapon::~Weapon()
{ }

void Weapon::set_name(const string name)
{
    m_name = name;
}

void Weapon::set_str(const int str)
{
	m_str = str;
}

int Weapon::x() const
{
    return m_x;
}

int Weapon::y() const
{
    return m_y;
}

void Weapon::set_x(int new_x)
{
    m_x = new_x;
}

void Weapon::set_y(int new_y)
{
    m_y = new_y;
}

string Weapon::name() const
{
    return m_name;
}

int Weapon::str() const
{
    return m_str;
}
