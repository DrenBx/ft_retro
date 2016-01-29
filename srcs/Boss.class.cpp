/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 22:05:15 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/11 23:36:26 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Boss.class.hpp>

Boss::Boss ( void ) : Enemy()
{
	char *buffer = new char [662];
	std::ifstream		pat("misc/boss.txt");
	
	pat.read(buffer, 662);
	_patern = Patern(buffer);
	_speed = -50;
	setY((WIN_HEIGHT / 2));
	_x = (WIN_WIDTH);
	_hp = BOSS_LIFE;
	_can_shoot = true;
	return ;
}

Boss::Boss ( Boss const & src ) : Enemy(src)
{
	*this = src;
	return ;
}

Boss::~Boss (void)
{
	return ;
}

int				Boss::move( void )
{
	if ( _x <= WIN_WIDTH / 2 )
	{
		if (rand() % (NB_FRAME / 3) == 0)
			this->shoot();
		_speed = 0;
		return (0);
	}
	else
	{
		_x += (float)_speed / NB_FRAME;
		return (0);
	}
}

void			Boss::shoot ( void )
{
	static void (Boss::*atk[])(void) = {
		&Boss::_shoot1,
		&Boss::_shoot2,
		&Boss::_shoot3
	};
	int				val = rand() % 100;

	if (val < 50)
		val = 0;
	else if (val < 80)
		val = 1;
	else
		val = 2;
	CALL_MEMBER_FN(this, atk[val])();
	return;
}

void			Boss::_shoot1 ( void )
{
	int			i = -1;
	int			dec = rand() % 4;

	while ( ++i < MAX_BULLETS && _bullets[i]);
	if ( i >= MAX_BULLETS ) return;
	_bullets[i] = new Bullet(_x, _y + 2 + dec, -20, 1, _red, std::string("======").c_str());
	while ( ++i < MAX_BULLETS && _bullets[i]);
	if ( i >= MAX_BULLETS ) return;
	_bullets[i] = new Bullet(_x, _y + 6 + dec, -20, 1, _red, std::string("======").c_str());
	while ( ++i < MAX_BULLETS && _bullets[i]);
	if ( i >= MAX_BULLETS ) return;
	_bullets[i] = new Bullet(_x , _y + 10 + dec, -20, 1, _red, std::string("======").c_str());
	while ( ++i < MAX_BULLETS && _bullets[i]);
	if ( i >= MAX_BULLETS ) return;
	_bullets[i] = new Bullet(_x , _y + 14 + dec, -20, 1, _red, std::string("======").c_str());
}
void			Boss::_shoot2 ( void )
{
	int			i = -1;
	int			dec = rand() % 7;

	while ( ++i < MAX_BULLETS && _bullets[i]);
	if ( i >= MAX_BULLETS ) return;
	_bullets[i] = new Bullet(_x , _y + dec, -10, 1, _yellow, std::string("|\n|\n|\n|").c_str());
}


void			Boss::_shoot3 ( void )
{
	int			i = -1;

	while ( ++i < MAX_BULLETS && _bullets[i]);
	if ( i >= MAX_BULLETS ) return;
	_bullets[i] = new Bullet(_x , WIN_HEIGHT - 5, -50, 1, _magenta, std::string("   //\n _//\n(')---.\n_/-_(.)o\n").c_str());

}

Boss &	Boss::operator=( Boss const & rhs )
{

	(void)rhs;
	return *this;
}

std::string		Boss::toString( void ) const
{
	std::stringstream			str;

	str << "Empty toString function";
	return str.str();
}

void		Boss::toString( std::ostream & o ) const
{
	o << this->toString();
}

std::ostream		&operator<<(std::ostream &o, Boss const &rhs )
{
	o << rhs.toString();
	return o;
}

/*
** ACESSORS
*/

