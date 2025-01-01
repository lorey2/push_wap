/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:01:37 by lorey             #+#    #+#             */
/*   Updated: 2024/12/29 15:38:44 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

//# include <stdio.h>
# include <stdlib.h>
//# include <string.h>
//# include <sys/types.h>
# include <unistd.h>
//# include <fcntl.h>
//# include <sys/wait.h>
//# include <limits.h>
# define BUFFER_SIZE 1000

typedef struct s_data
{
	int		*stack;
	int		argc;
	int		b;
}				t_data;

size_t		ft_strlen(const char *s);
size_t		ft_strlen_skip_zero(const char *s);
int			ft_strcmp(char *s1, char *s2);
long long	ft_atoi(const char *str);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);
void		execute(t_data *data);
void		g_n_l_execute(t_data *data);
int			get_next_line(char **line);
int			is_stack_already_sorted(t_data *data);

#endif
