/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:39:54 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/09 19:11:57 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t
	ft_lst_size(t_list *lst)
{

	size_t	len;
	t_list *el;

	el = lst;
	len = 0;
	while (el)
	{
		len += el->size;
		el = el->next;
	}
	return (len);
}

int
	ft_convert(char conv, t_modifiers mods, t_list **lst, va_list args)
{
	char	buff[BUFFER_SIZE];
	size_t	len;

	*buff = 0;
	if (conv == 'd' || conv == 'i' || conv == 'u')
		len = ft_parse_int(buff, mods, args, conv);
	else if (conv == 's')
		len = ft_parse_string(buff, mods, args);
	else if (conv == 'c')
		len = ft_parse_char(buff, mods, args);
	else if (conv == 'x' || conv == 'X' || conv == 'o' || conv == 'p')
		len = ft_parse_base(buff, mods, args, conv);
	else if (conv == 'f' || conv == 'e' || conv == 'g')
		len = ft_parse_float(buff, mods, args, conv);
	else if (conv == 'n')
		*(va_arg(args, int *)) = ft_lst_size(*lst);
	if (*buff)
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(buff), len));
	return (1);
}
