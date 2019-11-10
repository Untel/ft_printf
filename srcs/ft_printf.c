/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:55 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/10 19:06:31 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Converters: "cspdiuxX%"
 * Modifiers: "-0.*"
 * Converters_bonus: "nfge"
 * Modifiers_bonus: "l ll h hh ’# +"
 */

static void
	ft_clearfn(t_list *lst)
{
	if (lst->content)
		free(lst->content);
}

int
	ft_printf(const char *str, ...)
{
	t_list	*el;
	t_list	*fel;
	int		len;
	va_list	args;
	
	va_start(args, str);
	len = 0;
	el = 0;
	if (!ft_split_to_list(str, &el, args))
		return (-1);
	fel = el;
	while (el)
	{
		len += el->size;
		write(OUTPUT_FD, (char *)el->content, el->size);
		el = el->next;
	}
	ft_lstclear(&fel, ft_clearfn);
	va_end(args);
	return (len);
}

int
	ft_sprintf(char *buff, const char *str, ...)
{
	t_list	*el;
	t_list	*fel;
	va_list	args;
	size_t	i;

	va_start(args, str);
	i = 0;
	el = NULL;
	ft_split_to_list(str, &el, args);
	fel = el;
	while (el)
	{
		str = (char *)el->content;
		if (!*str)
			break;
		while (el->size-- > 0)
			buff[i++] = *str++;
		el = el->next;
	}
	ft_lstclear(&fel, ft_clearfn);
	buff[i] = 0;
	va_end(args);
	return (i);
}