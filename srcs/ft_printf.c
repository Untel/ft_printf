/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:55 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/06 18:50:57 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Converters: "cspdiuxX%"
 * Modifiers: "-0.*"
 * Converters_bonus: "nfge"
 * Modifiers_bonus: "l ll h hh ’# +"
 */

static int
	ft_freesome(void *a, void *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	return (0);
}

static void
	ft_clearfn(t_list *lst)
{
	if (lst->content)
	{
		free(lst->content);
	}
}

static int
	ft_split_to_list(const char *str, t_list **lst, va_list args)
{
	int		i;
	int		j;
	char	*ptr;
	t_list	*el;
	size_t	len;

	i = -1;
	j = 0;
	len = ft_strlen(str);	
	while (++i < len)
		if (str[i] == '%')
		{
			if (!(ptr = ft_substr(str, j, (i - j))))
				return (0);
			if (!(el = ft_lstnew((void *)ptr, i - j)))
				return (ft_freesome(ptr, NULL));
			ft_lstadd_back(lst, el);
			if (str[++i])
				i += ft_extract_flags(&str[i], lst, args);
			j = i;
		}
	if (str[j])
	{
		if (!(ptr = ft_substr(str, j, (i - j))))
			return (0);
		if (!(el = ft_lstnew((void *)ptr, i - j)))
			return (ft_freesome(ptr, NULL));
		ft_lstadd_back(lst, el);
	}
	return (1);
}

int
	ft_printf(const char *str, ...)
{
	t_list	*el;
	int		len;
	va_list	args;
	
	va_start(args, str);
	len = 0;
	el = 0;
	ft_split_to_list(str, &el, args);
	while (el)
	{
		len += el->size;
		ft_putstr_fd((char *)el->content, OUTPUT_FD);
		el = el->next;
	}
	ft_lstclear(el, ft_clearfn);
	va_end(args);
	return (len);
}

int
	ft_sprintf(char *buff, const char *str, ...)
{
	t_list	*el;
	t_list	*fel;
	va_list	args;
	char	*ret;
	size_t	i;

	va_start(args, str);
	i = 0;
	el = NULL;
	ft_split_to_list(str, &el, args);
	fel = el;
	// ft_lstprint(el, NULL);
	// if (!(ret = (char *)malloc(sizeof(char) * ((len = ft_get_printed_length(&el)) + 1))))
	// 	return (0);
	while (el)
	{
		// len += ft_strlcat(buff, (const char *)el->content);
		str = (char *)el->content;
		if (!*str)
			break;
		while (el->size-- > 0)
			buff[i++] = *str++;
		el = el->next;
	}
	// ft_lstprint(fel, NULL);
	ft_lstclear(&fel, ft_clearfn);
	buff[i] = 0;
	va_end(args);
	return (i);
}