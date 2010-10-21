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

#include "armor.h"
#include <string>
#include <cstdlib>

using namespace std;

Armor::Armor(const string name, const int tgh) : m_name(name), m_x(5), m_y(5), m_tgh(tgh)
{
	m_name = name;
        m_tgh = tgh;
}

Armor::Armor(const string name, const int x, const int y, const int tgh) : m_name(name), m_x(x), m_y(y), m_tgh(tgh)
{ 
	m_name = name;
        m_tgh = tgh;
}

Armor::~Armor()
{ }

void Armor::set_name(const string name)
{
    m_name = name;
}

void Armor::set_tgh(const int tgh)
{
	m_tgh = tgh;
}

int Armor::x() const
{
    return m_x;
}

int Armor::y() const
{
    return m_y;
}

string Armor::name() const
{
    return m_name;
}

int Armor::tgh() const
{
    return m_tgh;
}
