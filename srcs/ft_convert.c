/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:39:54 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/05 18:50:59 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_convert(char conv, t_modifiers mods, t_list **lst, va_list args)
{
	char	buff[BUFFER_SIZE];
	size_t	len;

	if (conv == 'd' || conv == 'i' || conv == 'u')
		len = ft_parse_int(buff, mods, args, conv);
	else if (conv == 's')
		len = ft_parse_string(buff, mods, args);
	else if (conv == 'c')
		len = ft_parse_char(buff, mods, args);
	else if (conv == 'x' || conv == 'X' || conv == 'o' || conv == 'p')
		len = ft_parse_base(buff, mods, args, conv);
	// else if (conv == 'p')
	// 	res = ft_parse_address(mods, args);
	else if (conv == 'f' || conv == 'e' || conv == 'g')
		len = ft_parse_float(buff, mods, args, conv);
	if (*buff)
		ft_lstadd_back(lst, ft_lstnew(buff, len));
	return (1);
}
