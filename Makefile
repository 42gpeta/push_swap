# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2023/05/15 18:15:02 by gpeta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= push_swap


#-------------------------------------------------------#
#	INGREDIENTS											#
#-------------------------------------------------------#

LIBS		:= ft
LIBS_TARGET := \
lib/libft/libft.a \
# lib/libmlx/libmlx_Linux.a \
# lib/libmlx/libmlx.a \

INCS		:= \
include \
lib/libft/include \
# lib/libmlx \


SRC_DIR		:= src
SRCS		:= \
list.c \
main.c \
push.c \
push_swap.c \
reverse_rotate.c \
rotate.c \
swap.c \
error.c \
print.c \
# /gnl/get_next_line.c  /gnl/get_next_line_utils.c  \


SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror 
# CFLAGS 		:= -Wall -Wextra 
CPPFLAG		:= $(addprefix -I ,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L ,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l ,$(LIBS))
NORMINETTE	:=	norminette -R CheckForbiddenSourceHeader ./*/*.c ./*/*.h
# MLX_FLAGS	:= -lXext -lX11 -lz -lm

#-------------------------------------------------------#
#	UTENSILS											#
#-------------------------------------------------------#

RM			:= rm -f
MAKEFLAGS	+= --silent --no-print-directory
# MAKEFLAGS	+= --no-print-directory
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