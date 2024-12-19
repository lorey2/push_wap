/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:18:03 by lorey             #+#    #+#             */
/*   Updated: 2024/12/19 21:21:37 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error_gnl(t_data *data)
{
	write(1, "not valid", 9);
	free(data->stack);
	exit (0);
}

void	execute_op(t_data *data, char *op)
{
	if (!ft_strcmp(op, "sa"))
		sa(data);
	else if (!ft_strcmp(op, "sb"))
		sb(data);
	else if (!ft_strcmp(op, "ss"))
		ss(data);
	else if (!ft_strcmp(op, "pa"))
		pa(data);
	else if (!ft_strcmp(op, "pb"))
		pb(data);
	else if (!ft_strcmp(op, "ra"))
		ra(data);
	else if (!ft_strcmp(op, "rb"))
		rb(data);
	else if (!ft_strcmp(op, "rr"))
		rr(data);
	else if (!ft_strcmp(op, "rra"))
		rra(data);
	else if (!ft_strcmp(op, "rrb"))
		rrb(data);
	else if (!ft_strcmp(op, "rrr"))
		rrr(data);
	else
		error_gnl(data);
}

void	g_n_l_execute(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	if (line)
		line[ft_strlen(line) - 1] = '\0';
	while (line != NULL)
	{
		execute_op(data, line);
		free(line);
		if (is_stack_already_sorted(data))
			break ;
		line = get_next_line(0);
		if (line)
			line[ft_strlen(line) - 1] = '\0';
	}
}
