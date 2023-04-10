/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_query.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 12:24:56 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/04/08 13:51:10 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pf_numlen(long n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int	pf_unumlen(unsigned long n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

size_t	pf_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0UL);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	pf_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*pf_strchr(const char *s, int c)
{
	int		i;
	char	chr;

	i = 0;
	chr = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return ((char *)(&s[i]));
		i++;
	}
	if (chr == '\0')
		return ((char *)(&s[i]));
	return (0);
}
