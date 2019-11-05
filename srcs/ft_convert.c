/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:39:54 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/05 09:58:58 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_convert(char conv, t_modifiers mods, t_list **lst, va_list args)
{
	char *res;

	if (conv == 'd' || conv == 'i' || conv == 'u')
		res = ft_parse_int(mods, args, conv);
	else if (conv == 's')
		res = ft_parse_string(mods, args);
	else if (conv == 'c')
		res = ft_parse_char(mods, args);
	else if (conv == 'x' || conv == 'X' || conv == 'o' || conv == 'p')
		res = ft_parse_base(mods, args, conv);
	// else if (conv == 'p')
	// 	res = ft_parse_address(mods, args);
	else if (conv == 'f' || conv == 'e' || conv == 'g')
		res = ft_parse_float(mods, args, conv);
	if (res)
		ft_lstadd_back(lst, ft_lstnew(res));
	return (1);
}
