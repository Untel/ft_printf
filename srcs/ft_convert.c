/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:39:54 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/30 18:36:59 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char*
	ft_parse_int(t_modifiers mods, va_list args)
{
	char *res;

	res = ft_itoa((int)va_arg(args, int));
	if (mods.sign && *res != '-')
		res = ft_strjoin(ft_char_to_str(mods.sign), res);
	res = ft_fill_padding(res, mods, 'd');
	return (res);
}

char*
	ft_parse_string(t_modifiers mods, va_list args)
{
	char *res;

	res = (char *)va_arg(args, char *);
	if (mods.precision == -1)
		res = ft_strdup(res);
	else
		res = ft_substr(res, 0, mods.precision == -2 ? 0 : mods.precision);
	res = ft_fill_padding(res, mods, 's');
	return (res);
}

char*
	ft_parse_char(t_modifiers mods, va_list args)
{
	char *res;

	res = malloc(sizeof(char) * 2);
	res[0] = ((char)va_arg(args, int));
	res[1] = 0;
	res = ft_fill_padding(res, mods, 'c');
	return (res);
}

int
	ft_convert(char conv, t_modifiers mods, t_list **lst, va_list args)
{
	char *res;

	if (conv == 'd' || conv == 'i')
		res = ft_parse_int(mods, args);
	if (conv == 's')
		res = ft_parse_string(mods, args);
	if (conv == 'c')
		res = ft_parse_char(mods, args);
	if (res)
		ft_lstadd_back(lst, ft_lstnew(res));
	return (1);
}
