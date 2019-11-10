/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseexp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:25:32 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/10 19:54:34 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char
	*ft_stringify_exp(char conv, long double arg, size_t dig, t_modifiers mods)
{
	char		*res;
	int			exp;
	char		expstr[BUFFER_SIZE];
	long double	val;

	mods.trail = conv == 'g' ? 0 : 1;
	exp = 0;
	if ((val = arg < 0 ? -arg : arg) > 1)
		while (val > 1 && val > 10.0 && (exp++ || 1))
			val /= 10;
	else
		while (val < 1 && (exp-- || 1))
			val *= 10;
	printf("Exp %d | is %d\n", exp, exp > -4);
	if (conv == 'g' &&
		((exp < 0 && exp > -4) || (exp > 0 && exp <= mods.precision)))
		return (ft_stringify_float(arg, dig, mods));
	val = arg < 0 ? -val : val;
	if (!(res = ft_stringify_float(val, dig, mods)))
		return (NULL);
	ft_sprintf(expstr, "e%+03d", exp);
	res = ft_then_free(res, ft_strjoin(res, expstr));
	return (res);
}
