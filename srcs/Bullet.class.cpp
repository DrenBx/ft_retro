/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:02:25 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:02:26 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bullet.class.hpp>

Bullet::Bullet () :
	Item(0, 0, 0, 10)
{
	this->_patern = Patern("-");
}

Bullet::Bullet (int x, int y) :
	Item(x, y, 0, 10)
{
	this->_patern = Patern("-");
}

Bullet::Bullet (int x, int y, int speed, int damage, e_color c) :
	Item(x, y, speed, damage),
	_color(c)
{
	this->_patern = Patern("-");
}

Bullet::Bullet (int x, int y, int speed, int damage, e_color c, char const *visual) :
	Item(x, y, speed, damage),
	_color(c)
{
	this->_patern = Patern(visual);
}

Bullet::Bullet ( Bullet const & src ) : Item(src)
{
	*this = src;
}

void		Bullet::display ( void )
{
	attron(COLOR_PAIR(this->_color));
	//mvwaddch(stdscr, (int)this->_y, (int)this->_x, this->_visual);
	getPatern().display(getX(), getY());
	attroff(COLOR_PAIR(this->_color));
}

int			Bullet::move ( void )
{
	this->_x += ((float)this->_speed / NB_FRAME);

	if (this->_x < 0)
		return (1);
	else if (this->_x > WIN_WIDTH - 1)
		return (1);
	return (0);
}

Bullet &	Bullet::operator=( Bullet const & rhs )
{
	_speed = rhs.getSpeed();
	_damage = rhs.getDamage();
	return (*this);
}

std::ostream		&operator<<(std::ostream &o, Bullet const &rhs )
{
	o << rhs.toString();
	return (o);
}

Bullet::~Bullet (void) {}

unsigned int			 Bullet::_index = 0;
