/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:09:40 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/20 19:45:16 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}

char	*ft_lowcase(const char *str)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	while (*str)
		*ptr++ = ft_tolower(*str++);
	*ptr = 0;
	return (ptr - len);
}

char	*ft_capitalize(const char *str)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(str);
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (*str)
		*ptr++ = ft_toupper(*str++);
	while (*str)
		*ptr++ = ft_tolower(*str++);
	*ptr = 0;
	return (ptr - len);
}
