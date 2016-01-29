/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:02:32 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:02:34 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>
#include <Enemy.class.hpp>

Enemy::Enemy ( void ) : EntityAggressive(), _name("void")
{
	int			i = 0;

	while (i < MAX_BULLETS)
		this->_bullets[i++] = NULL;
	_hp = 50;
	_speed = -5;
	_patern = Patern("8");
	_score_pts = 1;
	_can_shoot = false;
	setX(WIN_WIDTH - 1);
	setY((rand() % WIN_HEIGHT ) + 1);
}

Enemy::Enemy ( int hp, int speed, bool can_shoot, int score_pts, Patern p) : EntityAggressive(), _name("void")
{
	int			i = 0;

	while (i < MAX_BULLETS)
		this->_bullets[i++] = NULL;
	_hp = hp;
	_speed = -speed;
	_patern = p;
	_score_pts = score_pts;
	_can_shoot = can_shoot;
	setX(WIN_WIDTH - 1);
	setY((rand() % WIN_HEIGHT ) + 1);
}

Enemy::Enemy ( Enemy const & src ) : EntityAggressive(src)
{
	*this = src;
}

Enemy &	Enemy::operator=( Enemy const & rhs )
{
	_speed = rhs.getSpeed();
	_damage = rhs.getDamage();
	_score_pts = rhs.getScorePoints();
	_patern = rhs.getPatern();
	return (*this);
}

std::string		Enemy::toString( void ) const
{
	std::stringstream			str;

	str << "Enemy [" << this->_name << "] HP:" << this->_hp;
	return str.str();
}

void	Enemy::toString( std::ostream & o ) const
{
	o << this->toString();
}

int		Enemy::move ( void )
{
	_x += (float)_speed / NB_FRAME;

	if (rand() % 20  == 0)
		this->shoot();

	if (_x < ( -getPatern().getSizeX()))
		return (1);
	return (0);
}

std::ostream		&operator<<(std::ostream &o, Enemy const &rhs )
{
	o << rhs.toString();
	return o;
}

Enemy::~Enemy (void) { clearAllBullets(); }
