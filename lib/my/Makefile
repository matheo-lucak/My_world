##
## EPITECH PROJECT, 2019
## Makefile libmy
## File description:
## processes compilation for this lib
##

SRC				=	./my_putchar.c						\
					./my_isnum.c						\
					./my_isalpha.c						\
					./my_isalphanum.c					\
					./my_str_is_alphanum.c				\
					./my_str_is_num.c					\
					./my_int_size.c						\
					./my_int_to_str.c					\
					./my_strlen.c						\
					./my_strnlen.c						\
					./my_strlen_char.c					\
					./my_strlen_cmpstr.c				\
					./my_arrdup.c						\
					./my_append_to_array.c				\
					./my_skip_a_file_line.c				\
					./my_arrlen.c						\
					./my_show_arr.c						\
					./my_free_arr.c						\
					./my_putstr.c						\
					./my_getnbr.c						\
					./my_hay_needle.c					\
					./my_pow.c							\
					./my_put_nbr.c						\
					./my_put_nbr_u.c					\
					./my_put_nbr_s.c					\
					./my_put_nbr_su.c					\
					./my_put_nbr_l.c					\
					./my_put_nbr_ll.c					\
					./my_put_nbr_lu.c					\
					./my_put_nbr_llu.c					\
					./my_arrcmp.c						\
					./my_strcmp.c						\
					./my_strncmp.c						\
					./my_strdup.c						\
					./my_strndup.c						\
					./my_strdup_char.c					\
					./my_strdup_cmpstr.c				\
					./my_memcpy.c						\
					./my_memset.c						\
					./my_strcat.c						\
					./my_strcpy.c						\
					./my_str_to_word_array.c			\
					./find_char_in_str.c				\
					./get_next_line.c

SRCMATHEMATICAL	=	./mathematical/my_radians.c

SRCGRAPHICAL	=	./graphical/conv_vec2f_vec2i.c		\
					./graphical/conv_vec2i_vec2f.c


SRCMYPRINTF		=	./my_printf/my_printf.c				\
					./my_printf/flag_checkers.c			\
					./my_printf/get_flag.c				\
					./my_printf/create_flag_array.c		\
					./my_printf/redirect_putchar.c		\
					./my_printf/redirect_put_nbr.c		\
					./my_printf/redirect_short.c		\
					./my_printf/redirect_long.c			\
					./my_printf/redirect_percent.c		\
					./my_printf/redirect_lower_upper.c	\
					./my_printf/redirect_hashtag.c		\
					./my_printf/redirect_add_ptr.c		\
					./my_printf/my_flag_cmp.c

ARFLAGS 		=	rc

NAME			=	libmy.a

CPPFLAGS		=	-I./include/

CFLAGS			=	-Wall -Wextra

OBJ				=	$(SRC:.c=.o) $(SRCMATHEMATICAL:.c=.o) $(SRCGRAPHICAL:.c=.o) $(SRCMYPRINTF:.c=.o)

NAME			=	libmy.a

NAME_MY_H		=	my.h

NAME_MY_GRAPHICAL_H	=	my_graphical.h

NAME_MY_MATH_H		=	my_math.h

NAME_MYPRINTF_H	=	my_printf.h

all:			$(NAME)

$(NAME):		$(OBJ)
				$(AR) $(ARFLAGS) $(NAME) $(OBJ)
				cp $(NAME) ../
				cp ./include/$(NAME_MY_H) ./../../include/
				cp ./include/$(NAME_MY_GRAPHICAL_H) ./../../include/
				cp ./include/$(NAME_MY_MATH_H) ./../../include/
				cp ./include/$(NAME_MYPRINTF_H) ./../../include/

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(OBJ)
				$(RM) ./../../include/$(NAME_MY_H)
				$(RM) ./../../include/$(NAME_MY_GRAPHICAL_H)
				$(RM) ./../../include/$(NAME_MY_MATH_H)
				$(RM) ./../../include/$(NAME_MYPRINTF_H)
				$(RM) ./$(NAME_MY_H)
				$(RM) ../$(NAME)

re:				fclean all

.NOTPARALLEL:
.PHONY: 		all clean fclean re
