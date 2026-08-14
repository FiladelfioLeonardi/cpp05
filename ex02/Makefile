# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 11:21:02 by fefo              #+#    #+#              #
#    Updated: 2026/05/27 22:16:39 by fefo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		AForm.cpp \
		../Tester/ex02/Tester.cpp \
		../Tester/common.cpp \
		ShrubberyCreationForm.cpp 
		
HEADERS = Bureaucrat.hpp

LIB = -I .
 
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(LIB) -o $@ $^

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re