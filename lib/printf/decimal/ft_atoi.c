/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 15:35:20 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/04/08 13:49:58 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t'
		|| c == '\r' || c == '\n'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

static int	skip_white_space(const char *str, int *multiplyer)
{
	int		i;
	char	c;
	int		is_prefixed;

	i = 0;
	is_prefixed = 0;
	c = str[i];
	while ((is_whitespace(c) == 1 || c == '-' || c == '+')
		&& is_prefixed == 0)
	{
		if (c == '-' || c == '+')
		{
			if (c == '-')
				*multiplyer = -1;
			is_prefixed = 1;
		}
		i++;
		c = str[i];
	}
	if (pf_isdigit(c) == 0)
		return (-1);
	return (i);
}

int	pf_atoi(const char *str)
{
	int		result;
	int		i;
	char	c;
	int		multiplyer;

	result = 0;
	multiplyer = 1;
	i = skip_white_space(str, &multiplyer);
	if (i == -1)
		return (0);
	c = str[i];
	while (pf_isdigit(c) == 1)
	{
		result += (c - 48);
		if (pf_isdigit(str[i + 1]) == 1)
			result *= 10;
		i++;
		c = str[i];
	}
	result *= multiplyer;
	return (result);
}

long	pf_atol(const char *str)
{
	long	result;
	int		i;
	char	c;
	int		multiplyer;

	result = 0L;
	multiplyer = 1;
	i = skip_white_space(str, &multiplyer);
	if (i == -1)
		return (0);
	c = str[i];
	while (pf_isdigit(c) == 1)
	{
		result += (c - 48);
		if (pf_isdigit(str[i + 1]) == 1)
			result *= 10;
		i++;
		c = str[i];
	}
	result *= multiplyer;
	return (result);
}
