/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:18:03 by lorey             #+#    #+#             */
/*   Updated: 2024/12/27 17:34:06 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error_gnl(t_data *data, char *line)
{
	write(1, "not valid", 9);
	free(data->stack);
	free(line);
	exit (0);
}

void	execute_op(t_data *data, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(data);
	else if (!ft_strcmp(line, "sb"))
		sb(data);
	else if (!ft_strcmp(line, "ss"))
		ss(data);
	else if (!ft_strcmp(line, "pa"))
		pa(data);
	else if (!ft_strcmp(line, "pb"))
		pb(data);
	else if (!ft_strcmp(line, "ra"))
		ra(data);
	else if (!ft_strcmp(line, "rb"))
		rb(data);
	else if (!ft_strcmp(line, "rr"))
		rr(data);
	else if (!ft_strcmp(line, "rra"))
		rra(data);
	else if (!ft_strcmp(line, "rrb"))
		rrb(data);
	else if (!ft_strcmp(line, "rrr"))
		rrr(data);
	else
		error_gnl(data, line);
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
		line = get_next_line(0);
		if (line)
			line[ft_strlen(line) - 1] = '\0';
	}
}
