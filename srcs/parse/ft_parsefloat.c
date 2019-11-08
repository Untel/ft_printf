/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:32:41 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/08 20:01:47 by adda-sil         ###   ########.fr       */
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
		// len += digits;
		len += (mods.trail ? digits : decim_len);
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
		while (mods.trail && decim_len++ < digits)
			ft_strcat(res, "0");
		ft_memdel(&decim);
	}
	ft_memdel(&whole);
	return (res);
}

char
	*ft_stringify_float(long double val, size_t dig, t_modifiers mods)
{
	int64_t		whole;
	uint64_t	pow;
	long double	decim;
	char		*wholestr;
	char		*decimstr;
	char		prev[999];

	prev[0] = 0;
	whole = (int64_t)val;
	decimstr = NULL;
	decim = val - whole;
	if (decim < 0.0)
		decim = -decim;
	pow = ft_pow(10, dig);
	while (decim > 0.0 && decim < 1.0)
	{
		decim *= 10;
		dig--;
		ft_strcat(prev, "0");
		printf("have to push %s\n", prev);
	}
	decim *= pow;
	decim += 0.5;
	if (!mods.trail)
		while ((uint64_t)decim % 10 == 0)
			decim /= 10;
	if ((uint64_t)decim == pow)
		whole++;
	if (dig > 0)
		decimstr = ft_strjoin(prev, ft_lluitoa((uint64_t)decim));
	wholestr = ft_itoa_wrapper((uint64_t)(whole < 0 ? -whole : whole),
		mods.sep, whole < 0);
	return (ft_join_decim(wholestr, decimstr, dig, mods));
}

char
	*ft_stringify_exp(char conv, long double arg, size_t dig, t_modifiers mods)
{
	char		*res;
	int			exp;
	char		expstr[BUFFER_SIZE];
	long double	val;

	if (conv == 'g')
		mods.trail = 0;
	exp = 0;
	val = arg < 0 ? -arg : arg;
	if (val > 1)
		while (val > 10.0)
		{
			val /= 10;
			exp += 1;
		}
	else
		while (val < 1)
		{
			val *= 10;
			exp -= 1;
		}
	printf("Initial val is %llg\n", arg);
	if (conv == 'g' && (exp > -4 || exp >= mods.precision))
		return (ft_stringify_float(arg, dig, mods));
	val = arg < 0 ? -val : val;
	res = ft_stringify_float(val, dig, mods);
	ft_sprintf(expstr, "e%+03d", exp);
	res = ft_then_free(res, ft_strjoin(res, expstr));
	return (res);
}

char
	*ft_apply_float_precision(char *res, t_modifiers mods)
{
	if (!(res = ft_strdup(res)))
		return (NULL);
	if (mods.sign)
		res = ft_then_free(res, ft_add_sign(mods.sign, res));
	res = ft_then_free(res, ft_fill(res, mods.padding, ' ', mods.align_left));
	return (res);
}

char
	*ft_apply_float_flags(char *res, t_modifiers mods)
{
	res = ft_fill(res, (mods.sign && mods.padding > 0 ?
		mods.padding - 1 : mods.padding), mods.padchar, mods.align_left);
	if (mods.sign)
		res = ft_then_free(res, ft_add_sign(mods.sign, res));
	return (res);
}

size_t
	ft_parse_float(char buff[BUFFER_SIZE],
		t_modifiers mods, va_list args, char conv)
{
	int			digits;
	char		*res;
	size_t		len;
	long double	val;

	val = ft_get_sized_double(args, mods);
	digits = mods.precision == -1 ? 6 : mods.precision;
	if (conv == 'f')
		res = ft_stringify_float(val, digits, mods);
	else if (conv == 'e' || conv == 'g')
		res = ft_stringify_exp(conv, val, digits, mods);
	if (res && *res == '-')
	{
		res = ft_then_free(res, ft_strdup(res + 1));
		mods.sign = '-';
	}
	res = ft_then_free(res, ft_apply_float_flags(res, mods));
	len = ft_strcpy(buff, res);
	ft_memdel(&res);
	return (len);
}
