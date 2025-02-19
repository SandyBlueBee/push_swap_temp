# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syukna <syukna@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 16:06:24 by syukna            #+#    #+#              #
#    Updated: 2025/02/19 12:29:25 by syukna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Werror -Wextra
FILES = push_swap.c error.c dll_init.c dll_switch.c dll_rotate.c dll_check.c dll_sort.c dll_push.c send_back.c \
		send_forward.c score.c
OBJ = ${FILES:.c=.o}
HEADER = push_swap.h 

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a 

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f ${OBJ}

fclean: clean
	make -C libft fclean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re