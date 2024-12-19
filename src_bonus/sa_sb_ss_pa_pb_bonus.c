/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_pa_pb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:49:18 by lorey             #+#    #+#             */
/*   Updated: 2024/12/18 16:14:50 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_data *data)
{
	int	temp;

	if ((data->argc - 1) - data->b >= 2)
	{
		temp = data->stack[data->b];
		data->stack[data->b] = data->stack[data->b + 1];
		data->stack[data->b + 1] = temp;
	}
}

void	sb(t_data *data)
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
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}

void	pa(t_data *data)
{
	if (data->b > 0)
		data->b = data->b - 1;
}

void	pb(t_data *data)
{
	if (data->b < data->argc - 1)
		data->b = data->b + 1;
}
