/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:09:27 by lorey             #+#    #+#             */
/*   Updated: 2024/12/20 18:50:37 by lorey            ###   LAUSANNE.ch       */
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

int	max_or_min(t_data *data, int max_or_min)
{
	if (max_or_min == 1)
	{
		if (data->stack[0 + data->b] > data->stack[1 + data->b]
			&& data->stack[0 + data->b] > data->stack[2 + data->b])
			return (data->stack[0 + data->b]);
		else if (data->stack[1 + data-> b] > data->stack[0 + data->b]
			&& data->stack[1 + data->b] > data->stack[2 + data->b])
			return (data->stack[1 + data->b]);
		else
			return (data->stack[2 + data->b]);
	}
	else
	{
		if (data->stack[0 + data->b] < data->stack[1 + data->b]
			&& data->stack[0 + data->b] < data->stack[2 + data->b])
			return (data->stack[0 + data->b]);
		else if (data->stack[1 + data->b] < data->stack[0 + data->b]
			&& data->stack[1 + data->b] < data->stack[2 + data->b])
			return (data->stack[1 + data->b]);
		else
			return (data->stack[2 + data->b]);
	}
}

void	three_args(t_data *data)
{
	if (max_or_min(data, 0) == data->stack[0 + data->b])
	{
		sa(data, 0);
		ra(data, 0);
	}
	else if (max_or_min(data, 1) == data->stack[0 + data->b])
	{
		if (max_or_min(data, 0) == data->stack[2 + data->b])
		{
			sa(data, 0);
			rra(data, 0);
		}
		else
			ra(data, 0);
	}
	else
	{
		if (data->stack[2 + data->b] == max_or_min(data, 1))
			sa(data, 0);
		else
			rra(data, 0);
	}
}

void	three_cases(t_data *data)
{
	int	max_sa;

	max_sa = max_a(data);
	data->min_stack_a = min_a(data);
	if (data->stack[data->b - 1] < data->min_stack_a)
		while (data->min_stack_a != data->stack[data->b])
			ra(data, 0);
	else if (data->stack[data->b - 1] > max_sa)
		while (data->stack[data->b] != data->min_stack_a)
			ra(data, 0);
	else
		while (data->stack[data->b - 1] > data->stack[data->b]
			|| data->stack[data->b - 1] < data->stack[data->argc - 2])
			ra(data, 0);
	pa(data, 0);
}

void	four_five_args(t_data *data)
{
	int	i;

	i = data->argc;
	while (--i > 3)
		pb(data, 0);
	if (!(data->stack[data->b] < data->stack[data->b + 1]
			&& data->stack[data->b + 1] < data->stack[data->b + 2]))
		three_args(data);
	while (data->b != 0)
		three_cases(data);
	data->min_stack_a = min_a(data);
	final_rotation(data);
}
