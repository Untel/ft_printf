/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:55 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/10 05:33:11 by adda-sil         ###   ########.fr       */
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

int
	ft_addstr(const char *str, t_list **lst, int len)
{
	char *ptr;
	t_list	*el;

	if (!(ptr = ft_substr(str, 0, len)))
		return (0);
	if (!(el = ft_lstnew((void *)ptr, len)))
		return (ft_freesome(ptr, NULL));
	ft_lstadd_back(lst, el);
	return (1);
}

static int
	ft_split_to_list(const char *str, t_list **lst, va_list args)
{
	int		i;
	int		j;
	size_t	len;

	i = -1;
	j = 0;
	len = ft_strlen(str);	
	while (++i < len)
		if (str[i] == '%')
		{
			if (i - j > 0 && !ft_addstr(&str[j], lst, (i - j)))
				return (0);
			if (str[++i] && (j = ft_extract_flags(&str[i], lst, args)) > -1)
				i += j;
			if (j == -1)
				return (0);
			j = i;
		}
	return (str[j] ? ft_addstr(&str[j], lst, (i - j)) : 1);
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
	if (!ft_split_to_list(str, &el, args))
		return (-1);
	while (el)
	{
		len += el->size;
		write(OUTPUT_FD, (char *)el->content, el->size);
		el = el->next;
	}
	ft_lstclear(&el, ft_clearfn);
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