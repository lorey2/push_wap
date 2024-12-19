/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:03:30 by lorey             #+#    #+#             */
/*   Updated: 2024/12/18 15:49:07 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data, int silent)
{
	int	temp;
	int	back;

	back = data->b;
	if ((data->argc - 1) - data->b >= 2)
	{
		data->b--;
		temp = data->stack[data->b + 1];
		while (++data->b < data->argc - 2)
			data->stack[data->b] = data->stack[data->b + 1];
		data->stack[data->argc - 2] = temp;
	}
	data->b = back;
	if (silent == 0)
		final_test(data, "ra");
}

void	rb(t_data *data, int silent)
{
	int	temp;
	int	back;

	back = data->b;
	if (data->b >= 2)
	{
		temp = data->stack[data->b - 1];
		while (--data->b > 0)
			data->stack[data->b] = data->stack[data->b - 1];
		data->stack[0] = temp;
	}
	data->b = back;
	if (silent == 0)
		final_test(data, "rb");
}

void	rr(t_data *data, int silent)
{
	ra(data, 1);
	rb(data, 1);
	if (silent == 0)
		final_test(data, "rr");
}
