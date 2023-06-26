# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 12:57:52 by mschlenz          #+#    #+#              #
#    Updated: 2023/06/26 12:38:12 by mschlenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FORMAT----------------------------------#
DEFCL	=	$(shell echo -e "\033[0m")
RED		=	$(shell echo -e "\033[0;31m")
LBLUE	=	$(shell echo -e "\033[1;34m")
LCYAN	=	$(shell echo -e "\033[1;36m")
PURPLE	=	$(shell echo -e "\033[0;35m")
# ---------------------------------------#

NAME			=	libftprintf.a

SRC_DIR			=	src
OBJ_DIR			=	obj
LIB_DIR			=	lib

SRC				= 	$(NAME)

LIB				=	libft 

SRC_FILES		=	$(addsuffix .c, $(addprefix $(SRC_DIR)/, $(SRC)))
LIB_FILES		=	$(addsuffix .a, $(addprefix $(LIB_DIR)/, $(LIB)))
OBJ_FILES		=	$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))

INCLUDES		= 	-I src/libft/inc/
LINKER			=	-L ./ -l ftprintf
FLAGS			= 	#-fsanitize=address -g #-Wall -Wextra -Werror

all: $(LIB_FILES)

bonus: all

exec: $(NAME)

$(LIB_FILES):
	@make -C src/libft

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIB_FILES) $(OBJ_DIR) $(OBJ_FILES) message
	@gcc $(FLAGS) $(INCLUDES) $(LINKER) $(OBJ_FILES) -o $(NAME)


.INTERMEDIATE: message

message:
	@echo "${DEFCL}compiling ${LCYAN}${NAME}${DEFCL}..."

clean:
	@make clean -C src/libft
	@if [ -f "${NAME}" ]; then \
		echo "${PURPLE}removing ${LCYAN}${NAME}${PURPLE} binary file...${DEFCL}"; \
		rm -f ${NAME}; \
	fi
	@if find ${OBJ_FILES} > /dev/null 2>&1; then \
		echo "${PURPLE}removing ${LCYAN}${NAME}${PURPLE} object files...${DEFCL}"; \
		rm -f $(OBJ_FILES); \
	fi

fclean: clean
	@make fclean -C src/libft

re: fclean all

.PHONY: all clean fclean re bonus
