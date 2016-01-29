/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:04:29 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:04:31 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Patern_HPP
# define Patern_HPP

# include <string>
# include <main.hpp>

class Patern
{

	public:
		Patern( void );
		Patern( std::string str);
		Patern( Patern const & src );
		~Patern( void );

		Patern&		operator=( Patern const & rhs );

		int			getSizeX( void ) const;
		int			getSizeY( void ) const;
		void		changePatern( std::string p );

		void		display( int const posX, int const posY);

	private:
		int			_sizeX;
		int			_sizeY;
		std::string	_str;

};

#endif
