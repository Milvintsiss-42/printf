# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 21:12:38 by ple-stra          #+#    #+#              #
#    Updated: 2022/01/23 00:19:16 by ple-stra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS_DIR	= srcs
SRCS		=\
 ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c\
\
 ft_flags.c\
\
 ft_max_min.c\
\
 ft_strlen.c ft_strlen_c.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
 ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
 ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
 ft_free.c ft_strdup.c\
\
 ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_itoa_base.c\
 ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
 ft_putendl_fd.c ft_putnbr_fd.c ft_putchar.c ft_putstr.c\
\
 ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
 ft_lstadd_next.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
 ft_lstsort.c

BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/objs
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC_DIR		= includes

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I $(INC_DIR)

RM			= rm -rf

all			: $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		: $(OBJ)
			ar -rc $(BUILD_DIR)/$(NAME) $(OBJ)
			ranlib $(BUILD_DIR)/$(NAME)

clean		:
			$(RM) $(OBJ_DIR)

fclean		:
			$(RM) $(BUILD_DIR)

re			: fclean all

.PHONY: all clean fclean re
