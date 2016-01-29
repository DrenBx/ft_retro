/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:03:47 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:03:48 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP

#include <Item.class.hpp>

class Bullet : public Item
{
	public:
		Bullet( void );
		Bullet( int x, int y);
		Bullet(int x, int y, int speed, int damage, Item::e_color c);
		Bullet(int x, int y, int speed, int damage, Item::e_color c, char const *);
		Bullet( Bullet const & src );
		~Bullet(void);
		Bullet		&operator=( Bullet const & rhs );

		int			move ( void );
		void			display ( void );

	private:
		e_color			_color;
		static unsigned int		_index;
};

std::ostream		&operator<<(std::ostream &o, Bullet const &rhs );

#endif  /* ITEM_CLASS_HPP */
