/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:30:35 by lorey             #+#    #+#             */
/*   Updated: 2024/12/18 15:50:00 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_nb(t_data *data, int i)
{
	if (data->stack[i] < data->min_stack_b
		|| data->stack[i] > data->max_stack_b)
		return (min_rb_rrb(data));
	else
		return (min_rb_rrb_2(data));
}

void	the_two_cases(t_data *data, int i)
{
	if (data->stack[i] < data->min_stack_b
		|| data->stack[i] > data->max_stack_b)
	{
		min_rb_rrb(data);
		if (data->rb_nbr > data->rrb_nbr)
			while (data->stack[data->b - 1] != data->max_stack_b)
				rrb(data, 0);
		else
			while (data->stack[data->b - 1] != data->max_stack_b)
				rb(data, 0);
	}
	else
	{
		min_rb_rrb_2(data);
		if (data->rb_nbr > data->rrb_nbr)
			while (data->stack[data->b] < data->stack[data->b - 1]
				|| data->stack[data->b] > data->stack[0])
				rrb(data, 0);
		else
			while (data->stack[data->b] < data->stack[data->b - 1]
				|| data->stack[data->b] > data->stack[0])
				rb(data, 0);
	}
}

void	calculate_ra(t_data *data, int i)
{
	int	j;
	int	nbr;

	j = 0;
	while (i + (++j) < data->argc)
	{
		ra(data, 1);
		nbr = find_nb(data, i) + j;
		if (nbr < data->cheapest[1])
		{
			data->cheapest[1] = nbr;
			data->cheapest[0] = j;
		}
	}
}

void	calculate_rra(t_data *data, int i)
{
	int	j;
	int	nbr;

	j = 0;
	while (i + (++j) < data->argc)
	{
		rra(data, 1);
		nbr = find_nb(data, i) + j;
		if (nbr < data->cheapest[1])
		{
			data->cheapest[1] = nbr;
			data->cheapest[0] = -j;
		}
	}
	if (data->cheapest[0] > 0)
		while (--data->cheapest[0] != -1)
			ra(data, 0);
	else if (data->cheapest[0] < 0)
		while (++data->cheapest[0] != 1)
			rra(data, 0);
}

//cheapest[0] is the index nbr of ra/rra
//

void	first_algo(t_data *data)
{
	int	i;

	i = 1;
	pb(data, 0);
	pb(data, 0);
	while (++i < data->argc - 1)
	{
		data->min_stack_b = min(data);
		data->max_stack_b = max(data);
		data->cheapest[0] = 0;
		data->cheapest[1] = find_nb(data, i);
		calculate_ra(data, i);
		calculate_rra(data, i);
		the_two_cases(data, i);
		pb(data, 0);
	}
	data->min_stack_a = min_a(data);
	final_rotation(data);
}
