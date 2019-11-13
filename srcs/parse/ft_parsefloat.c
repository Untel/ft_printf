/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:32:41 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/13 01:00:20 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

long double
	ft_get_sized_double(va_list args, t_mod mods)
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
	*ft_join_decim(char *whole, char *decim, size_t digits, t_mod mods)
{
	char	*res;
	size_t	len;
	size_t	decim_len;

	len = ft_strlen(whole);
	if (decim && (decim_len = ft_strlen(decim)))
		len += (mods.trail ? digits : decim_len);
	while (!mods.trail && decim && decim[--decim_len] == '0')
		decim[decim_len] = 0;
	if ((decim && *decim) || mods.alt)
		len += 1;
	if (!(res = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strcat(res, whole);
	if ((decim && *decim) || mods.alt)
		ft_strcat(res, ".");
	if (decim)
	{
		ft_strcat(res, decim);
		while (mods.trail && decim_len++ < digits)
			ft_strcat(res, "0");
		ft_memdel((void **)&decim);
	}
	ft_memdel((void **)&whole);
	return (res);
}

char
	*ft_stringify_float(long double val, size_t dig, t_mod mods)
{
	int64_t		w;
	long double	decim;
	char		*wstr;
	char		*decimstr;
	int			to_reduce;

	w = (int64_t)val;
	if (mods.trail == 0)
		dig -= ft_intlen((w < 0 ? -w : w));
	dig = dig < 0 ? 0 : dig;
	decimstr = NULL;
	decim = (val - w) < 0 ? -(val - w) : (val - w);
	to_reduce = 0;
	if (decim <= 0.1 && (to_reduce = 1))
		decim += 0.1;
	decim *= ft_pow(10, dig);
	decim += .5;
	if ((uint64_t)decim == ft_pow(10, dig) && w++)
		decim = 0;
	wstr = ft_itoa_wrapper((uint64_t)(w < 0 ? -w : w), mods.sep, w < 0);
	if (dig > 0 && !(decimstr = ft_lluitoa((uint64_t)decim)))
		return (NULL);
	if (to_reduce && decimstr && *decimstr == '1')
		*decimstr = '0';
	return (ft_join_decim(wstr, decimstr, dig, mods));
}

char
	*ft_apply_float_flags(char *res, t_mod mods)
{
	if (!(res = ft_fill(res, (mods.sign && mods.padding > 0 ?
		mods.padding - 1 : mods.padding), mods.padchar, mods.align_left)))
		return (NULL);
	if (mods.sign)
		res = ft_f(res, ft_add_sign(mods.sign, res));
	return (res);
}

int
	ft_parse_float(char *buff,
		t_mod mods, va_list args, char conv)
{
	int			digits;
	char		*res;
	size_t		len;
	long double	val;

	res = NULL;
	val = ft_get_sized_double(args, mods);
	digits = mods.precision == -1 ? 6 : mods.precision;
	if (ft_is_conv("fF", conv))
		res = ft_stringify_float(val, digits, mods);
	else if (ft_is_conv("eEgG", conv))
		res = ft_stringify_exp(conv, val, digits, mods);
	if (res && *res == '-' && (res = ft_f(res, ft_strdup(res + 1))))
		mods.sign = '-';
	if (!res || (!(res = ft_f(res, ft_apply_float_flags(res, mods)))))
		return (-1);
	len = ft_strcpy(buff, res);
	ft_memdel((void **)&res);
	return (len);
}
