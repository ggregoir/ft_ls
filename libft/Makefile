# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/24 13:52:14 by ggregoir          #+#    #+#              #
#    Updated: 2017/09/11 13:31:26 by ggregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRC			=

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g -O3
RM			=	rm -rf

SRCDIR		=	./sources/
INCDIR		=	./includes/
OBJDIR		=	./obj/

INC			=	$(addprefix $(INCDIR), $(NAME:.a=.h))
EXT			=	$(INC) Makefile
OBJ 		=	$(SRC:.c=.o)

# **************************************************************************** #
#                             char functions 	                               #
# **************************************************************************** #
SRC +=	ft_islower.c
SRC +=	ft_isupper.c
SRC +=	ft_isalpha.c
SRC +=	ft_isdigit.c
SRC +=	ft_isalnum.c
SRC +=	ft_isascii.c
SRC +=	ft_isprint.c
SRC +=	ft_toupper.c
SRC +=	ft_tolower.c
SRC +=	ft_isspace.c

# **************************************************************************** #
#                             memory functions 	                               #
# **************************************************************************** #
SRC +=	ft_memset.c
SRC +=	ft_bzero.c
SRC +=	ft_memcpy.c
SRC +=	ft_memccpy.c
SRC +=	ft_memmove.c
SRC +=	ft_memchr.c
SRC +=	ft_memcmp.c

SRC +=	ft_memalloc.c
SRC +=	ft_memdel.c
SRC +=	ft_realloc.c
SRC +=	ft_free_strsplit.c
SRC	+=	ft_free_grid.c
# **************************************************************************** #
#                        display / put on screen functions                     #
# **************************************************************************** #
SRC +=	ft_putchar.c
SRC +=	ft_putchar_fd.c
SRC +=	ft_putendl.c
SRC +=	ft_putendl_fd.c
SRC +=	ft_putnbr.c
SRC +=	ft_putnbr_fd.c
SRC +=	ft_putstr.c
SRC +=	ft_putstr_fd.c
SRC +=	ft_print_memory.c
# **************************************************************************** #
#                             string functions 	                               #
# **************************************************************************** #
SRC +=	ft_strlen.c
SRC +=	ft_strdup.c
SRC +=	ft_strcpy.c
SRC +=	ft_strncpy.c
SRC +=	ft_strcat.c
SRC +=	ft_strncat.c
SRC +=	ft_strlcat.c
SRC +=	ft_strchr.c
SRC +=	ft_strrchr.c
SRC +=	ft_strstr.c
SRC +=	ft_strnstr.c
SRC +=	ft_strcmp.c
SRC +=	ft_strncmp.c
SRC +=	ft_strrev.c

SRC +=	ft_strnew.c
SRC +=	ft_strdel.c
SRC +=	ft_strclr.c
SRC +=	ft_striter.c
SRC +=	ft_striteri.c
SRC +=	ft_strmap.c
SRC +=	ft_strmapi.c
SRC +=	ft_strequ.c
SRC +=	ft_strnequ.c
SRC +=	ft_strsub.c
SRC +=	ft_strjoin.c
SRC	+=	ft_strjoinf.c
SRC +=	ft_strtrim.c
SRC +=	ft_strsplit.c

SRC +=	ft_strcjoin.c
SRC +=	ft_strcut.c
SRC +=	ft_printjoin.c
SRC	+=	ft_count_words.c
SRC	+=	ft_error.c

SRC	+=	print_color.c
# **************************************************************************** #
#                             integer functions 	                           #
# **************************************************************************** #
SRC +=	ft_atoi.c
SRC +=	ft_itoa.c
SRC +=	ft_atol.c
# **************************************************************************** #
#                             linked-list functions 	                       #
# **************************************************************************** #
SRC +=	ft_lstnew.c
SRC +=	ft_lstdelone.c
SRC +=	ft_lstdel.c
SRC +=	ft_lstadd.c
SRC +=	ft_lstiter.c
SRC +=	ft_lstmap.c
SRC +=	ft_lstmap.c
SRC	+=	ft_lstdelcont.c
SRC	+=	ft_lst_add_back.c

SRC +=	ft_gnl.c

O	= 	$(addprefix $(OBJDIR),$(OBJ))
S	=	$(addprefix $(SRCDIR), $(SRC))

all: $(NAME)

$(NAME): $(O) $(EXT)
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)
	@echo "\033[0;36m-----------------------------------------------"
	@echo "\033[0;32m[ ✔ ] Linked Libft executable" $(NAME)
	@echo "\033[0;36m-----------------------------------------------\x1b[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c $(EXT)
	@echo "\033[0;35m[ -> ] Compiling $<"
	@$(CC) $(CFLAGS) -c -I $(INCDIR) $< -o $@

$(O): | ./obj

./obj:
	@mkdir -p $(OBJDIR)
	@echo "\033[0;32m[ ✔ ] Folder for Libft object files created !"
	@echo "\033[0;36m-----------------------------------------------"

clean:
	@$(RM) $(OBJDIR)
	@echo "\033[0;31m[ ✔ ] Removed Libft object files"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31m[ ✔ ] Removed Libft executable" $(NAME)

re: fclean
	@make

norm:
	@norminette $(S) $(INC)

.PHONY: all clean fclean re norme
