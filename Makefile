# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/18 11:32:11 by rbernand          #+#    #+#              #
#    Updated: 2015/01/11 22:11:00 by rbernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_retro
HEADER=includes/
FLAGS=-Wall -Wextra -Werror -lncurses -g
DIRSRC=srcs/
DIROBJ=objs/
INCLUDES=includes/
SRCS=main.cpp \
	 Item.class.cpp \
	 Player.class.cpp \
	 Game.class.cpp \
	 Enemy.class.cpp \
	 Bullet.class.cpp \
	 Background.class.cpp \
	 EntityAggressive.class.cpp \
	 Patern.class.cpp \
	 Boss.class.cpp

OBJS=$(SRCS:%.cpp=$(DIROBJ)%.o)
CC=g++

all: init $(NAME) end

init:
	@tput init
end:
	@echo "\033[2K\t\033[1;36m$(NAME)\t\t\033[0;32m[ready]\033[0m"

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(FLAGS) $^ 

$(DIROBJ)%.o: $(DIRSRC)%.cpp $(INCLUDES)%.hpp
	$(CC) -o $@ $(FLAGS) -c $< -I$(INCLUDES)

$(DIROBJ)%.o: $(DIRSRC)%.cpp
	$(CC) -o $@ $(FLAGS) -c $< -I$(INCLUDES)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
