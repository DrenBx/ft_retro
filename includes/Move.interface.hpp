/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.interface.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:04:20 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:04:21 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_INTERFACE_HPP
# define MOVE_INTERFACE_HPP

#include <iostream>
#include <sstream>

class Move
{
	public:


	protected:
		virtual void	_display ( void ) = 0;
	private:
		
};

#endif  /* MOVE_INTERFACE_HPP */
