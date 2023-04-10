/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion_number_state.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 13:45:14 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/04/08 13:51:10 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_number_argument_length(t_cstate *state)
{
	int	len;

	len = pf_strlen(state->conversion);
	if (get_decimal_prefix(state) != NULL)
		len--;
	return (len);
}

int	get_precision_number_argument_length(t_cstate *state)
{
	int	len;

	len = pf_strlen(state->conversion);
	if (pf_atol(state->conversion) < 0)
		len--;
	return (len);
}

int	get_precision_modifier(t_cstate *state)
{
	int	arg_len;

	if (pf_strchr(NUMBER_CONVERSIONS, state->specifier) != NULL)
	{
		arg_len = get_precision_number_argument_length(state);
		if (state->precision <= arg_len)
			return (0);
		return (state->precision - arg_len);
	}
	else if (state->specifier == 's')
	{
		arg_len = pf_strlen(state->conversion);
		if (state->precision < arg_len)
			return (state->precision - arg_len);
	}
	return (0);
}
