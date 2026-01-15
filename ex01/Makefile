# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nseon <nseon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 10:54:16 by nseon             #+#    #+#              #
#    Updated: 2026/01/15 09:34:14 by nseon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	serialization

# ---------------FILES--------------- #

MAKE_DIR	=	.make/

SRC_DIR		=	src/

OBJ			=	$(patsubst %.cpp, $(MAKE_DIR)%.o, $(SRC))

DEP			=	$(patsubst %.cpp, $(MAKE_DIR)%.d, $(SRC))

# ---------------MAIN---------------- #

SRC			=	main.cpp \
				Serializer.cpp \

# --------------INCLUDES------------- #

INCS_DIR	=	includes/
INCLUDES	=	$(INCS_DIR)

# --------------CONFIGS-------------- #

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
CPPFLAGS	=	-MMD -MP $(addprefix -I, $(INCLUDES))

# --------------TARGETS-------------- #

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(MAKE_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(MAKE_DIR)

.PHONY: fclean
fclean:
	rm -rf $(NAME) $(MAKE_DIR)

.PHONY: re
re: fclean
	$(MAKE)

.PHONY: force
force:

-include $(DEP)

.DEFAULT_GOAL := all
