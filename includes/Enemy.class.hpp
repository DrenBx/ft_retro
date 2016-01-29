/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:03:53 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:03:54 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include <iostream>
#include <sstream>

#include <EntityAggressive.class.hpp>

class Enemy : public EntityAggressive
{
	public:
		Enemy ( void );
		Enemy ( int hp, int speed, bool can_shoot, int score_pts, Patern p );
		Enemy ( Enemy const & src );
		~Enemy (void);
		Enemy &	operator=( Enemy const & rhs );

		std::string		toString ( void ) const;
		void			toString ( std::ostream & ) const;
		//void			display ( WINDOW *win );
		int				move ( void );

	private:
		std::string				_name;
};

std::ostream		&operator<<(std::ostream &o, Enemy const &rhs );

#endif  /* ENEMY_CLASS_HPP */
