/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 23:29:40 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/12 00:03:25 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <main.hpp>

# include <Game.class.hpp>
# include <Player.class.hpp>
# include <Enemy.class.hpp>
# include <Bullet.class.hpp>
# include <Patern.class.hpp>
# define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))


#define LOG(X)		std::cout << X << std::endl

Game *			init_game( void )
{

	int				h;
	int				w;
	std::string		name  ="Default";
	Player *		player;

	initscr();
	srand(time(NULL));
	getmaxyx(stdscr, h, w);
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	nodelay(stdscr, TRUE);
 	keypad(stdscr, TRUE);
	player = new Player(name, 5, WIN_HEIGHT / 2);
	return ( new Game(player, h , w));
}

int			comparePatern(Item * src, Item * dst)
{
	int		x;
	int		y = -1;

	Patern p1 = src->getPatern();
	Patern p2 = dst->getPatern();

	while (++y < p1.getSizeY())
	{
		x = -1;
		while (++x < p1.getSizeX())
		{
			if (src->getX() + x >= dst->getX()
					&& src->getX() + x <= dst->getX() + p2.getSizeX() - 1)
			{
				if (src->getY() + y >= dst->getY()
					&& src->getY() + y <= dst->getY() + p2.getSizeY() - 1)
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

int			comparePosition ( Item * src, Item ** dst , int limit)
{
	int			i = -1;
	int			ret = 0;

	while ( ++i < limit )
	{
		//if (dst[i] && x == dst[i]->getX() && y == dst[i]->getY() )
		if (dst[i] && comparePatern(src, dst[i]))
		{
			if ( dynamic_cast<Enemy *>(src))
				src->beHitted( dst[i]->getDamage() );
			if ( dynamic_cast<Player *>(src))
				src->beHitted( 1 );
			delete dst[i];
			dst[i] = NULL;
			ret++;
		}
	}
	return ( ret );
}

int			checkCollisions( Game * game, Enemy ** enemies, Bullet ** bullets)
{
	int			i;
	int			j;
	Player		*player = game->getPlayer();;
	Bullet **	enemiesBullets;

	i = -1;
	comparePosition((Item *)player, (Item **)enemies, MAX_ENEMY);
	while ( ++i < MAX_ENEMY)
	{
		if (enemies[i])
		{
			comparePosition((Item *)enemies[i], (Item **)bullets, MAX_BULLETS);
			if (enemies[i]->canShoot())
			{
				enemiesBullets = enemies[i]->getBullets();
				comparePosition((Item*)player, (Item **)enemiesBullets, MAX_BULLETS);
				for ( j = 0; j < MAX_BULLETS; j++)
				{
					if (enemiesBullets[j]
						&& comparePosition( (Item *)enemiesBullets[j], (Item **)bullets, MAX_BULLETS) )
						{
							delete enemiesBullets[j];
							enemiesBullets[j] = NULL;
						}
				}
			}
			if ( enemies[i]->getHp() <= 0)
			{
				game->addKill();
				player->addScore(enemies[i]->getScorePoints());
				if (dynamic_cast<Boss *>(enemies[i]))
					return (1);
				delete enemies[i];
				enemies[i] = NULL;
			}
		}
	}
	return (0);
}


int		doKeyAction( Player * player )
{
	int				key = 0;

	if ( ( key = getch()) != ERR )
	{
		if (key == 27)
			return (1);
		else if (key == KEY_UP || key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT)
			player->move(key);
		else if (key == ' ')
			player->shoot();
	}
	return (0);
}

void		endGame(int score, char * prog, char **envp, char const * str)
{
	int				key = ERR;

	clear();
	nodelay(stdscr, FALSE);
	mvwprintw(stdscr, WIN_HEIGHT / 2, WIN_WIDTH / 2 - 9 / 2, str);
	mvwprintw(stdscr, WIN_HEIGHT / 2 + 1, WIN_WIDTH / 2 - 9 / 2, "Score : %d", score);
	refresh();
	nodelay(stdscr, FALSE);
	while (key != 27)
	{
		key = getch();
		if (key == 'r')
		{
			endwin();
			execve(prog, NULL, envp);
		}
	}
	endwin();
	COUT << ENDL;
}

int			main(int UNUSED(argc), char ** argv, char **envp)
{
	Game *			game = init_game();
	int				i = -1;
	std::string		visual[] = {
		" ",
		"*",
		" ",
		"~"
	};

	while (++i < WIN_WIDTH )
	{
		game->getBg()[i].setY(0);
		game->getBg()[i].setPatern(Patern(visual[rand() % 4]));
		game->getBg2()[i].setY(WIN_HEIGHT - 1);
	}
	while ( 42 )
	{
		usleep( 1000000 / NB_FRAME );
		if ( doKeyAction(game->getPlayer()) )
			break ;
		game->popRandomEnemy();
		game->move_all();
		if (checkCollisions(game, game->getEnemies(), game->getPlayer()->getBullets()))
			endGame(game->getPlayer()->getScore(), argv[0], envp, "You Win !");
		if (game->getPlayer()->getHp() <= 0)
			break ;
		clear();
		game->display_all();
	}
	endGame(game->getPlayer()->getScore(), argv[0], envp, "You loose !");

	COUT << ENDL;
}
