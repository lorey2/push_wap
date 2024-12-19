/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:26:58 by lorey             #+#    #+#             */
/*   Updated: 2024/12/12 04:45:11 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

void	clean(t_data *data, char *text)
{
	write(1, text, ft_strlen(text));
	free(data->pr_mve);
	data->pr_mve = NULL;
}

void	the_comparaisons(t_data *data, char *curr_move)
{
	if ((!ft_strcmp(data->pr_mve, "ra") && !ft_strcmp(curr_move, "rra"))
		|| (!ft_strcmp(data->pr_mve, "rb") && !ft_strcmp(curr_move, "rrb"))
		|| (!ft_strcmp(data->pr_mve, "sa") && !ft_strcmp(curr_move, "sa"))
		|| (!ft_strcmp(data->pr_mve, "sb") && !ft_strcmp(curr_move, "sb"))
		|| (!ft_strcmp(data->pr_mve, "pa") && !ft_strcmp(curr_move, "pb"))
		|| (!ft_strcmp(data->pr_mve, "rra") && !ft_strcmp(curr_move, "ra"))
		|| (!ft_strcmp(data->pr_mve, "rrb") && !ft_strcmp(curr_move, "rb"))
		|| (!ft_strcmp(data->pr_mve, "pb") && !ft_strcmp(curr_move, "pa")))
	{
		free(data->pr_mve);
		data->pr_mve = NULL;
	}
	else if (!ft_strcmp(data->pr_mve, "ra") && !ft_strcmp(curr_move, "rb"))
		clean(data, "rr\n");
	else if (!ft_strcmp(data->pr_mve, "rra") && !ft_strcmp(curr_move, "rrb"))
		clean (data, "rrr\n");
	else if (!ft_strcmp(data->pr_mve, "sa") && !ft_strcmp(curr_move, "sb"))
		clean(data, "ss\n");
	else
	{
		write(1, data->pr_mve, ft_strlen(data->pr_mve));
		write(1, "\n", 1);
		free(data->pr_mve);
		data->pr_mve = ft_strdup(curr_move);
	}
}

void	final_test(t_data *data, char *curr_move)
{
	if (data->pr_mve == NULL)
	{
		data->pr_mve = ft_strdup(curr_move);
		curr_move = NULL;
	}
	else
		the_comparaisons(data, curr_move);
}
