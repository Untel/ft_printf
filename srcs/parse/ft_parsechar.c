/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:07:39 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/13 01:00:20 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include <wchar.h>

int
	ft_parse_string(char *buff,
		t_mod mods, va_list args, char conv)
{
	wchar_t	*ptr;
	char	*res;
	size_t	len;

	mods.size = conv == 'S' ? L : mods.size;
	if (mods.size != L)
		res = va_arg(args, char *);
	else
	{
		ptr = va_arg(args, wchar_t *);
		if (ptr && (len = ft_wchars_to_str(buff, ptr)) == -1)
			return (-1);
	}
	res = ft_strdup(NULLABLE_STR((mods.size == L ? buff : res)));
	if (mods.precision > -1)
		res = ft_f(res, ft_subwstr(res, 0, DEFINED_VALUE(mods.precision)));
	if (!res || !(res = ft_f(res,
		ft_fill(res, mods.padding, mods.padchar, mods.align_left))))
		return (-1);
	len = ft_strcpy(buff, res);
	ft_memdel((void **)&res);
	return (len);
}

int
	ft_parse_char(char *buff,
		t_mod mods, va_list args, char conv)
{
	int		c;
	char	*res;
	int		len;

	mods.size = conv == 'C' ? L : mods.size;
	c = ft_is_conv("cC", conv) ? va_arg(args, int) : '%';
	if (mods.size <= N && (len = mods.padding > 1 ? mods.padding : 1))
		res = ft_fill_c(c, mods.padding, mods.padchar, mods.align_left);
	else
	{
		len = ft_wchar_to_char(buff, c);
		if (len > -1)
		{
			res = ft_fill(buff, mods.padding, mods.padchar, mods.align_left);
			len = (int)((int)mods.padding > len ? mods.padding : len);
		}
	}
	if (len > -1)
	{
		ft_memcpy(buff, res, len);
		ft_memdel((void **)&res);
	}
	return (len);
}
