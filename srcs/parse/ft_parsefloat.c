/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:32:41 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/06 15:43:47 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char
	*ft_stringify_float(double val, size_t dig)
{
	int				whole;
	double			decim;
	char*			join[3];
	long long int	pow;

	if (dig > 15)
		dig = 15;
	whole = (int)val;
	join[0] = ft_itoa(whole);
	if (dig == 0)
		return (ft_strdup(join[0]));
	decim = val - whole;
	if (decim < 0.0)
		decim = -decim;
	pow = ft_pow(10, dig);
	decim *= pow;
	decim += 0.5;
	join[1] = dig == 0 ? "" : ".";
	join[2] = dig == 0 ? "" : "0";
	if ((long long int)decim == pow)
		whole++;
	else
		join[2] = ft_llitoa((long long int)decim);
	return (ft_strmjoin(3, (char **)join, ""));
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
		return (ft_apply_float_precision(res, mods));
	else
	{
		res = ft_fill(res, (mods.sign ? mods.padding - 1 : mods.padding),
			mods.padchar, mods.align_left);
		if (mods.sign)
			res = ft_strjoin(ft_char_to_str(mods.sign), res);
	}
	return (res);
}

size_t
	ft_parse_float(char buff[BUFFER_SIZE],
		t_modifiers mods, va_list args, char conv)
{
	int		digits;
	char	*res;

	digits = mods.precision == -1 ? 6 : mods.precision;
	if (mods.alt)
		res = ft_itoa(va_arg(args, int));
	else
		res = ft_stringify_float(va_arg(args, double), digits);
	if (*res == '-' && res++)
		mods.sign = '-';
	ft_strcpy(buff, res);
	res = ft_apply_float_flags(res, mods);
	return (ft_strcpy(buff, res));
}
