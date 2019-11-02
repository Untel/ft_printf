/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:39:54 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/02 16:58:29 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char
	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

char*
	ft_parse_int(t_modifiers mods, va_list args, char conv)
{
	char *res;

	if (conv != 'u')
	{
		res = ft_itoa((int)va_arg(args, int));
		if (mods.sign && *res != '-')
			res = ft_strjoin(ft_char_to_str(mods.sign), res);
	}
	else
		res = ft_uitoa((unsigned int)va_arg(args, unsigned int));
	res = ft_fill_padding(res, mods, conv);
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

	res = ft_char_to_str((char)va_arg(args, int));
	res = ft_fill_padding(res, mods, 'c');
	return (res);
}

char*
	ft_parse_base(t_modifiers mods, va_list args, char *base, unsigned int bs)
{
	char *res;

	res = ft_nbrbase((int)va_arg(args, int), base, bs);
	res = ft_fill_padding(res, mods, 'x');
	return (res);
}

char*
	ft_parse_address(t_modifiers mods, va_list args)
{
	char			*res;
	int				i;
	int				n;
	uintptr_t		p;

	(void)mods;
	n = 0;
	p = (uintptr_t)va_arg(args, void *);
	i = (((sizeof(p) << 3) - 20) / 4) + 1;
	res = malloc(sizeof(char) * (i * 2 + 1));
	res[n++] = '0';
	res[n++] = 'x';
	while (--i >= 0)
		res[n++] = hex_digit((p >> (i * 4)) & 0xf);
	res[n] = 0;
	res = ft_fill_padding(res, mods, 'p');
	return (res);
}

int
	ft_convert(char conv, t_modifiers mods, t_list **lst, va_list args)
{
	char *res;

	if (conv == 'd' || conv == 'i' || conv == 'u')
		res = ft_parse_int(mods, args, conv);
	if (conv == 's')
		res = ft_parse_string(mods, args);
	if (conv == 'c')
		res = ft_parse_char(mods, args);
	if (conv == 'x')
		res = ft_parse_base(mods, args, "0123456789abcdef", 16);
	if (conv == 'X')
		res = ft_parse_base(mods, args, "0123456789ABCDEF", 16);
	if (conv == 'o')
		res = ft_parse_base(mods, args, "01234567", 8);
	if (conv == 'p')
		res = ft_parse_address(mods, args);
	if (res)
		ft_lstadd_back(lst, ft_lstnew(res));
	return (1);
}
