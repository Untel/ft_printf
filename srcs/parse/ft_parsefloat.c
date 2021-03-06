/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:32:41 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/17 17:20:07 by adda-sil         ###   ########.fr       */
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
	if (decim)
	{
		decim_len = ft_strlen(decim);
		while (!mods.trail && decim[--decim_len] == '0')
			decim[decim_len] = 0;
		decim_len = ft_strlen(decim);
		len += (mods.trail ? digits : decim_len);
	}
	if ((decim && *decim) || mods.alt)
		len += 1;
	if (!(res = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if ((len = ft_strcpy(res, whole)) && (mods.alt || decim))
		res[len++] = '.';
	if (decim)
	{
		len += ft_strcpy(&res[len], decim);
		while (mods.trail && decim_len++ < digits)
			res[len++] = '0';
		ft_memdel((void **)&decim);
	}
	ft_memdel((void **)&whole);
	return (res);
}

char
	*ft_stringify_float(long double val, size_t dig, t_mod mods)
{
	uint64_t	w;
	long double	decim;
	char		*wstr;
	char		*decimstr;
	int			to_reduce;

	w = (uint64_t)val;
	if (mods.trail == 0)
		dig -= ft_uintlen(w);
	dig = dig < 0 ? 0 : dig;
	decimstr = NULL;
	decim = val - w;
	to_reduce = 0;
	if (decim <= 0.1 && (to_reduce = 1))
		decim += 0.1;
	decim *= ft_pow(10, dig);
	decim += .5;
	if ((uint64_t)decim == ft_pow(10, dig) && (w++))
		decim = 0;
	wstr = ft_itoa_wrapper(w, mods.sep, 0);
	if (dig > 0 && !(decimstr = ft_lluitoa((uint64_t)decim)))
		return (NULL);
	if (to_reduce && decimstr && *decimstr == '1')
		*decimstr = '0';
	return (ft_join_decim(wstr, decimstr, dig, mods));
}

char
	*ft_apply_float_flags(char *res, t_mod mods)
{
	if (mods.padchar == '0')
		if (!(res = ft_f(res, ft_fill(res, (mods.sign && mods.padding > 0 ?
			mods.padding - 1 : mods.padding), '0', 0))))
			return (NULL);
	if (mods.sign)
		res = ft_f(res, ft_add_sign(mods.sign, res));
	if (mods.padchar == ' ')
		if (!(res = ft_f(res,
			ft_fill(res, mods.padding, ' ', mods.align_left))))
			return (NULL);
	return (res);
}

int
	ft_parse_float(char **buff, t_mod mods, va_list args)
{
	int			digits;
	char		*res;
	long double	val;

	res = NULL;
	val = ft_get_sized_double(args, mods);
	digits = mods.precision == -1 ? 6 : mods.precision;
	if (val < 0)
		mods.sign = '-';
	if (ft_is_conv("fF", mods.conv))
		res = ft_stringify_float(val < 0 ? -val : val, digits, mods);
	else if (ft_is_conv("eEgG", mods.conv))
		res = ft_stringify_exp(val < 0 ? -val : val, digits, mods);
	if (!res || (!(res = ft_apply_float_flags(res, mods))))
		return (-1);
	*buff = res;
	return (ft_strlen(res));
}
