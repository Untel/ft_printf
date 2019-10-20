/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:35:06 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/17 17:45:44 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*mal;
	size_t	size;

	size = ft_strlen(src);
	mal = malloc(sizeof(char) * (size + 1));
	while (*src)
		*mal++ = *src++;
	*mal = 0;
	return (mal - size);
}
