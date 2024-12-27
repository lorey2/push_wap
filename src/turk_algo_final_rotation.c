/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_final_rotation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:40:11 by lorey             #+#    #+#             */
/*   Updated: 2024/12/27 16:47:12 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_ra(t_data *data)
{
	int	i;
	int	counter_ra;

	counter_ra = 0;
	i = -1;
	data->min_stack_a = min_a(data);
	while (data->stack[0] != data->min_stack_a)
	{
		ra(data, 1);
		counter_ra++;
	}
	while (++i < counter_ra)
		rra(data, 1);
	return (counter_ra);
}

static int	count_rra(t_data *data)
{
	int	i;
	int	counter_rra;

	counter_rra = 0;
	i = -1;
	data->min_stack_a = min_a(data);
	while (data->stack[0] != data->min_stack_a)
	{
		rra(data, 1);
		counter_rra++;
	}
	while (++i < counter_rra)
		ra(data, 1);
	return (counter_rra);
}

void	final_rotation(t_data *data)
{
	while (data->b > 0)
		pa(data, 0);
	if (count_ra(data) < count_rra(data))
		while (data->stack[0] != data->min_stack_a)
			ra(data, 0);
	else
		while (data->stack[0] != data->min_stack_a)
			rra(data, 0);
}
