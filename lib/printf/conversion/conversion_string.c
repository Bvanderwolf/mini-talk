/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion_string.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 12:18:22 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/04/08 13:50:49 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

const char	*get_decimal_prefix(t_cstate *state)
{
	if (state->specifier != 'i' && state->specifier != 'd')
		return (NULL);
	if (pf_atoi(state->conversion) < 0)
		return ("-");
	if (has_flag(state, PLUS_PREFIX))
		return ("+");
	else if (has_flag(state, BLANK_PREFIX))
		return (" ");
	return (NULL);
}

const char	*get_alternate_form_prefix(t_cstate *state)
{
	if (state->specifier == 'x')
		return ("0x");
	else if (state->specifier == 'X')
		return ("0X");
	return (NULL);
}

char	*conversion_strdup(const char *s1)
{
	if (s1 == NULL)
		return (conversion_strdup("(null)"));
	return (pf_strdup(s1));
}

char	*conversion_uitoh(va_list *args, t_cstate state)
{
	if (state.specifier == 'x')
		return (pf_uitoh(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (state.specifier == 'X')
		return (pf_uitoh(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	return (NULL);
}
