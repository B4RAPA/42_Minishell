# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 09:49:13 by lfabel            #+#    #+#              #
#    Updated: 2025/02/19 13:52:21 by lfabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_itoa.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_strnstr.c ft_substr.c ft_strcmp.c ft_strcpy.c \
ft_strcat.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstmap_bonus.c get_next_line_utils.c get_next_line.c \
ft_split/ft_split.c ft_split/word_count.c

OBJS = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_strchr.o ft_strdup.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o \
ft_strrchr.o ft_strstr.o ft_tolower.o ft_toupper.o ft_strjoin.o ft_itoa.o ft_strtrim.o ft_strmapi.o ft_striteri.o  ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_strnstr.o ft_substr.o ft_strcmp.o ft_strcpy.o \
ft_strcat.o ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstclear_bonus.o ft_lstdelone_bonus.o ft_lstiter_bonus.o ft_lstlast_bonus.o ft_lstsize_bonus.o ft_lstadd_back_bonus.o ft_lstmap_bonus.o get_next_line.o get_next_line_utils.o \
ft_split/ft_split.o ft_split/word_count.o
INCLUDE = libft.h get_next_line.h


all: $(NAME)


$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean: 
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: 	fclean all

.PHONY: clean all flean re