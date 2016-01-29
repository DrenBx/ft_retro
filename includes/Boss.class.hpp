/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 22:05:15 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/12 00:03:40 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_CLASS_HPP
# define BOSS_CLASS_HPP

#include <iostream>
#include <sstream>
#include <Enemy.class.hpp>
#include <Patern.class.hpp>
#include <Bullet.class.hpp>
#include <main.hpp>
#include <fstream>
# define CALL_MEMBER_FN(obj, ptr) ((obj)->*(ptr))

class Boss : public Enemy
{
	public:
		Boss ( void );
		Boss ( Boss const & src );
		~Boss (void);
		Boss &	operator=( Boss const & rhs );

		std::string		toString ( void ) const;
		void			toString ( std::ostream & ) const;

		int				move ( void );
		void			shoot ( void );
	private:
		void			_shoot1 (void );
		void			_shoot2 (void );
		void			_shoot3 (void );
};

std::ostream		&operator<<(std::ostream &o, Boss const &rhs );

#endif  /* BOSS_CLASS_HPP */
