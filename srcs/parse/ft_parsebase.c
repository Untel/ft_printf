/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsebase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:26:07 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/03 21:10:20 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char
	*ft_apply_base_flags(char *str, t_modifiers mods, char conv)
{
	char *res;
	char *tmp;

	res = str;
	if (mods.precision != -1)
		res = ft_fill(res, mods.precision, '0', 0);
	if (conv == 'p' || mods.alt)
		res = ft_strjoin("0x", res);
	res = ft_fill(res, mods.padding, mods.padchar, mods.align_left);
	return (res);
}

char
	*ft_parse_base(t_modifiers mods, va_list args, char conv)
{
	char		*res;
	char		*tmp;
	uintptr_t	val;

	val = va_arg(args, uintptr_t);
	if (conv == 'x')
		res = ft_nbrbase(val, "0123456789abcdef", 16);
	else if (conv == 'X')
		res = ft_nbrbase(val, "0123456789ABCDEF", 16);
	else if (conv == 'o')
		res = ft_nbrbase(val, "01234567", 8);
	else if (conv == 'p')
		res = val ?
			ft_strjoin("10", ft_nbrbase(val, "0123456789abcdef", 16))
			: ft_char_to_str('0');
	tmp = ft_apply_base_flags(res, mods, conv);
	return (tmp);
}

/* to-delete ?*/
char
	ft_val_to_hex(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

char
	*ft_parse_address(t_modifiers mods, uintptr_t p)
{
	char			*res;
	int				i;
	size_t			n;
	int				start;

	n = 0;
	i = (((sizeof(p) << 3) - 4) / 4) + 1;
	res = malloc(sizeof(char) * (i * 10 + 1));
	start = 0;
	while (--i >= 0 && !start)
		if ((res[n] = ft_val_to_hex((p >> (i * 4)) & 0xf)) != '0' && n++)
			start = 1;
	while (--i >= 0)
		res[n++] = ft_val_to_hex((p >> (i * 4)) & 0xf);
	res[n] = 0;
	res = ft_fill_padding(res, mods, 'p');
	return (res);
}
