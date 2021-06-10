# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vintran <vintran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 18:48:02 by vintran           #+#    #+#              #
#    Updated: 2021/06/10 17:12:37 by vintran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap
BONUS_NAME			=	checker
BONUS_DIR			=	./bonus/
SRCS_DIR			=	./srcs/
SRCS				=	main.c				\
						algo.c				\
						best_chunk.c		\
						chunk.c				\
						ft_list2.c			\
						ft_list.c			\
						ft_rooftop.c		\
						ft_split.c			\
						get_pos.c			\
						get_values.c		\
						is_char.c			\
						manage_tab.c		\
						op_push.c			\
						op_rotate.c			\
						op_rrotate.c		\
						op_swap.c			\
						parsing.c			\
						sort_five.c			\
						sort_three.c		\
						swap_to.c			\
						utils.c
SRCS_BASENAME		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS				=	$(SRCS_BASENAME:.c=.o)
CC					=	clang
FLAGS				=	-Wall -Werror -Wextra

.c.o			:
				$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

all				:	$(NAME)

bonus			:	$(NAME) $(BONUS_NAME)

$(NAME)			:	$(OBJS)
				$(CC) $(OBJS) $(FLAGS) -o $(NAME)
				@echo [$(NAME)] : Created !

$(BONUS_NAME)	:
				make -C $(BONUS_DIR)
				mv $(BONUS_DIR)$(BONUS_NAME) ./

clean			:
				rm -f $(OBJS)
				make clean -C $(BONUS_DIR)

fclean			:	clean
				rm -f $(NAME)
				rm -f $(BONUS_NAME)

re				:	fclean all

.PHONY: 		clean fclean all re
