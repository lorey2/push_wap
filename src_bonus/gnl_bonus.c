/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:20:25 by lorey             #+#    #+#             */
/*   Updated: 2024/12/28 21:06:40 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	finish(int bytes_read, int i, char *buffer, char **line)
{
	if (bytes_read == 0 && i == 0)
	{
		free(buffer);
		*line = NULL;
		return (0);
	}
	return (1);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		bytes_read;

	i = 0;
	buffer = (char *)malloc(1024);
	if (!buffer)
		return (-1);
	bytes_read = read(0, &buffer[i], 1);
	if (bytes_read < 1)
	{
		free(buffer);
		*line = NULL;
		return (bytes_read);
	}
	while (bytes_read > 0 && buffer[i] != '\n')
		bytes_read = read(0, &buffer[++i], 1);
	if (buffer[i] == '\n')
		i++;
	buffer[i] = '\0';
	*line = buffer;
	return (finish(bytes_read, i, buffer, line));
}
