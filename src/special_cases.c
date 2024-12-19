/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:09:27 by lorey             #+#    #+#             */
/*   Updated: 2024/12/11 18:58:23 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_already_sorted(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->argc - 2)
		if (data->stack[i] > data->stack[i + 1])
			return (0);
	return (1);
}

int	max3(t_data *data)
{
	if (data->stack[0] > data->stack[1] && data->stack[0] > data->stack[2])
		return (data->stack[0]);
	else if (data->stack[1] > data->stack[0] && data->stack[1] > data->stack[2])
		return (data->stack[1]);
	else
		return (data->stack[2]);
}

int	min3(t_data *data)
{
	if (data->stack[0] < data->stack[1] && data->stack[0] < data->stack[2])
		return (data->stack[0]);
	else if (data->stack[1] < data->stack[0] && data->stack[1] < data->stack[2])
		return (data->stack[1]);
	else
		return (data->stack[2]);
}

void	three_args(t_data *data)
{
	if (min3(data) == data->stack[0])
	{
		sa(data, 0);
		ra(data, 0);
	}
	else if (max3(data) == data->stack[0])
	{
		if (min3(data) == data->stack[2])
		{
			sa(data, 0);
			rra(data, 0);
		}
		else
			ra(data, 0);
	}
	else
	{
		if (data->stack[2] == max3(data))
			sa(data, 0);
		else
			rra(data, 0);
	}
}
