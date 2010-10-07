#include "monster.h"
#include <cstdlib>

using namespace std;

Monster::Monster(string name) : MovingObject(name), m_health(10)
{ }

Monster::Monster(string name, int x, int y) : MovingObject(name, x, y), m_health(10)
{ }

void Monster::update()
{
	int rand = random() % 5;
	switch(rand) {
		case 0:
			move_up();
		break;
		case 1:
			move_left();
		break;
		case 2:
			move_down();
		break;
		case 3:
			move_right();
		break;
		//One out of every five times or so, just let the monster sit where it is.
	}
}

int Monster::health() const
{
	return m_health;
}

bool Monster::hurt_monster(const int damage)
{
	if (damage > m_health) {
		m_health = 0;
		return false;
	}
	m_health -= damage;
	return true;
}

void Monster::heal_monster(const int healing)
{
	m_health += healing;
	if (m_health > 100)
		m_health = 100;
}
