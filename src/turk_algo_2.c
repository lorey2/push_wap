/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:36:49 by lorey             #+#    #+#             */
/*   Updated: 2024/12/14 01:56:20 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_data *data)
{
	data->rb_nbr = 0;
	data->rrb_nbr = 0;
}

int	min_rb_rrb(t_data *data)
{
	int	j;

	init(data);
	while (data->stack[data->b - 1] != data->max_stack_b)
	{
		rb(data, 1);
		data->rb_nbr++;
	}
	j = -1;
	while (++j != data->rb_nbr)
		rrb(data, 1);
	while (data->stack[data->b - 1] != data->max_stack_b)
	{
		rrb(data, 1);
		data->rrb_nbr++;
	}
	j = -1;
	while (++j != data->rrb_nbr)
		rb(data, 1);
	if (data->rb_nbr >= data->rrb_nbr)
		return (data->rrb_nbr);
	else
		return (data->rb_nbr);
}

int	min_rb_rrb_2(t_data *data)
{
	int	j;

	init(data);
	while (data->stack[data->b] < data->stack[data->b - 1]
		|| data->stack[data->b] > data->stack[0])
	{
		rb(data, 1);
		data->rb_nbr++;
	}
	j = -1;
	while (++j != data->rb_nbr)
		rrb(data, 1);
	while (data->stack[data->b] < data->stack[data->b - 1]
		|| data->stack[data->b] > data->stack[0])
	{
		rrb(data, 1);
		data->rrb_nbr++;
	}
	j = -1;
	while (++j != data->rrb_nbr)
		rb(data, 1);
	if (data->rb_nbr >= data->rrb_nbr)
		return (data->rrb_nbr);
	else
		return (data->rb_nbr);
}
