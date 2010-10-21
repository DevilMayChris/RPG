#include "monster.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Player::Player(string name) : MovingObject(name), m_score(0), m_health(50)
{ }

Player::Player(string name, int x, int y) : MovingObject(name, x, y), m_score(0), m_health(50)
{ }

bool Player::take_item(Object* item)
{
	//Check to see if the item is living
	Monster* mon = dynamic_cast<Monster *>(item);
	if (mon)
		return false;

	//Put the item in the player's inventory.
	inventory.push_back(item);

	//Heal the player by the object's healing potential
	m_health += item->healing();

	m_score += item->value();

	return true;
}

void Player::give_bonus(const int bonus)
{
	if (bonus > 0)
		m_score += bonus;
}

int Player::score() const
{
	return m_score;
}

int Player::health() const
{
	return m_health;
}

bool Player::hurt_player(const int damage)
{
	if (damage > m_health) {
		m_health = 0;
		return false;
	}
	m_health -= damage;
	return true;
}

void Player::heal_player(const int healing)
{
	m_health += healing;
	if (m_health > 100)
		m_health = 100;
}

void Player::set_weapon(Weapon* new_weapon)
{
	weapon = new_weapon->name();
	str = new_weapon->str();
}

void Player::set_armor(Armor* new_armor)
{
	armor = new_armor->name();
	tgh = new_armor->tgh();
}

string Player::get_weapon()
{
	return weapon;
}

string Player::get_armor()
{
	return armor;
}

int Player::get_str()
{
	return str;
}

int Player::get_tgh()
{
	return tgh;
}