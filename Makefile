# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/29 13:45:56 by Youssef           #+#    #+#              #
#    Updated: 2022/06/05 21:37:41 by Youssef          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g

LFLAGS	=	-I includes

LIBFT       =	./libft.a

NAME_SRV	=	server

NAME_CL 	=	client

NAME_LIBFT	=	libft.a

all: $(NAME_LIBFT) $(NAME_SRV) $(NAME_CL)

$(NAME_LIBFT): 
	@make -C ./Libft
	@cp ./Libft/libft.a ./
	@echo "Making Libft..."

$(NAME_SRV) : server.o
	@$(CC) server.o $(CFLAGS) -o $(NAME_SRV) $(NAME_LIBFT)
	@echo "Making server..."


$(NAME_CL) : client.o
	@$(CC) client.o $(CFLAGS) -o $(NAME_CL) $(NAME_LIBFT)
	@echo "Making client..."

clean:
	@rm -f ./libft.a server.o client.o
	@make -C ./Libft clean
	@echo "Clean(libft)"
	@echo "Clean(server)"
	@echo "Clean(client)"

fclean: clean
	@rm -f $(NAME_SRV) $(NAME_CL)
	@make -C ./Libft fclean
	@echo "Fclean(libft)"
	@echo "Fclean(SRV and CL)"

re : fclean all

.PHONY: all fclean clean re $(EXEC)
