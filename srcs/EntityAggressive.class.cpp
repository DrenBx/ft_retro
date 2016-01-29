/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityAggressive.class.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:02:39 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:02:40 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EntityAggressive.class.hpp>

EntityAggressive::EntityAggressive ()
{
	setX(0);
	setY(0);
}

EntityAggressive::EntityAggressive (int x, int y) : Item(x, y)
{
	setX(x);
	setY(y);
}

EntityAggressive::EntityAggressive (int x, int y, int speed, int damage) : Item(x, y, speed, damage)
{
	setX(x);
	setY(y);
}

EntityAggressive::EntityAggressive ( EntityAggressive const & src ) :
	Item(src)
{
	*this = src;
}

EntityAggressive &	EntityAggressive::operator=( EntityAggressive const & rhs )
{
	
	this->_speed = rhs.getSpeed();
	this->_damage = rhs.getDamage();
	this->_score_pts = rhs.getScorePoints();
	this->_patern = rhs.getPatern();
	return (*this);
}

std::ostream		&operator<<(std::ostream &o, EntityAggressive const &rhs )
{
	o << rhs.toString();
	return o;
}

Bullet **	EntityAggressive::getBullets () const { return ((Bullet **)this->_bullets); }
bool		EntityAggressive::canShoot() const { return (_can_shoot); }

void		EntityAggressive::setShootAbility ( bool b ) { _can_shoot = b; }

void	EntityAggressive::shoot( void )
{
	int			i = 0;
	int			shoot_speed = getSpeed() < 0 ? -20 : 20;
	int			shootDir = getSpeed() == 0 ? 1 : -1;

	if (!canShoot())
		return ;

	while (i < MAX_BULLETS && this->_bullets[i])
		i++;
	if (i == MAX_BULLETS )
		return ;
	this->_bullets[i] = new Bullet(_x +  shootDir, _y, shoot_speed, 10, _red);
}

void		EntityAggressive::clearAllBullets()
{
	for (int i = 0; i < MAX_BULLETS; ++i)
	{
		if (_bullets[i] == NULL) {
			delete _bullets[i];
			_bullets[i] = NULL;
		}
	}
}

EntityAggressive::~EntityAggressive (void) { clearAllBullets(); }


unsigned int			 EntityAggressive::_index = 0;
