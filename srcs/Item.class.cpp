/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:02:53 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:02:56 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Item.class.hpp>

Item::Item () : _id(Item::_index++), _speed(0), _patern(Patern("#")), _damage(10)
{
	setX(0);
	setY(0);
}

Item::Item (int x, int y) : _id(Item::_index++), _speed(0), _patern(Patern("#")), _damage(10)
{
	setX(x);
	setY(y);
}

Item::Item (int x, int y, int speed, int damage) : _id(Item::_index++), _speed(speed), _patern(Patern("#")), _damage(damage)
{
	setX(x);
	setY(y);
}

Item::Item ( Item const & src )
{
	*this = src;
}

Item &	Item::operator=( Item const & rhs )
{
	this->_speed = rhs.getSpeed();
	this->_damage = rhs.getDamage();
	this->_score_pts = rhs.getScorePoints();
	return (*this);
}

void			Item::setPatern ( Patern p )
{
	_patern = p;
}

std::string		Item::toString() const
{
	std::stringstream	str;

	str << "Item [" << _id << "]";
	return str.str();
}

void		Item::toString( std::ostream & o ) const
{
	o << toString();
}

std::ostream		&operator<<(std::ostream &o, Item const &rhs )
{
	o << rhs.toString();
	return o;
}


/* ACESSORS */

Patern			Item::getPatern ( void ) const { return ( _patern ); }
//Patern const &	Item::getPatern ( void ) const { return ( _patern ); }
int				Item::getX ( void ) const { return ( _x ); }
int				Item::getY ( void ) const { return ( _y ); }
int				Item::getSpeed() const { return (_speed); }
int				Item::getDamage() const { return (_damage); }
int				Item::getScorePoints() const { return (_score_pts); }
int				Item::beHitted( int n) {
	this->_hp -= n;
	return (this->_hp <= 0 ? 1 : 0);
}

int			Item::getHp ( void ) const
{
	return this->_hp;
}

void	Item::setSpeed(int speed) { _speed = speed; }
void	Item::setX(int x) { _x = x; }

void	Item::setY(int y)
{
	_y = y <= 0 ? 1 : (y >= (WIN_HEIGHT - 1 - getPatern().getSizeY()) ? (WIN_HEIGHT - 1 - getPatern().getSizeY()) : y);
}

/* END ACESSOR */


void	Item::display ( void )
{
//	mvwaddch(stdscr, (int)this->_y, (int)this->_x, this->_visual);
	getPatern().display(getX(), getY());
}

int		Item::move ( void )
{
	_x += (float)_speed / NB_FRAME;

	if (_x < (1 - getPatern().getSizeX()) || _x > (WIN_WIDTH - 1 + getPatern().getSizeX()))
		return (1);
	return (0);
}

Item::~Item (void) {}

unsigned int			 Item::_index = 0;
