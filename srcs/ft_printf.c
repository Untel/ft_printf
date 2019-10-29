/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:55 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/29 17:42:54 by adda-sil         ###   ########.fr       */
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

int		extract_flags(char *str)
{
	
}

int		split_to_list(const char *str, t_list **lst)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!(ptr = ft_substr(str, j, (i - j))))
				return (0);
			ft_lstadd_back(lst, ft_lstnew((char *)ptr));
			i = extract_flags(&ptr[i]);
		}
		i++;
	}
	if (!(ptr = ft_substr(str, j, (i - j))))
		return (0);
	ft_lstadd_back(lst, ft_lstnew((char *)ptr));
	convert_data(&ptr[i]);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	t_list	*el;
	size_t	len;

	len = 0;
	split_to_list(str, &el);
	while (el)
	{
		len += ft_strlen(el->content);
		ft_putstr_fd((char *)el->content, 0);
		printf((char *)el->content, 1);
		el = el->next;
	}
	return (1);
}
