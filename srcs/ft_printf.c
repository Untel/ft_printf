/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:55 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/28 20:54:50 by adda-sil         ###   ########.fr       */
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

int		ft_printf(const char *str, ...)
{
	int 	i;
	int		j;
	char	*ptr;
	i = -1;
	j = 0;
	printf("%s", str);
	if (str[0] == 'H')
		printf(" -yo");
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ptr = ft_substr(str, j, (i - j));
			j = i;
		}
	}
	return (1);
}
