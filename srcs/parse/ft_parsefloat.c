/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:32:41 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/08 17:06:49 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double
	ft_get_sized_double(va_list args, t_modifiers mods)
{
	long double val;

	if (mods.size <= N)
		val = (long double)va_arg(args, double);
	else if (mods.size > N)
		val = va_arg(args, long double);
	else
		val = 0;
	return (val);
}

char
	*ft_join_decim(char *whole, char *decim, int digits, t_modifiers mods)
{
	char	*res;
	size_t	len;
	size_t	decim_len;

	len = ft_strlen(whole);
	if (decim)
	{
		len += digits;
		decim_len = ft_strlen(decim);
	}
	if (decim || mods.alt)
		len += 1;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strcat(res, whole);
	if (decim || mods.alt)
		ft_strcat(res, ".");
	if (decim)
	{
		ft_strcat(res, decim);
		while (decim_len++ < digits)
			ft_strcat(res, "0");
		ft_memdel(&decim);
	}
	ft_memdel(&whole);
	return (res);
}

char
	*ft_stringify_float(double val, size_t dig, t_modifiers mods)
{
	int64_t		whole;
	long double	decim;
	char		*wholestr;
	char		*decimstr;
	uint64_t	pow;

	whole = (int64_t)val;
	decimstr = NULL;
	decim = val - whole;
	if (decim < 0.0)
		decim = -decim;
	pow = ft_pow(10, dig);
	decim *= pow;
	decim += 0.5;
	if ((uint64_t)decim == pow)
		whole++;
	if (dig > 0)
		decimstr = ft_lluitoa((uint64_t)decim);
	wholestr = ft_itoa_wrapper((uint64_t)(whole < 0 ? -whole : whole),
		mods.sep, whole < 0);
	return (ft_join_decim(wholestr, decimstr, dig, mods));
}

char
	*ft_apply_float_precision(char *res, t_modifiers mods)
{
	if (!(res = ft_strdup(res)))
		return (NULL);
	if (mods.precision > 0)
		res = ft_then_free(res, ft_fill(res, mods.precision, '0', 0));
	if (mods.sign)
		res = ft_then_free(res, ft_add_sign(mods.sign, res));
	res = ft_then_free(res, ft_fill(res, mods.padding, ' ', mods.align_left));
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
			res = ft_then_free(res, ft_add_sign(mods.sign, res));
	}
	return (res);
}

size_t
	ft_parse_float(char buff[BUFFER_SIZE],
		t_modifiers mods, va_list args, char conv)
{
	int		digits;
	char	*res;
	size_t	len;

	digits = mods.precision == -1 ? 6 : mods.precision;
	res = ft_stringify_float(ft_get_sized_double(args, mods), digits, mods);
	if (res && *res == '-')
	{
		res = ft_then_free(res, ft_strdup(res + 1));
		mods.sign = '-';
	}
	if (!res || !(res = ft_then_free(res, ft_apply_float_flags(res, mods))))
		return (-1);
	len = ft_strcpy(buff, res);
	ft_memdel(&res);
	return (len);
}
