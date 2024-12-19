/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:01:31 by lorey             #+#    #+#             */
/*   Updated: 2024/12/19 17:10:12 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <stdio.h>
# include <stdlib.h>
//# include <string.h>
//# include <sys/types.h>
# include <unistd.h>
//# include <fcntl.h>
//# include <sys/wait.h>
//# include <limits.h>

typedef struct s_data
{
	int		*stack;
	int		argc;
	int		b;
	int		cheapest[2];
	int		max_stack_b;
	int		min_stack_b;
	int		min_stack_a;
	int		rrb_nbr;
	int		rb_nbr;
	char	*pr_mve;

}				t_data;

size_t		ft_strlen(const char *s);
int			ft_strcmp(char *s1, char *s2);
long long	ft_atoi(const char *str);
void		sa(t_data *data, int silent);
void		sb(t_data *data, int silent);
void		ss(t_data *data, int silent);
void		pa(t_data *data, int silent);
void		pb(t_data *data, int silent);
void		ra(t_data *data, int silent);
void		rb(t_data *data, int silent);
void		rr(t_data *data, int silent);
void		rra(t_data *data, int silent);
void		rrb(t_data *data, int silent);
void		rrr(t_data *data, int silent);
void		first_algo(t_data *data);
int			rb_bigger_rrb(t_data *data);
int			rb_bigger_rrb_2(t_data *data);
int			min_rb_rrb(t_data *data);
int			min_rb_rrb_2(t_data *data);
int			max(t_data *data);
int			min(t_data *data);
int			min_a(t_data *data);
void		final_rotation(t_data *data);
int			is_stack_already_sorted(t_data *data);
void		three_args(t_data *data);
void		the_two_cases(t_data *data, int i);
int			find_nb(t_data *data, int i);
void		execute(t_data *data);
void		final_test(t_data *data, char *current_move);
char		*ft_strdup(const char *s1);

#endif
