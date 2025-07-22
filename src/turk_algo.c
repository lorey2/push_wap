/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:30:35 by lorey             #+#    #+#             */
/*   Updated: 2025/07/22 16:08:36 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

int	find_rb_nbr(t_data *data, int num)
{
	int	count;

	count = 0;
	if (num > data->max_stack_b || num < data->min_stack_b)
		while (data->stack[data->b - count - 1] != data->max_stack_b)
			count++;
	else if (num > data->stack[data->b - 1]
		&& num < data->stack[0])
		;
	else
	{
		while (count < data->b)
		{
			if (num < data->stack[data->b - 1 - count]
				&& num > data->stack[data->b - 1 - ((count + 1) % data->b)])
			{
				count++;
				break ;
			}
			count++;
		}
	}
	return (count);
}

void	do_the_moves(t_move *cheapest, t_data *data)
{
	while (cheapest->ra > 0 && cheapest->rb > 0)
	{
		rr(data, 0);
		cheapest->ra--;
		cheapest->rb--;
	}
	while (cheapest->rra > 0 && cheapest->rrb > 0)
	{
		rrr(data, 0);
		cheapest->rra--;
		cheapest->rrb--;
	}
	while (cheapest->ra-- > 0)
		ra(data, 0);
	while (cheapest->rra-- > 0)
		rra(data, 0);
	while (cheapest->rb-- > 0)
		rb(data, 0);
	while (cheapest->rrb-- > 0)
		rrb(data, 0);
	pb(data, 0);
}

typedef struct s_cost
{
	int	n_ra;
	int	n_rra;
	int	n_rb;
	int	n_rrb;
	int	c_ra_rb;
	int	c_rra_rrb;
	int	c_ra_rrb;
	int	c_rra_rb;
}			t_cost;

void	setup_costs(t_cost *cost, t_data *data, int i)
{
	cost->n_ra = i - data->b;
	cost->n_rra = (data->argc - 1) - data->b - cost->n_ra;
	cost->n_rb = find_rb_nbr(data, data->stack[i]);
	if (cost->n_rb == 0)
		cost->n_rrb = 0;
	else
		cost->n_rrb = data->b - cost->n_rb;
	if (cost->n_ra > cost->n_rb)
		cost->c_ra_rb = cost->n_ra;
	else
		cost->c_ra_rb = cost->n_rb;
	if (cost->n_rra > cost->n_rrb)
		cost->c_rra_rrb = cost->n_rra;
	else
		cost->c_rra_rrb = cost->n_rrb;
	cost->c_ra_rrb = cost->n_ra + cost->n_rrb;
	cost->c_rra_rb = cost->n_rra + cost->n_rb;
}

void	iterate_on_all_stack_b(t_cost *cost,
								t_data *data, int i, t_move *cheapest)
{
	while (i < data->argc - 1)
	{
		setup_costs(cost, data, i);
		if (cost->c_ra_rb < cheapest->cost)
			*cheapest = ((t_move){cost->c_ra_rb, cost->n_ra, 0, cost->n_rb, 0});
		if (cost->c_rra_rrb < cheapest->cost)
			*cheapest = ((t_move){cost->c_rra_rrb,
					0, cost->n_rra, 0, cost->n_rrb});
		if (cost->c_ra_rrb < cheapest->cost)
			*cheapest = ((t_move){cost->c_ra_rrb,
					cost->n_ra, 0, 0, cost->n_rrb});
		if (cost->c_rra_rb < cheapest->cost)
			*cheapest = ((t_move){cost->c_rra_rb,
					0, cost->n_rra, cost->n_rb, 0});
		i++;
	}
}

void	first_algo2(t_data *data)
{
	t_move	cheapest;
	int		i;
	t_cost	cost;

	pb(data, 0);
	pb(data, 0);
	while (data->b < data->argc - 1)
	{
		data->min_stack_b = min(data);
		data->max_stack_b = max(data);
		cheapest = (t_move){2147483647, 0, 0, 0, 0};
		i = data->b;
		iterate_on_all_stack_b(&cost, data, i, &cheapest);
		do_the_moves(&cheapest, data);
	}
	final_rotation(data);
}
