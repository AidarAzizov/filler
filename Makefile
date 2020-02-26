# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asusan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 15:33:11 by asusan            #+#    #+#              #
#    Updated: 2019/08/27 13:57:18 by asusan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftfiller.a

OUTPUT = asusan.filler

INCLUDE = -I includes/

FLAGS = -Wall -Wextra -Werror

LIB_FILES = ft_atoi.c ft_putchar.c ft_strdup.c \
			ft_putstr.c ft_strlen.c ft_itoa.c \
			ft_strsub.c ft_isdigit.c ft_putnbr.c \
			ft_bzero.c ft_memset.c ft_strchr.c \
			ft_strjoin.c \
			ft_strcmp.c get_next_line.c \
			ft_strnew.c ft_strstr.c \
			ft_strdel.c

SRC_FILES = main.c filler.c free_file.c \
            min_sq_for_figure.c create_maps.c \
            installation.c

SRC = $(addprefix src/, $(SRC_FILES))
LIBFT = $(addprefix libft/, $(LIB_FILES))

OBJ = $(SRC_FILES:.c=.o) $(LIB_FILES:.c=.o)

all: $(NAME)

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec. \(°□°)/"
	@gcc -c $(FLAGS) $(SRC) $(LIBFT) $(INCLUDE)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "(•̀ᴗ•́)و filler generated!".
	@gcc -o $(OUTPUT) $(OBJ) -I includes/ -L libft/

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f main.o

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OUTPUT)


re: fclean all
