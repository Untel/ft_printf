/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:55 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/30 15:24:52 by adda-sil         ###   ########.fr       */
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
	ft_split_to_list(str, &el, args);
	// ft_lstprint(el, "NODES");
	while (el)
	{
		// printf("%s", (char *)el->content);
		len += ft_strlen(el->content);
		ft_putstr_fd((char *)el->content, 1);
		el = el->next;
	}
	// printf("\nTotal length %d\n", (int)len);
	va_end(args);
	return (1);
}
