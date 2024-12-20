/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_min_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:18:02 by lorey             #+#    #+#             */
/*   Updated: 2024/12/20 15:03:01 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_data *data)
{
	int	max;
	int	i;

	i = 0;
	max = data->stack[0];
	while (++i < data->b)
		if (data->stack[i] > max)
			max = data->stack[i];
	return (max);
}

int	min(t_data *data)
{
	int	min;
	int	i;

	i = 0;
	min = data->stack[0];
	while (++i < data->b)
		if (data->stack[i] < min)
			min = data->stack[i];
	return (min);
}

int	min_a(t_data *data)
{
	int	i;
	int	min;

	min = data->stack[data->b];
	i = data->b;
	while (++i < data->argc - 1)
		if (data->stack[i] < min)
			min = data->stack[i];
	return (min);
}

int	max_a(t_data *data)
{
	int	i;
	int	max;

	max = data->stack[data->b];
	i = data->b;
	while (++i < data->argc - 1)
		if (data->stack[i] > max)
			max = data->stack[i];
	return (max);
}
