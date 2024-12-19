/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:41:20 by lorey             #+#    #+#             */
/*   Updated: 2024/12/18 16:15:16 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_data *data)
{
	int	temp;
	int	back;

	back = data->argc;
	if ((data->argc - 1) - data->b >= 2)
	{
		data->argc--;
		temp = data->stack[data->argc - 1];
		while (--data->argc > data->b)
			data->stack[data->argc] = data->stack[data->argc - 1];
		data->stack[data->b] = temp;
	}
	data->argc = back;
}

void	rrb(t_data *data)
{
	int	i;
	int	temp;

	data->b--;
	if (data->b >= 1)
	{
		i = -1;
		temp = data->stack[0];
		while (++i < data->b)
			data->stack[i] = data->stack[i + 1];
		data->stack[data->b] = temp;
	}
	data->b++;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
