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

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = util.c
SRCS_SERVER = $(SERVER).c
SRCS_CLIENT = $(CLIENT).c
OBJS = $(SRCS:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

LIBFT = libft
LIBFT_FLAGS = -L $(LIBFT) -lft
INC_FLAGS = -I includes -I $(LIBFT)

green:=$(shell tput setaf 2)
reset:=$(shell tput sgr0)

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@make --silent --directory=$(LIBFT)

$(SERVER): $(OBJS_SERVER) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS_SERVER) $(OBJS) $(LIBFT_FLAGS)
	$(info $(green)<MAKE> SERVER$(reset))

$(CLIENT): $(OBJS_CLIENT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS_CLIENT) $(OBJS) $(LIBFT_FLAGS)
	$(info $(green)<MAKE> CLIENT$(reset))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)
	$(info $(green)<MAKE> $(<) -> $(@)$(reset))

clean:
	@make clean --silent --directory=$(LIBFT)
	$(info $(green)<MAKE> Libft - clean$(reset))
	@rm -f $(OBJS) $(OBJS_SERVER) $(OBJS_CLIENT)
	$(info $(green)<MAKE> clean$(reset))

fclean: clean
	@make fclean --silent --directory=$(LIBFT)
	$(info $(green)<MAKE> Libft - fclean$(reset))
	@rm -f $(SERVER) $(CLIENT)
	$(info $(green)<MAKE> fclean$(reset))

re: fclean all
	$(info $(red)<MAKE> re$(reset))

.PHONY: all clean fclean re $(LIBFT)
