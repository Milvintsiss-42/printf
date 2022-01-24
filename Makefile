# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 02:43:30 by ple-stra          #+#    #+#              #
#    Updated: 2022/01/24 18:12:06 by ple-stra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS_DIR	= srcs
SRCS		= ft_printf.c parsing.c is_conversion.c\
 parse_conversion_c.c parse_conversion_s.c parse_conversion_p.c\
 parse_conversion_di.c parse_conversion_uxX.c parse_conversion_utils.c\
 parse_arguments.c invalid_conversion.c\
 lists.c buildstr.c free.c
BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/objs
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC			= -I./includes -I./libft/includes

LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/build/libft.a

CC			= gcc

CFLAGS		= $(INC) -Wall -Wextra
ifneq (nWerror, $(filter nWerror,$(MAKECMDGOALS)))
	CFLAGS	+= -Werror
endif

RM			= rm -rf

all			: $(NAME)

bonus		: all

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A)	:
			@echo "building libft..."
			@$(MAKE) -sC $(LIBFT_DIR) all
rmlibft		:
			@echo "deleting libft build..."
			@$(MAKE) -sC $(LIBFT_DIR) fclean

$(NAME)		: $(LIBFT_A) $(OBJ)
			@cp $(LIBFT_A) $(NAME)
			ar -rc $(NAME) $(OBJ)
			ranlib $(NAME)
			
clean		:
			$(RM) $(OBJ_DIR)

fclean		: rmlibft
			$(RM) $(BUILD_DIR)
			$(RM) $(NAME)

re			: fclean all

.PHONY: all clean fclean re rmlibft nWerror
