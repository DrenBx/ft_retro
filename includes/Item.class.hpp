/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:04:13 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:04:14 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_CLASS_HPP
# define ITEM_CLASS_HPP

#include <iostream>
#include <sstream>
#include <ncurses.h>

#include <main.hpp>
#include <Patern.class.hpp>
#include <Move.interface.hpp>


class Item
{
	public:
		Item ( void );
		Item ( int x, int y);
		Item (int x, int y, int speed, int damage);
		Item ( Item const & src );
		virtual ~Item (void);
		Item &	operator=( Item const & rhs );

		std::string		toString ( void ) const;
		void			toString ( std::ostream & ) const;

		int				getSpeed() const;
		int				getDamage() const;
		int				getX ( void ) const;
		int				getY ( void ) const;
		int				getHp ( void ) const ;
		
		Patern			getPatern ( void ) const;
		//Patern const &	getPatern ( void ) const;
		
		void			setPatern(Patern p);
		void			setSpeed(int speed);
		int				getScorePoints() const;
		virtual void	setX ( int x );
		void			setY ( int y );
	
		int				beHitted( int n);

		virtual void	display ( void );
		virtual int		move ( void );

		enum e_color 
		{
			_red = 1, _green, _yellow, _magenta, _cyan
		};

	private:
		static unsigned int		_index;

	protected:
		unsigned int	_id;
		int				_hp;
		float			_x;
		float			_y;
		int				_sizeX;
		int				_sizeY;
		int				_speed;
		Patern			_patern;
		int				_score_pts;
		int				_damage;
};


std::ostream		&operator<<(std::ostream &o, Item const &rhs );

#endif  /* ITEM_CLASS_HPP */
