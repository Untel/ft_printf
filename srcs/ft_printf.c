/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:55 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/29 19:36:21 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Converters: "cspdiuxX%"
 * Modifiers: "-0.*"
 * Converters_bonus: "nfge"
 * Modifiers_bonus: "l ll h hh ’# +"
 */

const char *converters = "cspdiuxX%";
const char *modifiers = "-0.*123456789";

static int
	convert(char conv, t_modifiers mods, t_list **lst, va_list args)
{
	char *res = 0;
	(void)mods;

	if (conv == 'd')
		res = ft_itoa((int)va_arg(args, int));

	if (res)
		ft_lstadd_back(lst, ft_lstnew(res));
	return (1);
}

static int
	extract_flags(const char *str, t_list **lst, va_list args)
{
	int			i;
	t_modifiers mods;

	mods = (t_modifiers){ .padding = 0, .margin = 0, .show_sign = 0 };

	i = 0;
	while (str[i] && ft_strchr(modifiers, str[i]))
		i++;

	// if (ft_strchr(converters, str[i]))
	convert(str[i], mods, lst, args);
	return (i + 1);
}

static int
	split_to_list(const char *str, t_list **lst, va_list args)
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
				i += extract_flags(&str[i], lst, args);
			j = i;
		}
		i++;
	}
	if (!(ptr = ft_substr(str, j, (i - j))))
		return (0);
	if (!(el = ft_lstnew((void *)ptr)))
		return (0);
	ft_lstadd_back(lst, el);
	// ft_lstprint(el, "In split fct");
	return (1);
}

int
	ft_printf(const char *str, ...)
{
	t_list	*el = 0;
	size_t	len;
	va_list	args;
	
	len = 0;
	va_start(args, str);
	split_to_list(str, &el, args);
	ft_lstprint(el, "Main");
	while (el)
	{
		// printf("%s", (char *)el->content);
		len += ft_strlen(el->content);
		ft_putstr_fd((char *)el->content, 1);
		el = el->next;
	}
	va_end(args);
	return (1);
}
