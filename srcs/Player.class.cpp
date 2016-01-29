/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:03:18 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:03:20 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Player.class.hpp>

Player::Player ( void ) : EntityAggressive()
{
	setShootAbility(1);
	this->_patern = Patern(">>");
}

Player::Player ( Player const & src ) : EntityAggressive()
{
	setShootAbility(1);
	this->_patern = Patern(">>");
	*this = src;
}

Player::Player ( std::string name, int x, int y) : EntityAggressive(x, y), _name(name)
{
	this->_hp = 3;
	this->_patern = Patern(">>");
}

Player &	Player::operator=( Player const & rhs )
{
	_speed = rhs.getSpeed();
	_damage = rhs.getDamage();
	return *this;
}

std::string		Player::toString( void ) const
{
	std::stringstream			str;

	str << "Empty toString function";
	return str.str();
}

void		Player::toString( std::ostream & o ) const
{
	o << this->toString();
}

std::ostream		&operator<<(std::ostream &o, Player const &rhs )
{
	o << rhs.toString();
	return o;
}

/* GETTER */
unsigned int	Player::getScore() const { return (_score); }
/* END GETTER */

/* SETTER */
void			Player::setX(int x) {

	_x = x;

	if (_x > (WIN_WIDTH / 2) )
		_x = WIN_WIDTH / 2;
	else if ( _x < 0 )
		_x = 0;
	//_x = x <= 0 ? 0 : ( x >= (WIN_WIDTH - getPatern().getSizeX()) ? (WIN_WIDTH - getPatern().getSizeX()) : x); 
}

void			Player::addScore(int s) {
	_score = (_score + s) <= 0 ? 0 : _score + s;
}
/* END SETTER */

void			Player::move (int key)
{
	switch (key)
	{
		case KEY_UP:
			setY(_y - 1);
			break ;
		case KEY_DOWN:
			setY(_y + 1);
			break ;
		case KEY_RIGHT:
			setX(_x + 1);
			break ;
		case KEY_LEFT:
			setX(_x - 1);
			break ;
	}
}

void		Player::display( void )
{
	//mvwaddch(stdscr, (int)_y, (int)_x, _visual);
	getPatern().display(getX(), getY());
}

void			Player::shoot()
{
	int			i = 0;
	int				bullets_value;
	static std::string		visual[] = {
		".",
		"-",
		"~",
		":",
		"=",
		"=>",
		"|",
		"SEGV"
	};

	while (i < MAX_BULLETS && this->_bullets[i])
		i++;
	if (i == MAX_BULLETS )
		return ;
	bullets_value = _score / 6;
	bullets_value = bullets_value > 7 ? 7 : bullets_value;
	this->_bullets[i] = new Bullet(_x + 2, _y, 32, 10 * (bullets_value + 1), _green, (visual[bullets_value]).c_str());
}

void			Player::displayLife ( void )
{
	attron(COLOR_PAIR(3));
	mvwprintw(stdscr, WIN_HEIGHT, WIN_WIDTH - _hp, std::string(_hp, '*').c_str());
	attroff(COLOR_PAIR(3));
}

Player::~Player() { clearAllBullets(); } 
