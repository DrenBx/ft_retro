/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityAggressive.class.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:04:00 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:04:01 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_AGGRESSIVE_CLASS_HPP
# define ENTITY_AGGRESSIVE_CLASS_HPP

#include <Item.class.hpp>
#include <Bullet.class.hpp>

class EntityAggressive : public Item
{
	public:
		EntityAggressive ( void );
		EntityAggressive ( int x, int y);
		EntityAggressive (int x, int y, int speed, int damage);
		EntityAggressive ( EntityAggressive const & src );
		virtual ~EntityAggressive (void);
		EntityAggressive &	operator=( EntityAggressive const & rhs );

		Bullet **		getBullets ( void ) const ;
		//Bullet *		getBullet ( int n ) const ;
		bool 			canShoot ( void ) const ;
		void			setShootAbility ( bool b );
		
		virtual void	shoot ( void );
		void			clearAllBullets( void );
	protected:
		bool			_can_shoot;
		Bullet			*_bullets[MAX_BULLETS];
	
	private:
		static unsigned int		_index;

};

std::ostream		&operator<<(std::ostream &o, EntityAggressive const &rhs );

#endif  /* ENTITY_AGGRESSIVE_CLASS_HPP */
