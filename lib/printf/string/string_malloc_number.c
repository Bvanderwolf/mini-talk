/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_malloc_number.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 13:33:14 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/04/08 13:50:34 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_uitoh(unsigned int n, const char *hex_characters)
{
	int		len;
	char	*str;
	int		i;

	len = pf_numlen(n, 16);
	i = len - 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = hex_characters[n % 16];
		n /= 16;
		i--;
	}
	return (str);
}

char	*pf_uitoa(unsigned int n)
{
	int		len;
	char	*str;
	int		i;

	len = pf_numlen(n, 10);
	i = len - 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}

char	*pf_itoa(int n)
{
	int		len;
	int		i;
	char	*str;

	len = pf_numlen(n, 10);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		if (n > 0)
			str[i] = (n % 10) + 48;
		else
			str[i] = (n % 10 * -1) + 48;
		n /= 10;
		i--;
	}
	return (str);
}

char	*pf_ultohex(unsigned long n)
{
	const char	*hex_characters = "0123456789abcdef";
	char		*str;
	int			len;
	int			i;

	len = pf_unumlen(n, 16) + 2;
	i = len - 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str[0] = '0';
	str[1] = 'x';
	if (n == 0UL)
		str[2] = '0';
	while (n != 0UL)
	{
		str[i] = hex_characters[n % 16];
		n /= 16;
		i--;
	}
	return (str);
}
