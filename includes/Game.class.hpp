/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:04:07 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:04:08 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

#include <iostream>
#include <sstream>

#include <Player.class.hpp>
#include <Boss.class.hpp>
#include <Enemy.class.hpp>
#include <Background.class.hpp>
#include <ncurses.h>

#include <main.hpp>
#include <stdlib.h>

class Game
{
	public:
		Game ( void );
		Game ( Game const & src );
		Game ( Player * p, int x, int y);
		~Game (void);
		Game &	operator=( Game const & rhs );

		Player *		getPlayer( void );
		Enemy **		getEnemies ( void );

		std::string		toString ( void ) const;
		void			toString ( std::ostream & ) const;

		Background *	getBg ( void) const;
		Background *	getBg2 ( void) const;
		void			move_all ( void );
		void			moveBullets ( Bullet **bullets );
		void			display_all ( void );
		void			displayBullets ( Bullet **bullets );
		void			popRandomEnemy ( void );
		void			addKill(void);
		bool			bossApear ( void ) const;

	private:
		Enemy		*_enemies[MAX_ENEMY];
		Background	_background[WIN_WIDTH];
		Background	_background2[WIN_WIDTH];
		Player		*_player;
		int			_height;
		int			_width;
		int			_kills;
		bool		_boss;

	private:
		static const unsigned int		_maxEnemy;
};

//const unsigned int			Game::_maxEnemy = 12;




std::ostream		&operator<<(std::ostream &o, Game const &rhs );

#endif  /* GAME_CLASS_HPP */
