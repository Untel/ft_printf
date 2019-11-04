/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:32:41 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/04 10:25:07 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char
	*ft_stringify_float(double val, size_t dig)
{
	char	*str = "";
	int		whole;
	double	decim;

	whole = (int)val;
	decim = val - whole;
	printf("%d | %f: %f\n", whole, decim, val);
	decim *= ft_pow(dig, 10);
	printf("%d | %f: %f\n", whole, decim, val);
	return (str);
}

char
	*ft_apply_float_precision(char *res, t_modifiers mods)
{
	if (mods.precision > 0)
		res = ft_fill(res, mods.precision, '0', 0);
	if (mods.sign)
		res = ft_strjoin(ft_char_to_str(mods.sign), res);
	res = ft_fill(res, mods.padding, ' ', mods.align_left);
	return (res);
}

char
	*ft_apply_float_flags(char *res, t_modifiers mods)
{
	if (mods.precision != -1)
		return (ft_apply_int_precision(res, mods));
	else
	{
		res = ft_fill(res, (mods.sign ? mods.padding - 1 : mods.padding),
			mods.padchar, mods.align_left);
		if (mods.sign)
			res = ft_strjoin(ft_char_to_str(mods.sign), res);
	}
	return (res);
}

char
	*ft_parse_float(t_modifiers mods, va_list args, char conv)
{
	char	*res;

	res = ft_stringify_float(va_arg(args, double), 3);
	// if (conv != 'u')
	// 	res = ft_itoa((int)va_arg(args, int));
	// else
	// 	res = ft_uitoa((unsigned int)va_arg(args, unsigned int));
	// if (*res == '-' && res++)
	// 	mods.sign = '-';
	// return (ft_apply_int_flags(res, mods));
	return (res);
}
