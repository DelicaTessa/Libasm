# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tclement <tclement@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/05 13:02:07 by tclement      #+#    #+#                  #
#    Updated: 2021/02/23 10:38:31 by tclement      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

HEADER = libasm.h

SRC = 	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_strdup.s \
		ft_write.s  \
		ft_read.s   

OBJ = $(SRC:%.s=%.o)

CFLAG = -f macho64

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

bonus: all

%.o: %.s $(HEADER)
	nasm $(CFLAG) -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re: fclean all

.PHONY: fclean clean re bonus