# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 15:33:41 by wfan              #+#    #+#              #
#    Updated: 2023/06/02 15:33:44 by wfan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

green:=$(shell tput setaf 2)
reset:=$(shell tput sgr0)


all: server client

bonus: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft
	$(info $(green)<MAKE> SERVER$(reset))

client: client.o
	$(CC) -o $@ $< -Llibft -lft
	$(info $(green)<MAKE> CLIENT$(reset))

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	$(info $(green)<MAKE> clean$(reset))
	make -C libft clean
	$(info $(green)<MAKE> Libft - clean$(reset))
	
fclean: clean
	rm -f server client libft/libft.a
	$(info $(green)<MAKE> fclean$(reset))
	$(info $(green)<MAKE> Libft - fclean$(reset))

re: fclean all
	$(info $(green)<MAKE> re$(reset))

.PHONY: all bonus libft clean fclean re