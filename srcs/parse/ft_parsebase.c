/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsebase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:26:07 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/10 04:57:08 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char
	*ft_apply_base_flags(char *res, t_modifiers mods, char conv)
{
	if (res && mods.precision != -1)
		res = ft_then_free(res, ft_fill(res, mods.precision, '0', 0));
	if (res && (conv == 'p' || (mods.alt && conv == 'x')))
		res = ft_then_free(res, ft_strjoin("0x", res));
	else if (res && mods.alt && conv == 'X')
		res = ft_then_free(res, ft_strjoin("0X", res));
	else if (res && mods.alt && conv == 'o')
		res = ft_then_free(res, ft_strjoin("0", res));
	return (res ? ft_then_free(res,
		ft_fill(res, mods.padding, mods.padchar, mods.align_left)) : NULL);
}

size_t
	ft_parse_base(char buff[BUFFER_SIZE],
	t_modifiers mods, va_list args, char conv)
{
	char		*res;
	char		*tmp;
	uint64_t	val;

	if (conv == 'p')
		val = (uint64_t)va_arg(args, uintptr_t);
	else
		val = ft_get_sized_uint(args, mods);
	if (conv == 'x' || conv == 'p')
		res = ft_nbrbase(val, "0123456789abcdef", 16);
	else if (conv == 'X')
		res = ft_nbrbase(val, "0123456789ABCDEF", 16);
	else if (conv == 'o')
		res = ft_nbrbase(val, "01234567", 8);
	if (!res || !(res = ft_apply_base_flags(res, mods, conv)))
		return (-1);
	val = ft_strcpy(buff, res);
	ft_memdel(&res);
	return (val);
}
