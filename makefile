# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohan <yohan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 15:01:53 by yohan             #+#    #+#              #
#    Updated: 2023/12/09 15:01:54 by yohan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getlineft.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

SRC = get_next_line_utils\

all: $(NAME)

$(NAME): $(SRC: = .o)
			ar rc $(NAME) $(SRC: = .o)
clean:
	$(RM)	$(SRC : .o)
fclean: clean
		$(RM)	$(NAME)
re: fclean $(NAME)
