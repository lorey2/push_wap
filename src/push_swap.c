/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:31:38 by lorey             #+#    #+#             */
/*   Updated: 2025/07/21 17:01:59 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	error(char *text, t_data *data, int i)
{
	write(1, "ERROR :'(\n", 10);
	write (1, text, ft_strlen(text));
	if (i != 0)
		free(data->stack);
	exit(1);
}

void	is_number_double(char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		if (ft_strlen_skip_zero(argv[i]) > 10)
			error("number too big", data, 0);
		j = -1;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][++j])
			if (argv[i][j] > '9' || argv[i][j] < '0')
				error("you must have only numbers", data, 0);
		j = i;
		while (argv[++j])
			if (!ft_strcmp(argv[i], argv[j]))
				error("there is a number in double", data, 0);
	}
}

void	create_stack(t_data *data, char **argv)
{
	int			i;
	int			j;
	long long	temp;

	i = 0;
	while (++i < data->argc)
	{
		temp = ft_atoi(argv[i]);
		if (temp > 2147483647 || temp < -2147483648)
		{
			free(data->stack);
			error("too big number", data, 0);
		}
		data->stack[i - 1] = temp;
	}
	i = -1;
	while (++i < data->argc - 1)
	{
		j = i;
		while (++j < data->argc - 1)
			if (data->stack[i] == data->stack[j])
				error("there is a number in double", data, 1);
	}
}

void	finish(t_data *data)
{
	if (data->pr_mve != NULL)
	{
		write(1, data->pr_mve, ft_strlen(data->pr_mve));
		write(1, "\n", 1);
		free(data->pr_mve);
	}
	free(data->stack);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.argc = argc;
	data.b = 0;
	data.pr_mve = NULL;
	is_number_double(argv, &data);
	if (argc != 1 && argc != 2)
	{
		data.stack = malloc(data.argc * sizeof(int));
		if (!data.stack)
			return (0);
		create_stack(&data, argv);
		if (is_stack_already_sorted(&data))
			return (finish(&data), 0);
		if (argc == 3)
			return (sa(&data, 0), finish(&data), 0);
		if (argc == 4)
			return (three_args(&data), finish(&data), 0);
		if (argc == 5 || argc == 6)
			return (four_five_args(&data), finish(&data), 0);
		return (first_algo2(&data), finish(&data), 0);
	}
	return (0);
}

//	write_stack(stack, argc, b);
//	123
//	132
//	213
//	231
//	312
//	321
