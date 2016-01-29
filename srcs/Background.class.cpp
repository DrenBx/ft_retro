/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:02:12 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:02:13 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Background.class.hpp>

Background::Background()
{
	std::string		visual;
	_speed = -(10);
	_damage = 0;
	_hp = 1000000;
	_x = Background::_default_x++ % WIN_WIDTH;
	visual = (int)_x % 10 == 9 ? '@' : '=';
	_patern = Patern(visual);
}

Background::Background( Background const & src ) : Item(src)
{
	*this = src;
}

Background &	Background::operator=( Background const & rhs )
{
	_speed = rhs.getSpeed();
	_damage = rhs.getDamage();
	_patern = rhs.getPatern();
	return (*this);
}

std::ostream		&operator<<(std::ostream &o, Background const &rhs )
{
	o << rhs.toString();
	return (o);
}

void			Background::setY( int n)
{
	_y = n;
}

int		Background::move()
{
	_x += (float)_speed / NB_FRAME;
	
	_x = _x < 0 ? WIN_WIDTH : _x;
	return (0);
}

void	Background::display ( void)
{
	getPatern().display(getX(), getY());
	//mvwaddch(stdscr, 0, (int)_x, _visual);
	//mvwaddch(stdscr, WIN_HEIGHT - 1, (int)_x, _visual);
}

Background::~Background (void) {}

unsigned int	Background::_index = 0;
unsigned int	Background::_default_x = 0;
