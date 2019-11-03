/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:07:39 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/03 18:27:54 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char
	*ft_parse_string(t_modifiers mods, va_list args)
{
	char *res;

	res = (char *)va_arg(args, char *);
	if (mods.precision == -1)
		res = ft_strdup(res);
	else
		res = ft_substr(res, 0, mods.precision == -2 ? 0 : mods.precision);
	res = ft_fill(res, mods.padding, mods.padchar, mods.align_left);
	return (res);
}

char*
	ft_parse_char(t_modifiers mods, va_list args)
{
	char *res;

	res = ft_char_to_str((char)va_arg(args, int));
	res = ft_fill(res, mods.padding, mods.padchar, mods.align_left);
	return (res);
}
