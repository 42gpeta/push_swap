# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2023/07/04 21:33:18 by gpeta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= push_swap

#-------------------------------------------------------#
#	INGREDIENTS											#
#-------------------------------------------------------#

LIBS		:= ft
LIBS_TARGET := \
lib/libft/libft.a \


INCS		:= \
include \
lib/libft/include \


SRC_DIR		:= src
SRCS		:= \
algo.c \
algo_utils_conbination.c \
algo_utils_count.c \
algo_utils_execute.c \
algo_utils_find_node.c \
error.c \
list.c \
list_utils.c \
main.c \
push.c \
push_swap.c \
reverse_rotate.c \
rotate.c \
sort.c \
sort_utils.c \
swap.c \
print.c \


SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror 
CPPFLAG		:= $(addprefix -I ,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L ,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l ,$(LIBS))
NORMINETTE	:=	norminette

#-------------------------------------------------------#
#	UTENSILS											#
#-------------------------------------------------------#

RM			:= rm -f
MAKEFLAGS	+= --silent --no-print-directory
DIR_DUP		= mkdir -p $(@D)

#-------------------------------------------------------#
#	RECIPES												#
#-------------------------------------------------------#

all : $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) -g $(LDFLAGS) $(OBJS) $(LDLIBS) $(MLX_FLAGS) -o $(NAME)
	$(info EXE ./$(NAME) CREATED)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

# compilation des *.c en *.o sans linker
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAG) -ggdb -c -o $@ $<

clean:
	for f in $(dir $(LIBS_TARGET)) ; do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	for f in $(strip(dir $(LIBS_TARGET))) ; do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# ************************************* #
#				PUSH_SWAP				#
# ************************************* #

.PHONY: all clean fclean re
.SILENT:

###############################################
##	NORMINETTE : COLORMINETTE (@VEGRET)

RED          =    \033[0;91m
LIGHT_RED    =    \033[0;31m
GREEN        =    \033[0;92m

norminette:
	@$(NORMINETTE) | grep -v Norme | awk '{\
	if ($$NF == "OK!") { \
	    print "$(GREEN)"$$0"$(END)" \
	} else if ($$NF == "Error!") { \
	    print "$(RED)$(BOLD)"$$0"$(END)" \
	} else if ($$1 == "Error:") { \
	    print "$(LIGHT_RED)"$$0"$(END)" \
	} else { print }}'

###############################################
##	NORMINETTE : verif norminette (@VEGRET)

norm_verif:
	nm $(NAME)