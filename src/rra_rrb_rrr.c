/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:41:20 by lorey             #+#    #+#             */
/*   Updated: 2024/12/18 15:49:22 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data, int silent)
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
	if (silent == 0)
		final_test(data, "rra");
}

void	rrb(t_data *data, int silent)
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
	if (silent == 0)
		final_test(data, "rrb");
}

void	rrr(t_data *data, int silent)
{
	rra(data, 1);
	rrb(data, 1);
	if (silent == 0)
		final_test(data, "rrr");
}
