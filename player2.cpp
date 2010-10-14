/*
 *  Player2.h
 *  
 *
 *  Created by Garrett Wyrick on 10/14/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#include "monster.h"
#include "Player2.h"
#include <cstdlib>

using namespace std;

Player2::Player2(string name) : MovingObject(name), m_score(0), m_health(50)
{ }

Player2::Player2(string name, int x, int y) : MovingObject(name, x, y), m_score(0), m_health(50)
{ }

bool Player2::take_item(Object* item)
{
	//Check to see if the item is living
	Monster* mon = dynamic_cast<Monster *>(item);
	if (mon)
		return false;
	
	//Put the item in the Player2's inventory.
	inventory.push_back(item);
	
	//Heal the Player2 by the object's healing potential
	m_health += item->healing();
	
	m_score += item->value();
	
	return true;
}

void Player2::give_bonus(const int bonus)
{
	if (bonus > 0)
		m_score += bonus;
}

int Player2::score() const
{
	return m_score;
}

int Player2::health() const
{
	return m_health;
}

bool Player2::hurt_Player2(const int damage)
{
	if (damage > m_health) {
		m_health = 0;
		return false;
	}
	m_health -= damage;
	return true;
}

void Player2::heal_Player2(const int healing)
{
	m_health += healing;
	if (m_health > 100)
		m_health = 100;
}

