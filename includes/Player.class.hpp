/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:04:44 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:04:45 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

#include <iostream>
#include <sstream>
#include <ncurses.h>
#include <strings.h>
#include <main.hpp>

#include <EntityAggressive.class.hpp>

class Player : public EntityAggressive
{
	public:
		Player ( void );
		Player ( Player const & src );
		~Player (void);
		Player ( std::string, int x, int y);
		Player &	operator=( Player const & rhs );

		unsigned int	getScore ( void ) const ;
		
		void			setX(int x);

		void			addScore(int n);

		std::string		toString ( void ) const;
		void			toString ( std::ostream & ) const;
		void			move ( int key );
		void			shoot ( void );
		void			display( void );
		void			displayLife( void );

	private:
		std::string			_name;
		int					_score;
		unsigned int		_score_multiplier;

};

std::ostream		&operator<<(std::ostream &o, Player const &rhs );

#endif  /* PLAYER_CLASS_HPP */
