/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancel <dancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:03:51 by dancel            #+#    #+#             */
/*   Updated: 2024/12/10 13:06:46 by dancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_total
{
	struct s_stack	*t_a;
	int				size_a;
	struct s_stack	*t_b;
	int				size_b;
	char			*result;
}					t_total;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;
/*

# push_swap.c
# ============================*/

int		main(int argc, char **argv);
/*

# utils.c
# ============================*/

char	**only_one_tab(char **argv, int i);
char	**valid_list(char **args, int i, int j);
int		is_sorted(char c, t_total *mega);
void	exit_push_swap(t_total *mega, int error);
void	free_stack(t_stack *t_x);
/*

# build_mega.c
# =============================*/

t_total	*search_min_in_args(char **args);
t_total	*replace_value_by_pos(char **args, int *value, int temp, int len);
t_total	*create_mega(char **args, int *value, int len);
void	fill_stack_a(t_stack **s_a, int value, int i, t_total *mega);
/*

# moves_set_one.c
# =============================*/

char	*ps_strjoin(t_total *mega, char *add_to_result);
void	swap(char c, t_total *mega);
void	push(char c, t_total *mega);
void	push_next(t_total *mega, char c, t_stack *source, t_stack *dest);
t_stack	*create_new_element(t_total *mega, char c, t_stack *s_x, t_stack *s_y);
/*

# moves_set_two.c
# =============================*/

void	rotate(char c, t_total *mega);
void	rotate_next(char c, t_total *mega);
void	rrotate(char c, t_total *mega);
void	rrotate_next(char c, t_total *mega);
/*

# sort.c
# =============================*/

void	sort(t_total *mega);
void	sort_3(t_total *mega);
void	halve(int n, t_total *mega);
void	put_in_b(int x, t_total *mega);
void	put_min_above(t_total *mega);
/*

# analyse.c
# =============================*/

void	find_cheaper(t_total *mega);
int		find_y(int v, t_total *mega);
int		find_cost(int cost, int x, int y, t_total *mega);
char	*find_comb(int cost, int x, int y, t_total *mega);
int		cmp(int a, int b, int mode);
/*

# move_x.c
# =============================*/

void	move_x(int x, int y, char *comb, t_total *mega);
void	move_x_next(int x, int y, char *comb, t_total *mega);

#endif