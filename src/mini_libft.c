/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:04:19 by lorey             #+#    #+#             */
/*   Updated: 2024/12/29 15:28:31 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

size_t	ft_strlen_skip_zero(const char *s)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	while (s[size])
		size++;
	return (size - i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

long long	ft_atoi(const char *str)
{
	long long		i;
	long long		number;
	long long		neg;

	i = 0;
	number = 0;
	neg = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'\
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number += (str[i] - '0');
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			number *= 10;
		i++;
	}
	return (number *= neg);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*point;

	i = 0;
	point = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!point)
		return (0);
	while (++i <= ft_strlen(s1))
		point[i - 1] = s1[i - 1];
	point[i - 1] = '\0';
	return (point);
}
