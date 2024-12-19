/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:03:30 by lorey             #+#    #+#             */
/*   Updated: 2024/12/18 16:15:03 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_data *data)
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
}

void	rb(t_data *data)
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
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
