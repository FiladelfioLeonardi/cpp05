# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 11:21:02 by fefo              #+#    #+#              #
#    Updated: 2026/08/14 09:51:01 by fefo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Tester
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRCS =	main.cpp \
		common.cpp

INCLUDES = -I ../../ex01 -I .

 
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ $^

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re