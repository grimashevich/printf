NAME = libftprintf.a
LIBFT = libft.a
LIBFT_DIR = ./libft
CC = gcc
SRC =		functions_0.c		functions_1.c		functions_2.c

# SRC_B =		ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c			\
			ft_lstadd_back.c	ft_lstdelone.c		ft_lstclear.c	ft_lstiter.c			\
			ft_lstmap.c

OBJ = $(patsubst %.c,%.o,$(SRC))
# OBJ_B = $(patsubst %.c,%.o,$(SRC_B))

D_FILES = $(patsubst %.c,%.d,$(SRC) $(SRC_B))

OPT_FLAGS =
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) all -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAGS) $(OPT_FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

# bonus :
#	@make OBJ="$(OBJ_B)" all

clean :
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJ) $(D_FILES)

fclean : clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re