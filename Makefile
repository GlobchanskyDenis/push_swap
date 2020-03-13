# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 20:44:24 by bsabre-c          #+#    #+#              #
#    Updated: 2020/03/12 17:19:15 by bsabre-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS				=	-Wall -Wextra -Werror -g
CHECKER				=	checker
PUSH_SWAP			=	push_swap
DIR_CHECKER			=	checker_dir/
DIR_PUSH_SWAP		=	push_swap_dir/
DIR_COMMON			=	common/
DIR_OPERATIONS		=	operations/
DIR_LFT				=	libft/
LFT					=	$(DIR_LFT)libft.a
FILES_CHECKER		=	main.c						command_reader.c
FILES_PUSH_SWAP		=	main.c						recursion_algorithm.c	\
						sort_small_stack_1.c		sort_small_stack_2.c	\
						queue_1.c					queue_2.c				\
						final_rotations.c			smart_wheel_1.c			\
						smart_wheel_2.c				bruteforce.c			\
						bruteforce_push.c			bruteforce_rev_rotate.c	\
						bruteforce_rotate.c			bruteforce_swap.c		\
						bublesort.c	
FILES_COMMON		=	reader.c					common.c				\
						flags.c						quicksort.c				\
						visualization.c
FILES_OPERATIONS	=	push.c						swap.c					\
						rotate.c					rev_rotate.c

SRC_CHECKER			= $(addprefix $(DIR_CHECKER), $(FILES_CHECKER))
SRC_PUSH_SWAP		= $(addprefix $(DIR_PUSH_SWAP), $(FILES_PUSH_SWAP))
SRC_OPERATIONS		= $(addprefix $(DIR_OPERATIONS), $(FILES_OPERATIONS))
OBJECTS_CHECKER		= $(addprefix $(DIR_CHECKER),$(FILES_CHECKER:.c=.o))
OBJECTS_PUSH_SWAP	= $(addprefix $(DIR_PUSH_SWAP),$(FILES_PUSH_SWAP:.c=.o))
OBJECTS_COMMON		= $(addprefix $(DIR_COMMON),$(FILES_COMMON:.c=.o))
OBJECTS_OPERATIONS	= $(addprefix $(DIR_OPERATIONS),$(FILES_OPERATIONS:.c=.o))

.PHONY: all clean fclean re

all:		$(CHECKER) $(PUSH_SWAP)

checker:	$(OBJECTS_CHECKER) $(OBJECTS_OPERATIONS) $(OBJECTS_COMMON) $(OBJECTS_PUSH_SWAP) $(DIR_CHECKER)/checker.h $(DIR_COMMON)/common.h
			@make -C $(DIR_LFT)
			@echo "Compiling checker"
			@gcc $(FLAGS) $(OBJECTS_CHECKER) $(OBJECTS_OPERATIONS) $(OBJECTS_COMMON) $(LFT) -o $(CHECKER)
			@echo "          -- Done"

push_swap:	$(OBJECTS_PUSH_SWAP) $(OBJECTS_OPERATIONS) $(OBJECTS_COMMON) $(DIR_PUSH_SWAP)/push_swap.h $(DIR_COMMON)/common.h
			@echo "Compiling push_swap"
			@gcc $(FLAGS) $(OBJECTS_PUSH_SWAP) $(OBJECTS_OPERATIONS) $(OBJECTS_COMMON) $(LFT) -o $(PUSH_SWAP)
			@echo "          -- Done"

clean:
			@make -C $(DIR_LFT) clean
			@rm -rf .DS_Store
			@rm -rf $(DIR_CHECKER)/.DS_Store
			@rm -rf $(DIR_PUSH_SWAP)/.DS_Store
			@rm -rf $(DIR_COMMON)/.DS_Store
			@rm -rf $(DIR_OPERATIONS)/.DS_Store
			@rm -rf $(OBJECTS_CHECKER)
			@rm -rf $(OBJECTS_PUSH_SWAP)
			@rm -rf $(OBJECTS_OPERATIONS)
			@rm -rf $(OBJECTS_COMMON)

fclean:		clean
			@make -C $(DIR_LFT) fclean
			@rm -rf $(CHECKER)
			@echo remove $(CHECKER)
			@rm -rf $(PUSH_SWAP)
			@echo remove $(PUSH_SWAP)

re:			fclean all
