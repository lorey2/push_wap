/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_pa_pb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:49:18 by lorey             #+#    #+#             */
/*   Updated: 2024/12/18 15:48:00 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int silent)
{
	int	temp;

	if ((data->argc - 1) - data->b >= 2)
	{
		temp = data->stack[data->b];
		data->stack[data->b] = data->stack[data->b + 1];
		data->stack[data->b + 1] = temp;
	}
	if (silent == 0)
		final_test(data, "sa");
}

void	sb(t_data *data, int silent)
{
	int	temp;

	data->b--;
	if (data->b >= 2)
	{
		temp = data->stack[data->b];
		data->stack[data->b] = data->stack[data->b - 1];
		data->stack[data->b - 1] = temp;
	}
	data->b++;
	if (silent == 0)
		final_test(data, "sb");
}

void	ss(t_data *data, int silent)
{
	sa(data, 1);
	sb(data, 1);
	if (silent == 0)
		final_test(data, "ss");
}

void	pa(t_data *data, int silent)
{
	if (data->b > 0)
		data->b = data->b - 1;
	if (silent == 0)
		final_test(data, "pa");
}

void	pb(t_data *data, int silent)
{
	if (data->b < data->argc - 1)
		data->b = data->b + 1;
	if (silent == 0)
		final_test(data, "pb");
}
