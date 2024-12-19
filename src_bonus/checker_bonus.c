/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:57:19 by lorey             #+#    #+#             */
/*   Updated: 2024/12/19 21:51:29 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>

int	is_stack_already_sorted(t_data *data)
{
	int	i;

	i = -1;
	if (data->b != 0)
		return (0);
	while (++i < data->argc - 2)
		if (data->stack[i] > data->stack[i + 1])
			return (0);
	return (1);
}

void	error(char *text)
{
	write(1, "ERROR :'(\n", 10);
	write(1, text, ft_strlen(text));
	exit(1);
}

void	is_number_double(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) > 10)
			error("number too big\n");
		j = -1;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][++j])
			if (argv[i][j] > '9' || argv[i][j] < '0')
				error("you must have only numbers\n");
		j = i;
		while (argv[++j])
			if (!ft_strcmp(argv[i], argv[j]))
				error("there is a number in double\n");
	}
}

void	create_stack(t_data *data, char **argv)
{
	int			i;
	long long	temp;

	i = 0;
	while (++i < data->argc)
	{
		temp = ft_atoi(argv[i]);
		if (temp > 2147483647 || temp < -2147483648)
		{
			free(data->stack);
			error("too big number\n");
		}
		data->stack[i - 1] = temp;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.argc = argc;
	data.b = 0;
	data.stack = malloc(data.argc * sizeof(int));
	if (!data.stack)
		return (0);
	is_number_double(argv);
	create_stack(&data, argv);
	g_n_l_execute(&data);
	if (is_stack_already_sorted(&data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free(data.stack), 0);
}