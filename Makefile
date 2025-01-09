# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dancel <dancel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 17:19:35 by dancel            #+#    #+#              #
#    Updated: 2024/12/10 10:35:08 by dancel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables de Compilation
# ============================

PUSH_SWAP  = push_swap
CHECKER    = checker
CC         = cc
CFLAGS     = -Wall -Werror -Wextra -g3


# Bibliothèques et Fichiers
# ============================

PRINTF     = ft_printf/libftprintf.a
LIBFT      = libft/libft.a
INCLUDES   = -Ift_printf -Ilibft -Iget_next_line


# Cible principale
# ============================

all: $(PUSH_SWAP)

$(PUSH_SWAP): 	push_swap.c \
				build_mega.c \
				utils.c \
				moves_set_one.c \
				moves_set_two.c \
				sort.c \
				analyse.c \
				move_x.c \
				$(PRINTF) \
				$(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@


# Cible bonus
# ============================

bonus: all $(CHECKER)

$(CHECKER) :	checker.c \
				build_mega.c \
				utils.c \
				moves_set_one.c \
				moves_set_two.c \
				sort.c \
				analyse.c \
				move_x.c \
				$(PRINTF) \
				$(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

# Compilation des bibliothèques
# ============================

$(PRINTF):
	@make -s -C ft_printf

$(LIBFT):
	@make -s -C libft


# Nettoyage des fichiers
# ============================

clean:
	@make clean -s -C ft_printf
	@make clean -s -C libft

fclean: clean
	@make fclean -s -C ft_printf
	@make fclean -s -C libft
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER)


# Rebuild
# ============================

re: fclean all


# Cibles "fantômes"
# ============================

.PHONY: all clean fclean re bonus

