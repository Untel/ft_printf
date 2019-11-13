/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsebase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:26:07 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/13 01:00:20 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

char
	*ft_apply_base_flags(char *res, t_mod mods, char conv)
{
	size_t prefixlen;

	prefixlen = (ft_is_conv("oO", conv) ? 1 : 2);
	if (mods.padchar == '0' && mods.precision == -1 && mods.padding)
		mods.precision = ((mods.alt || conv == 'p')
			&& mods.padding > prefixlen ?
				mods.padding - (prefixlen) : mods.padding);
	if (!ft_strncmp(res, "0", 3) && mods.precision == 0)
		res = ft_f(res, ft_strdup(""));
	if (res && mods.precision != -1)
		res = ft_f(res, ft_fill(res, mods.precision, '0', 0));
	if (res && (ft_is_conv("pP", conv) || (mods.alt && conv == 'x')))
		res = ft_f(res, ft_strjoin("0x", res));
	else if (res && mods.alt && conv == 'X')
		res = ft_f(res, ft_strjoin("0X", res));
	else if (res && mods.alt && ft_is_conv("oO", conv))
		res = ft_f(res, ft_strjoin("0", res));
	return (res ? ft_f(res,
		ft_fill(res, mods.padding, ' ', mods.align_left)) : NULL);
}

int
	ft_parse_base(char *buff,
	t_mod mods, va_list args, char conv)
{
	char		*res;
	uint64_t	val;

	res = NULL;
	if (conv == 'p')
		val = (uint64_t)va_arg(args, uintptr_t);
	else
		val = ft_get_sized_uint(args, mods);
	if (val == 0 && mods.alt)
		mods.alt = 0;
	if (ft_is_conv("xpP", conv))
		res = ft_nbrbase(val, "0123456789abcdef", 16);
	else if (conv == 'X')
		res = ft_nbrbase(val, "0123456789ABCDEF", 16);
	else if (ft_is_conv("oO", conv))
		res = ft_nbrbase(val, "01234567", 8);
	if (!res || !(res = ft_apply_base_flags(res, mods, conv)))
		return (-1);
	val = ft_strcpy(buff, res);
	ft_memdel((void **)&res);
	return ((int)val);
}
