# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 12:57:52 by mschlenz          #+#    #+#              #
#    Updated: 2023/06/30 08:22:35 by mschlenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS =	--no-print-directory
SHELL 			=	/bin/bash


#FORMAT----------------------------------#
DEFCL			=	$(shell echo -e "\033[0m")
RED				=	$(shell echo -e "\033[0;31m")
GREEN			=	$(shell echo -e "\033[0;32m")
BGREEN			=	$(shell echo -e "\033[1;32m")
YELLOW			=	$(shell echo -e "\033[0;33m")
BLUE			=	$(shell echo -e "\033[0;34m")
BBLUE			=	$(shell echo -e "\033[1;34m")
PURPLE			=	$(shell echo -e "\033[0;35m")
CYAN			=	$(shell echo -e "\033[0;36m")
BCYAN			=	$(shell echo -e "\033[1;36m")
GRAY			=	$(shell echo -e "\033[0m\033[38;5;239m")
DEL_R			=	\033[K
# ---------------------------------------#


NAME 	=	libftprintf.a

INC_DIR		=	inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIB_DIR		=	../../../../

SRC			= 	libft/ft_calloc \
				libft/ft_isdigit \
				libft/ft_itoa \
				libft/ft_memset \
				libft/ft_strjoin \
				libft/ft_strlen \
				libft/ft_tolower \
				libft/ft_bzero \
				libft/ft_strdup \
				ft_printf \
				char \
				hex \
				int \
				ptr \
				string \
				uint \
				utils \
				uitoa \
				bonus/padding

SRC_PATH	=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC)))
OBJ_FILES	=	$(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRC)))

FLAGS		=	-g #-Wall -Wextra -Werror
INCLUDES	= 	-I $(INC_DIR)

all: create_dirs 
	@$(MAKE) -j $(NAME) 

r: all
	@$(CC) main.c $(NAME)
	@./a.out

bonus: all

$(NAME): $(OBJ_FILES)
	@ar -rcs $(NAME) $^

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(FLAGS) -o $@ $(INCLUDES) -c $< 

create_dirs: $(OBJ_DIR)/bonus $(OBJ_DIR)/libft
	@mkdir -p $(OBJ_DIR)/bonus
	@mkdir -p $(OBJ_DIR)/libft

clean:
	@if [[ -n `find $(OBJ_DIR) -type f -name '*.o'` ]]; then \
		echo "${PURPLE}removing ${LBLUE}ft_printf${PURPLE} object files...${DEFCL}"; \
		find $(OBJ_DIR) -type f -name '*.o' -delete; \
	fi

fclean: clean
	@if [ -f "libftprintf.a" ]; then \
		echo "${PURPLE}removing ${LBLUE}ft_printf${PURPLE} library file...${DEFCL}"; \
		rm -f libftprintf.a; \
	fi

re: fclean all

.PHONY: all clean fclean re bonus