/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:02:45 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:02:47 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Game.class.hpp>

Game::Game ( void )
{
	return ;
}

Game::Game ( Game const & src )
{
	*this = src;
	return ;
}

Game::~Game (void)
{
	return ;
}

Game::Game (Player *p, int h, int w) :
	_player(p),
	_height(h),
	_width(w),
	_kills(0),
	_boss(false)
{
	int			i = 0;

	while (i < MAX_ENEMY)
		_enemies[i++] = NULL;
	return ;
}


void		Game::addKill( void )
{
	_kills++;
}

bool		Game::bossApear ( void ) const
{
	if (_kills > KILL_TO_BOSS)
		return (true);
	return (false);
}

Game &	Game::operator=( Game const & rhs )
{

	(void)rhs;
	return *this;
}

Player *		Game::getPlayer( void )
{
	return (this->_player);
}

Enemy **		Game::getEnemies ( void )
{
	return this->_enemies;
}

std::string		Game::toString( void ) const
{
	std::stringstream			str;

	str << "Empty toString function";
	return str.str();
}

void		Game::toString( std::ostream & o ) const
{
	o << this->toString();
}

std::ostream		&operator<<(std::ostream &o, Game const &rhs )
{
	o << rhs.toString();
	return o;
}

Background *		Game::getBg ( void ) const{
	return (Background *)_background;
}
Background *		Game::getBg2 ( void ) const {
	return (Background *)_background2;
}

void				Game::displayBullets(Bullet **bullets)
{
	int		i = -1;

	if (bullets)
		while (++i < MAX_BULLETS)
			if (bullets[i])
				bullets[i]->display();
}

void				Game::display_all (void)
{
	int				i = -1;

	while (++i < WIN_WIDTH)
	{
		_background[i].display();
		_background2[i].display();
	}

	i = -1;
	while ( ++i < MAX_ENEMY )
	{
		if (this->_enemies[i])
		{
			displayBullets(_enemies[i]->getBullets());
			this->_enemies[i]->display();
		}
	}
	displayBullets(_player->getBullets());
	this->_player->display();
	mvwprintw(stdscr, WIN_HEIGHT , 0, "Score: %d", _player->getScore());
	_player->displayLife();
}

void					Game::popRandomEnemy ( void )
{
	int				i = -1;
	int				rand_hp;
	int				rand_speed;
	int				can_shoot;
	std::string		visual;

	if (bossApear() && !_boss)
	{
		while (++i < MAX_ENEMY && this->_enemies[i] != NULL);
		if (i < MAX_ENEMY)
		{
			_enemies[i] = new Boss();
			_boss = true;
		}
	}
	else if (rand() % 100 == 0 && !_boss)
	{
		while (i < MAX_ENEMY && this->_enemies[i] != NULL)
			i++;
		if ( i < MAX_ENEMY )
		{
			rand_hp = 10 + (rand() % 100);
			rand_speed = 10 + (rand() % 15);
			can_shoot = rand_speed <= 5 ? 1 : 0;
			visual = rand_speed <= 5 ? "<[-o-]>" : "{-o-}";
			visual = rand() % 5 == 0 ? "(-o-)" : visual;
			if ( rand() % 42 == 0)
			{
				this->_enemies[i] = new Enemy(1000, 6, 1, 10, std::string("d|__|.\n |  |"));
				_enemies[i]->setY(WIN_WIDTH);
			}
			else
			{
				this->_enemies[i] = new Enemy(rand_hp, rand_speed, can_shoot, 1, visual);
				_enemies[i]->setY(_enemies[i]->getY() - 2);
			}
		}
	}
	if (rand() % (1000 / ((_boss * 10) + 1)) == 0)
	{
		i = -1;
		while (++i < MAX_ENEMY && this->_enemies[i] != NULL);
		if (i >= MAX_ENEMY) return ;
		this->_enemies[i] = new Enemy(1000000, 5, 0, 0, std::string("  ##  \n######\n  ##  "));
	}
	return ;
}

void				Game::moveBullets(Bullet **bullets)
{
	int		i = -1;

	if (bullets)
		while (++i < MAX_BULLETS)
			if ( bullets[i] && bullets[i]->move())
			{
				delete bullets[i];
				bullets[i] = NULL;
			}
}

void				Game::move_all ( void )
{
	int				i = -1;

	while (++i < WIN_WIDTH)
	{
		_background[i].move();
		_background2[i].move();
	}

	i = -1;
	while (++i < MAX_ENEMY )
	{
		if ( this->_enemies[i] )
		{
			moveBullets(_enemies[i]->getBullets());
			if (this->_enemies[i]->move())
			{
				getPlayer()->addScore(-(_enemies[i]->getScorePoints()));
				delete this->_enemies[i];
				this->_enemies[i] = NULL;
			}
		}
	}
	moveBullets(_player->getBullets());
}
