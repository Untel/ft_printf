/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:07:39 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/06 20:58:43 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t
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
	res = ft_then_free(res,
		ft_fill(res, mods.padding, mods.padchar, mods.align_left));
	len = ft_strcpy(buff, res);
	ft_memdel(&res);
	return (len);
}

size_t
	ft_parse_char(char buff[BUFFER_SIZE], t_modifiers mods, va_list args)
{
	char c[2];
	char *res;

	c[0] = (char)va_arg(args, int);
	c[1] = 0;
	res = ft_fill(c, mods.padding, mods.padchar, mods.align_left);
	ft_strcpy(buff, res);
	ft_memdel(&res);
	return (mods.padding > 1 ? mods.padding : 1);
}
