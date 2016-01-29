/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:04:50 by fkalb             #+#    #+#             */
/*   Updated: 2015/01/12 00:04:51 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <sstream>
# include <ncurses.h>
# include <stdlib.h>

# include <unistd.h>

# define			NB_FRAME		120
# define			WIN_WIDTH		120
# define			WIN_HEIGHT		25


#define MAX_ENEMY		50
#define MAX_BULLETS		100

#define KILL_TO_BOSS	5
#define BOSS_LIFE		1000


# define			COUT std::cout
# define			ENDL std::endl


#endif  /* MAIN_HPP */
