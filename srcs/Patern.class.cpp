/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patern.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:03:02 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:03:03 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Patern.class.hpp>

Patern::Patern() {
	_sizeX = 1;
	_sizeY = 1;
	_str = "#";
}

Patern::Patern(std::string p) {
	changePatern(p);
}

Patern::Patern(Patern const & src) {
	*this = src;
}

Patern&	Patern::operator=(Patern const & rhs) {
	//changePatern(rhs._str);
	_sizeX = rhs.getSizeX();
	_sizeY = rhs.getSizeY();
	_str = rhs._str;
	return (*this);
}

void	Patern::display( int posX, int posY)
{
	int				i = -1, j = 0;
	int				len = _str.size();
	std::string		tmp_str;
	while (++i < len)
	{
		if (_str[i] == '\n' && _str[i + 1])
		{
			mvwprintw(stdscr, posY + j, posX, tmp_str.c_str());
			tmp_str = std::string();
			j++;
		}
		else
			tmp_str.append(1, _str[i]);
	}
	mvwprintw(stdscr, posY + j, posX, tmp_str.c_str());
}

void	Patern::changePatern(std::string p)
{
	int		i = -1;
	int		len = p.size();
	int		count_y = 1;
	int		count_x = 0;
	int		count_tmp = 0;
	
	while (++i < len)
	{
		if (p[i] == '\n' && p[i + 1])
		{
			count_y++;
			count_x = count_x < count_tmp ? count_tmp : count_x;
			count_tmp = 0;
		}
		else
			count_tmp++;
	}
	_str = p;
	_sizeY = count_y;
	_sizeX = count_x < count_tmp ? count_tmp : count_x;
}

int		Patern::getSizeX() const { return(_sizeX); }
int		Patern::getSizeY() const { return(_sizeY); }

Patern::~Patern() {
}
