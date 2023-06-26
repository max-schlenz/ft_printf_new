# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 12:57:52 by mschlenz          #+#    #+#              #
#    Updated: 2023/06/26 12:37:57 by mschlenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
DEFCL	=	\033[0m
RED		=	\033[0;31m
LBLUE	=	\033[1;34m
LCYAN	=	\033[1;36m
PURPLE	=	\033[0;35m

NAME 	=	ft_printf

INC_DIR		=	../../inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIB_DIR		=	../../../../

SRC			= 	$(NAME)	\
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
OBJ_PATH	=	$(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRC)))

FLAGS		=	-g #-Wall -Wextra -Werror
INCLUDES	= 	-I $(INC_DIR)

all: create_dirs $(OBJ_PATH)

bonus: all

obj/%.o : src/%.c message
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@
	@ar -ruc $(LIB_DIR)libftprintf.a $@ 2>/dev/null

create_dirs:
	@mkdir -p $(OBJ_DIR)/bonus
	@mkdir -p $(LIB_DIR)

.INTERMEDIATE: message

message:
	@echo "${DEFCL}compiling ${LBLUE}ft_printf${DEFCL}..."

clean:
	@if [[ -n `find $(OBJ_DIR) -type f -name '*.o'` ]]; then \
		echo "${PURPLE}removing ${LBLUE}ft_printf${PURPLE} object files...${DEFCL}"; \
		find $(OBJ_DIR) -type f -name '*.o' -delete; \
	fi

fclean: clean
	@if [ -f "$(LIB_DIR)libftprintf.a" ]; then \
		echo "${PURPLE}removing ${LBLUE}ft_printf${PURPLE} library file...${DEFCL}"; \
		rm -f $(LIB_DIR)libftprintf.a; \
	fi

re: fclean all

.PHONY: all clean fclean re bonus