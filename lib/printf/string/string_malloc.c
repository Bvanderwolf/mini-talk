/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_malloc.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 15:58:17 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/04/08 13:50:55 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_strdup(const char *s1)
{
	size_t	src_size;
	char	*cpy;

	if (s1 == NULL)
		return (NULL);
	src_size = pf_strlen(s1) + 1;
	cpy = (char *)malloc(src_size * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	pf_strlcpy(cpy, s1, src_size);
	return (cpy);
}

char	*pf_ctostr(int c)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = (char)c;
	str[1] = '\0';
	return (str);
}
