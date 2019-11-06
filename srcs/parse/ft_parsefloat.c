/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:32:41 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/06 22:51:21 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char
	*ft_join_decim(char *whole, char *decim, t_modifiers mods)
{
	char	*res;
	size_t	len;

	if (mods.alt && !decim)
		decim = ft_strdup("0");
	len = ft_strlen(whole);
	if (decim)
		len += ft_strlen(decim) + 1;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strcat(res, whole);
	ft_strcat(res, ".");
	ft_strcat(res, decim);
	ft_memdel(&whole);
	ft_memdel(&decim);
	return (res);
}

char
	*ft_stringify_float(double val, size_t dig, t_modifiers mods)
{
	int				whole;
	double			decim;
	char			*wholestr;
	char			*decimstr;
	long long int	pow;

	if (dig > 15)
		dig = 15;
	whole = (int)val;
	wholestr = ft_itoa(whole);
	decimstr = NULL;
	if (dig == 0 && !mods.alt)
		return (ft_then_free(wholestr, ft_strdup(wholestr)));
	decim = val - whole;
	if (decim < 0.0)
		decim = -decim;
	pow = ft_pow(10, dig);
	decim *= pow;
	decim += 0.5;
	if ((long long int)decim == pow)
		whole++;
	else
		decimstr = ft_llitoa((long long int)decim);
	return (ft_join_decim(wholestr, decimstr, mods));
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
	if (mods.alt)
		res = ft_itoa(va_arg(args, int));
	else
		res = ft_stringify_float(va_arg(args, double), digits, mods);
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
