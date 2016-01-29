/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:03:33 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:03:34 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_CLASS_HPP
# define BACKGROUND_CLASS_HPP

#include <Item.class.hpp>
#include <main.hpp>

class Background : public Item
{
	public:
		Background( void );
		Background( Background const & src );
		~Background(void);
		Background		&operator=( Background const & rhs );

		int		move( void );
		void	display ( void );
		void	setY( int n);

	private:
		static unsigned int		_index;
		static unsigned int		_default_x;
};

std::ostream		&operator<<(std::ostream &o, Background const &rhs );

#endif  /* BACKGROUND_CLASS_HPP */
