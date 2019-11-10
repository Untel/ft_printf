/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:07:39 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/10 22:36:28 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_parse_string(char buff[BUFFER_SIZE], t_modifiers mods, va_list args)
{
	char	*res;
	size_t	len;

	res = (char *)va_arg(args, char *);
	res = NULLABLE_STR(res);
	if (mods.precision == -1)
		res = ft_strdup(res);
	else
		res = ft_substr(res, 0, DEFINED_VALUE(mods.precision));
	if (!res || !(res = ft_then_free(res,
		ft_fill(res, mods.padding, mods.padchar, mods.align_left))))
		return (-1);
	len = ft_strcpy(buff, res);
	ft_memdel((void **)&res);
	return (len);
}

int
	ft_parse_char(char buff[BUFFER_SIZE],
		t_modifiers mods, va_list args, char conv)
{
	char	c[2];
	char	*res;
	int		len;

	c[0] = conv == 'c' ? (char)va_arg(args, int) : '%';
	res = ft_fill_c(c, 1, mods.padding, mods.padchar, mods.align_left);
	len = mods.padding > 1 ? mods.padding : 1;
	ft_memcpy(buff, res, len);
	ft_memdel((void **)&res);
	return (len);
}
