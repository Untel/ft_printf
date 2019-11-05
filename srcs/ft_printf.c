/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:55 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/05 16:33:39 by adda-sil         ###   ########.fr       */
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
	ft_split_to_list(const char *str, t_list **lst, va_list args)
{
	int		i;
	int		j;
	char	*ptr;
	t_list	*el;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!(ptr = ft_substr(str, j, (i - j))))
				return (0);
			if (!(el = ft_lstnew((void *)ptr)))
				return (0);
			ft_lstadd_back(lst, el);
			if (str[++i])
				i += ft_extract_flags(&str[i], lst, args);
			j = i;
		}
		i++;
	}
	if (!(ptr = ft_substr(str, j, (i - j))))
		return (0);
	if (!(el = ft_lstnew((void *)ptr)))
		return (0);
	ft_lstadd_back(lst, el);
	// ft_lstprint(lst, "In split fct");
	return (1);
}

int
	ft_get_printed_length(t_list *el)
{
	int len;

	len = 0;
	while (el)
	{
		len += ft_strlen(el->content);
		el = el->next;
	}
	return (len);
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
		len += ft_strlen(el->content);
		ft_putstr_fd((char *)el->content, OUTPUT_FD);
		el = el->next;
	}
	va_end(args);
	return (len);
}

int
	ft_sprintf(char *buff, const char *str, ...)
{
	t_list	*el;\
	va_list	args;
	char	*ret;
	size_t	i;

	va_start(args, str);
	i = 0;
	el = NULL;
	ft_split_to_list(str, &el, args);
	// if (!(ret = (char *)malloc(sizeof(char) * ((len = ft_get_printed_length(&el)) + 1))))
	// 	return (0);
	while (el)
	{
		// len += ft_strlcat(buff, (const char *)el->content);
		str = (char *)el->content;
		if (!*str)
			break;
		while (*str)
			buff[i++] = *str++;
		el = el->next;
	}
	buff[i] = 0;
	va_end(args);
	return (i);
}